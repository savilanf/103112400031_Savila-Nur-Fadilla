#ifndef BST2_H
#define BST2_H
#include <iostream>
using namespace std;

typedef int infotype; //alias infotype untuk data integer
typedef struct Node *address; //alias address untuk pointer ke struct Node Node*

struct Node{
    infotype info; //info data yang disimpan (integer)
    address left; //pointer left
    address right; //pointer right
};

//isEmpty & createTree
bool isEmpty(address root); //function untuk mengecek apakah bst kosong atau tidak
void createTree(address &root); //function untuk membuat bst nya (root di set null)

//alokasi & insert
address newNode(infotype x); //function untuk memasukkan data (infotype) ke node
address insertNode(address root, infotype x); //function untuk memasukkan node ke bst

//traversal
void preOrder(address root); //function traversal tree secara preOrder (tengah-kiri-kanan atau root-child kiri-child kanan)
void inOrder(address root); //function traversal tree secara inOrder (kiri-tengah-kanan atau child kiri-root-child kanan)
void postOrder(address root); //function traversal tree secara postOrder (kiri-kanan-tengah atau child kiri-child kanan-root)

//utilities
int countNodes(address root); //function untuk menghitung size atau uk atau jumlah node dalam tree
int treeDepth(address root); //function untuk menghitung depth atau tinggi atau kedalaman atau level tree

//function & prosedur baru
//searching
void searchByData(address root, infotype x); //function untuk melakukan searching data tertentu

//mostleft & mostright
address mostLeft(address root); //function untuk menampilkan node paling kiri
                                //node dengan nilai terkecil dalam bst
address mostRight(address root); //function untuk menampilkan node paling kanan 
                                 //node dengan nilai terbesar dalam bst

//delete
bool deleteNode(address &root, infotype x); //function untuk menghapus node tertentu dalam bst
                                            //menghapus berdasarkan parameter infotype
void deleteTree(address &root); //prosedur untuk menghapus bst (seluruh node dalam bst)

#endif
