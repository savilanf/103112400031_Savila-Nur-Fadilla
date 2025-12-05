#ifndef BST1_H
#define BST1_H
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

#endif
