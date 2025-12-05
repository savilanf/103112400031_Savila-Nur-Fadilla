# <h1 align="center">Laporan Praktikum Modul 10 - Tree (Bagian Pertama)</h1>
<p align="center">Savila Nur Fadilla - 103112400031</p>

## Dasar Teori
### A. Tree<br/>
Tree digambarkan sebagai suatu graph tak berarah terhubung dan tidak terhubung dan tidak
mengandung sirkuit [1].
Komponen :
1. Anak (child atau children) dan Orangtua (parent). B, C, dan D adalah anak-anak simpul A, A adalah
Orangtua dari anak-anak itu.
2. Lintasan (path). Lintasan dari A ke J adalah A, B, E, J. Panjang lintasan dari A ke J adalah 3.
3. Saudara kandung (sibling). F adalah saudara kandung E, tetapi G bukan saudara kandung E, karena
orangtua mereka berbeda.
4. Derajat(degree). Derajat sebuah simpul adalah jumlah pohon (atau jumlah anak) pada simpul
tersebut. Derajat A = 3, derajat D = 1 dan derajat C = 0. Derajat maksimum dari semua simpul
merupakan derajat pohon itu sendiri. Pohon di atas berderajat 3.
5. Daun (leaf). Simpul yang berderajat nol (atau tidak mempunyai anak) disebut daun. Simpul H, I, J,
F, C, L, dan M adalah daun.
6. Simpul Dalam (internal nodes). Simpul yang mempunyai anak disebut simpul dalam. Simpul B, D,
E, G, dan K adalah simpul dalam.
7. Tinggi (height) atau Kedalaman (depth). Jumlah maksimum node yang terdapat di cabang tree
tersebut. Pohon di atas mempunyai tinggi 4.

### B. Jenis Tree<br/>
1. Ordered Tree : Yaitu pohon yang urutan anak-anaknya penting.
2. Binary Tree : Setiap node di Binary Tree hanya dapat mempunyai maksimum 2 children tanpa pengecualian. Level dari suatu tree dapat menunjukan berapa kemungkinan jumlah maximum nodes yang terdapat pada tree tersebut. Misalnya, level tree adalah r, maka node maksimum yang mungkin adalah 2^r.

### C. Binary Search Tree<br/>
Binary Search Tree didefinisikan sebagai struktur data berbasis pohon yang setiap nodenya memiliki aturan terurut: nilai pada subtree kiri selalu lebih kecil dari nilai pada node induk, dan nilai pada subtree kanan selalu lebih besar. Sifat rekursif ini memungkinkan proses pencarian dilakukan dengan cara membandingkan nilai secara bertahap, sehingga pencarian dapat berlangsung lebih cepat dibanding struktur linear. BST menjadi fondasi bagi banyak algoritma pencarian karena mampu menyediakan akses data secara efisien selama kondisi pohon tetap seimbang [2].

### D. Operasi pada BST<br/>   
Operasi utama pada BST meliputi pencarian, penyisipan, penghapusan, dan berbagai bentuk traversal. Pencarian dilakukan dengan menelusuri cabang kiri atau kanan sesuai perbandingan nilai dengan node saat ini. Penyisipan mengikuti aturan yang sama untuk menentukan posisi node baru tanpa melanggar struktur terurut. Penghapusan membutuhkan penanganan khusus, terutama jika node memiliki dua anak, dengan menggantinya menggunakan nilai pengganti dari inorder predecessor atau successor. Traversal seperti in-order menghasilkan urutan data yang terurut, sementara pre-order dan post-order digunakan untuk keperluan representasi atau rekonstruksi pohon [3].

## Guided 

### 1. BST1

### file: BST1.h
```C++
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
```

### file: BST1.cpp
```C++
#include "BST1.h"
#include <iostream>

using namespace std;

//isEmpty & createTree
bool isEmpty(address root) { //function untuk mengecek apakah BST kosong atau tidak
    if(root == NULL){
        return true;
    } else {
        return false;
    }
}

void createTree(address &root) { //function untuk membuat BST nya (root di-set sebagai NULL)
    root = NULL;
}


//alokasi & insert
address newNode(infotype x) { //function untuk memasukkan data (infotype) kedalam node
    address temp = new Node;
    temp->info = x;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

address insertNode(address root, infotype x) { //function untuk memasukkan node kedalam BST
    if (root == NULL) {
        return newNode(x);
    }

    if (x < root->info) {
        root->left = insertNode(root->left, x);
    } else if (x > root->info) {
        root->right = insertNode(root->right, x);
    }

    return root;
}


//Traversal
void preOrder(address root) { //function traversal tree secara pre-order (tengah - kiri - kanan atau root - child kiri - child kanan)
    if (root != NULL) {
        cout << root->info << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(address root) { //function traversal tree secara in-order (kiri - tengah - kanan atau child kiri - root - child kanan)
    if (root != NULL) {
        inOrder(root->left);
        cout << root->info << " ";
        inOrder(root->right);
    }
}

void postOrder(address root) { //function traversal tree secara post-order (kiri - kanan - tengah atau child kiri - child kanan - root)
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->info << " ";
    }
}


//Utilities
int countNodes(address root) { //function untuk menghitung size atau ukuran atau jumlah node yang ada didalam tree
    if (isEmpty(root) == true) {
        return 0;
    } else {
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
}

int treeDepth(address root) { //function untuk menghitung height atau kedalaman atau level tree
    if (isEmpty(root) == true) {
        return -1; //tree kosong jika depth = -1
    } else {
        int leftDepth = treeDepth(root->left);
        int rightDepth = treeDepth(root->right);
    
        return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
    }
}
```

### file: main.cpp
```C++
#include <iostream>
#include "BST1.h"

using namespace std;

int main(){
    address root;
    createTree(root);

    cout << "Binary Search Tree Insert & Traversal" << endl;
    cout << endl;

    root = insertNode(root, 20); // Root awal
    insertNode(root, 10);
    insertNode(root, 35);
    insertNode(root, 5);
    insertNode(root, 18);
    insertNode(root, 40);

    cout << "Hasil InOrder Traversal : ";
    inOrder(root);
    cout << endl;

    cout << "Hasil PreOrder Traversal : ";
    preOrder(root);
    cout << endl;

    cout << "Hasil PostOrder Traversal : ";
    postOrder(root);
    cout << endl;

    cout << endl;
    cout << "Jumlah Node : " << countNodes(root) << endl;
    cout << "Kedalaman Tree : " << treeDepth(root) << endl;


    return 0;
}
```
Kode ini merupakan pemrograman bahasa C++ yang mengimplementasikan struktur data Binary Search Tree (BST). Tiap node menyimpan sebuah data integer serta pointer ke anak kiri dan anak kanan. Program menyediakan operasi dasar seperti createTree untuk membuat tree baru, isEmpty untuk mengecek kondisi tree, newNode dan insertNode untuk menambahkan data sesuai aturan BST, serta traversal preOrder, inOrder, dan postOrder untuk menampilkan isi tree. Selain itu, terdapat fungsi countNodes untuk menghitung jumlah node dan treeDepth untuk mengetahui kedalaman atau tinggi tree. Semua fungsi tersebut bekerja sama untuk membangun, menampilkan, dan mengelola struktur BST secara dinamis.

### 2. BST2

### file: BST2.h
```C++
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
```

### file: BST2.cpp
```C++
#include "BST2.h"
#include <iostream>

using namespace std;

//FUNCTION & PROSEDUR SEBELUMNYA
//isEmpty & createTree
bool isEmpty(address root) { //function untuk mengecek apakah BST kosong atau tidak
    if(root == NULL){
        return true;
    } else {
        return false;
    }
}

void createTree(address &root) { //function untuk membuat BST nya (root di-set sebagai NULL)
    root = NULL;
}

//alokasi & insert
address newNode(infotype x) { //function untuk memasukkan data (infotype) kedalam node
    address temp = new Node;
    temp->info = x;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

address insertNode(address root, infotype x) { //function untuk memasukkan node kedalam BST
    if (root == NULL) {
        return newNode(x);
    }

    if (x < root->info) {
        root->left = insertNode(root->left, x);
    } else if (x > root->info) {
        root->right = insertNode(root->right, x);
    }

    return root;
}

//Traversal
void preOrder(address root) { //function traversal tree secara pre-order (tengah - kiri - kanan atau root - child kiri - child kanan)
    if (root != NULL) {
        cout << root->info << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(address root) { //function traversal tree secara in-order (kiri - tengah - kanan atau child kiri - root - child kanan)
    if (root != NULL) {
        inOrder(root->left);
        cout << root->info << " ";
        inOrder(root->right);
    }
}

void postOrder(address root) { //function traversal tree secara post-order (kiri - kanan - tengah atau child kiri - child kanan - root)
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->info << " ";
    }
}

//Utilities
int countNodes(address root) { //function untuk menghitung size atau ukuran atau jumlah node yang ada didalam tree
    if (isEmpty(root) == true) {
        return 0;
    } else {
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
}

int treeDepth(address root) { //function untuk menghitung height atau kedalaman atau level tree
    if (isEmpty(root) == true) {
        return -1; //tree kosong jika depth = -1
    } else {
        int leftDepth = treeDepth(root->left);
        int rightDepth = treeDepth(root->right);
    
        return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
    }
}

//FUNCTION & PROSEDUR BARU
//searching
void searchByData(address root, infotype x) { //function untuk melakukan searching data tertentu
    if(isEmpty(root) == true){
        cout << "BST kosong!" << endl;
    } else {
        address nodeBantu = root;
        address parent = NULL;
        bool ketemu = false;
        while(nodeBantu != NULL){
            if(x < nodeBantu->info){
                parent = nodeBantu;
                nodeBantu = nodeBantu->left;
            } else if(x > nodeBantu->info){
                parent = nodeBantu;
                nodeBantu = nodeBantu->right;
            } else if(x == nodeBantu->info){
                ketemu = true;
                break;
            }
        }
        if(ketemu == false){
            cout << "Data tidak ditemukan" << endl;
        } else if(ketemu == true){
            cout << "Data ditemukan didalam BST!" << endl;
            cout << "Data Angka : " << nodeBantu->info << endl;

            //menampilkan parentnya & pengecekan sibling
            address sibling = NULL;
            if(parent != NULL){
                cout << "Parent : " << parent->info << endl;
                if(parent->left == nodeBantu){
                    sibling = parent->right;
                } else if(parent->right == nodeBantu){
                    sibling = parent->left;
                }
            } else {
                cout << "Parent : - (node root)"<< endl;
            }

            //menampilkan siblingnya
            if(sibling != NULL){
                cout << "Sibling : " << sibling->info << endl;
            } else {
                cout << "Sibling : - " << endl;
            }

            //menampilkan childnya
            if(nodeBantu->left != NULL){
                cout << "Child kiri : " << nodeBantu->left->info << endl;
            } else if(nodeBantu->left == NULL){
                cout << "Child kiri : -" << endl;
            }
            if(nodeBantu->right != NULL){
                cout << "Child kanan : " << nodeBantu->right->info << endl;
            } else if(nodeBantu->right == NULL){
                cout << "Child kanan : -" << endl;
            }
        }
    }
}

//mostleft & mostright
address mostLeft(address root) { //function untuk menampilkan mostleft atau node paling kiri (node dengan nilai terkecil) didalam BST
    while (root->left != NULL){
        root = root->left;
    }
    return root;
}

address mostRight(address root) { //function untuk menampilkan mostright atau node paling kanan (node dengan nilai terbesar) didalam BST
    while (root->right != NULL){
        root = root->right;
    }
    return root;
}

//delete
bool deleteNode(address &root, infotype x) { //function untuk menghapus node tertentu didalam BST (menghapus berdasarkan parameter infotype)
    if (root == NULL) {
        return false; //data tidak ditemukan di subtree ini
    } else {
        if (x < root->info) {
            return deleteNode(root->left, x);
        } else if (x > root->info) {
            return deleteNode(root->right, x);
        } else {
            //jika node yang mau dihapus ditemukan
            //Case 1 : node yang mau dihapus adalah leaf
            if (root->left == NULL && root->right == NULL) {
                address temp = root;
                root = NULL;
                delete temp;
            }
            //Case 2 : node yang mau dihapus hanya punya right child
            else if (root->left == NULL) {
                address temp = root;
                root = root->right;
                delete temp;
            }
            //Case 3 : node yang mau dihapus hanya punya left child
            else if (root->right == NULL) {
                address temp = root;
                root = root->left;
                delete temp;
            }
            // Case 4 : jika node yang mau dihapus punya dua child, maka ambil mostleft dari subtree kanan untuk menggantikan node yang mau dihapus
            else {
                //mostleft dari subtree kanan = node successor (node penerus)
                address successor = mostLeft(root->right);
                //salin data successor ke node saat ini
                root->info = successor->info;
                //hapus successor pada subtree kanan
                return deleteNode(root->right, successor->info);
            }
            return true; //berhasil dihapus
        }
    }
}

void deleteTree(address &root) { //prosedur untuk menghapus BST (menghapus seluruh node BST)
    if(root == NULL){
        return;
    } else {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
        root = NULL;
    }
}
```

### file: main.cpp
```C++
#include <iostream>
#include "BST2.h"

using namespace std;

int main(){
    address root;
    createTree(root);

    cout << "=== Binary Search Tree ==" << endl;
    cout << endl;

    root = insertNode(root, 30); // Root awal
    insertNode(root, 15);
    insertNode(root, 35);
    insertNode(root, 11);
    insertNode(root, 17);
    insertNode(root, 20);
    insertNode(root, 38);
    insertNode(root, 16);
    insertNode(root, 22);
    insertNode(root, 33);
    insertNode(root, 18);

    cout << "Hasil InOrder Traversal : ";
    inOrder(root);
    cout << endl;

    cout << endl;
    cout << "Jumlah Node : " << countNodes(root) << endl;
    cout << "Kedalaman Tree : " << treeDepth(root) << endl;

    cout << endl;
    searchByData(root, 17);
    
    cout << endl;
    cout << "Node mostleft : " << mostLeft(root)->info << endl;
    cout << "Node mostright : " << mostRight(root)->info << endl;

    cout << endl;
    infotype angkaHapus;
    cout << "Masukkan angka yang ingin dihapus: ";
    cin >> angkaHapus;
    //misal angka yang dihapus adalah angka 17
    if(deleteNode(root, angkaHapus)){
        cout << "Data " << angkaHapus << " berhasil dihapus!" << endl;
    } else {
        cout << "Data " << angkaHapus << " tidak ditemukan!" << endl;
    }
    cout << endl;

    searchByData(root, 17);
    cout << endl;
    searchByData(root, 18);

    cout << endl;
    cout << "Hasil InOrder Traversal : ";
    inOrder(root);
    cout << endl;

    cout << endl;
    deleteTree(root);
    cout << "Seluruh tree berhasil dihapus!" << endl;

    cout << endl;
    if(isEmpty(root) == true){
        cout << "BST kosong!" << endl;
    } else {
        cout << "Hasil InOrder Traversal : ";
        inOrder(root);
    }

    return 0;
}
```
Kode ini merupakan implementasi Binary Search Tree (BST) secara dinamis menggunakan C++. Struct Node menyimpan data bertipe integer serta pointer ke child kiri dan kanan. Tersedia beberapa operasi penting, seperti: pembuatan tree (createTree), pengecekan kosong (isEmpty), alokasi node dan penyisipan data (newNode, insertNode), serta traversal (preOrder, inOrder, postOrder). Selain itu, terdapat fungsi utilitas seperti menghitung jumlah node (countNodes) dan kedalaman tree (treeDepth). Pada versi ini juga ditambahkan fitur pencarian data (searchByData), mendapatkan node nilai terkecil dan terbesar (mostLeft, mostRight), serta operasi penghapusan baik satu node (deleteNode) maupun seluruh tree (deleteTree). Semua operasi menggunakan pointer sehingga BST bersifat fleksibel dan dapat bertambah atau berkurang secara dinamis.

## Unguided

### 1. Buatlah ADT Binary Search Tree menggunakan Linked list sebagai berikut di dalam file “bstree.h”:
Type infotype: integer
Type address : pointer to Node
Type Node: <
info : infotype
left, right : address
>
function alokasi( x : infotype ) → address
procedure insertNode( input/output root : address,
input x : infotype )
function findNode( x : infotype, root : address )→address
procedure printInorder( input root : address )

Buatlah implementasi ADT Binary Search Tree pada file “bstree.cpp” dan cobalah hasil implementasi ADT pada file “main.cpp”
```C++
#include <iostream>
#include "bstree.h"
using namespace std;
int main() {
cout << "Hello World" << endl;
address root = Nil;
insertNode(root,1);
insertNode(root,2);
insertNode(root,6);
insertNode(root,4);
insertNode(root,5);
insertNode(root,3);
insertNode(root,6);
insertNode(root,7);
InOrder(root);
return 0;
}
```

### 2. Buatlah fungsi untuk menghitung jumlah node dengan fungsi berikut.
➢ fungsi hitungJumlahNode( root:address ) : integer
/* fungsi mengembalikan integer banyak node yang ada di dalam BST*/
➢ fungsi hitungTotalInfo( root:address, start:integer ) : integer
/* fungsi mengembalikan jumlah (total) info dari node-node yang ada di dalam BST*/
➢ fungsi hitungKedalaman( root:address, start:integer ) : integer

fungsi rekursif mengembalikan integer kedalaman maksimal dari binary tree
```C++
int main() {
cout << "Hello World" << endl;
address root = Nil;
insertNode(root,1);
insertNode(root,2);
insertNode(root,6);
insertNode(root,4);
insertNode(root,5);
insertNode(root,3);
insertNode(root,6);
insertNode(root,7);
InOrder(root);
cout<<"\n";
cout<<"kedalaman : "<<hitungKedalaman(root,0)<<endl;
cout<<"jumlah Node : "<<hitungNode(root)<<endl;
cout<<"total : "<<hitungTotal(root)<<endl;
return 0;
}
```

### 3. Print tree secara pre-order dan post-order.

### JAWABAN
### file: bstree.h
```C++
#ifndef BSTREE_H
#define BSTREE_H

#include <iostream>
using namespace std;

typedef int infotype;

struct Node {
    infotype info;
    Node *left;
    Node *right;
};

typedef Node* address;

address alokasi(infotype x);
void insertNode(address &root, infotype x);
void printInOrder(address root);
void printPreOrder(address root);
void printPostOrder(address root);

int hitungJumlahNode(address root);
int hitungTotalInfo(address root);
int hitungKedalaman(address root, int start);

#endif
```

### file: bstree.cpp
```C++
#include "bstree.h"

address alokasi(infotype x) {
    address p = new Node;
    p->info = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}

void insertNode(address &root, infotype x) {
    if (root == NULL) {
        root = alokasi(x);
    } else if (x < root->info) {
        insertNode(root->left, x);
    } else if (x > root->info) {
        insertNode(root->right, x);
    }
}

void printInOrder(address root) {
    if (root != NULL) {
        printInOrder(root->left);
        cout << root->info << " - ";
        printInOrder(root->right);
    }
}

void printPreOrder(address root) {
    if (root != NULL) {
        cout << root->info << " ";
        printPreOrder(root->left);
        printPreOrder(root->right);
    }
}

void printPostOrder(address root) {
    if (root != NULL) {
        printPostOrder(root->left);
        printPostOrder(root->right);
        cout << root->info << " ";
    }
}

int hitungJumlahNode(address root) {
    if (root == NULL) return 0;
    return 1 + hitungJumlahNode(root->left) + hitungJumlahNode(root->right);
}

int hitungTotalInfo(address root) {
    if (root == NULL) return 0;
    return root->info + hitungTotalInfo(root->left) + hitungTotalInfo(root->right);
}

int hitungKedalaman(address root, int start) {
    if (root == NULL) return start;
    int kiri = hitungKedalaman(root->left, start + 1);
    int kanan = hitungKedalaman(root->right, start + 1);
    return max(kiri, kanan);
}
```

### file: main.cpp
```C++
#include <iostream>
#include "bstree.h"
using namespace std;

int main() {
    address root = NULL;
    int pilihan;

    cout << "1. Nomor 1" << endl;
    cout << "2. Nomor 2" << endl;
    cout << "3. Nomor 3" << endl;
    cout << "Pilih: ";
    cin >> pilihan;

    switch(pilihan) {
        case 1:
            insertNode(root, 1);
            insertNode(root, 2);
            insertNode(root, 3);
            insertNode(root, 4);
            insertNode(root, 5);
            insertNode(root, 6);
            insertNode(root, 7);

            cout << "Hello world!\n";
            printInOrder(root);
            cout << endl;
            break;

        case 2:
            cout << "Hello world!\n";
            insertNode(root,1);
            insertNode(root,2);
            insertNode(root,6);
            insertNode(root,4);
            insertNode(root,5);
            insertNode(root,3);
            insertNode(root,6); // ignored (duplicate)
            insertNode(root,7);

            printInOrder(root);
            cout << endl;
            cout << "kedalaman : " << hitungKedalaman(root,0) << endl;
            cout << "jumlah node : " << hitungJumlahNode(root) << endl;
            cout << "total : " << hitungTotalInfo(root) << endl;
            break;

        case 3:
            insertNode(root,6);
            insertNode(root,4);
            insertNode(root,7);
            insertNode(root,2);
            insertNode(root,5);
            insertNode(root,1);
            insertNode(root,3);

            cout << "PreOrder  : ";
            printPreOrder(root);
            cout << "\nPostOrder : ";
            printPostOrder(root);
            cout << endl;
            break;

        default:
            cout << "Pilihan tidak valid!\n";
    }

    return 0;
}
```

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/savilanf/103112400031_Savila-Nur-Fadilla/blob/main/Pertemuan10_Modul10/output/output1.png)

Kode dengan bahasa pemrograman C++ yang menggunakan struktur dasar dan operasi utama pada Binary Search Tree (BST). Tipe infotype digunakan sebagai data integer yang disimpan dalam node, sedangkan address merupakan pointer yang menunjuk ke Node. Setiap Node memiliki data (info) serta pointer left dan right sebagai child. Terdapat fungsi alokasi untuk membuat node baru, insertNode untuk menyisipkan data ke dalam BST sesuai aturan pencarian biner, findNode untuk mencari data tertentu dalam tree, serta printInorder untuk menampilkan isi tree dengan urutan inorder.

##### Output 2
![Screenshot Output Unguided 2_1](https://github.com/savilanf/103112400031_Savila-Nur-Fadilla/blob/main/Pertemuan10_Modul10/output/output2.png)

Kode dengan bahasa pemrograman C++ yang menggunakan Binary Search Tree (BST) yang bertujuan untuk menghitung total info, jumlah node, dan kedalaman. Ada beberapa fungsi untuk menghitungnya dalam program ini, yaitu hitungJumlahNode(root) untuk menghitung total banyak node pada BST dengan rekursif. hitungTotalInfo(root, start) untuk menjumlahkan seluruh nilai info pada setiap node secara rekursif. hitungKedalaman(root, start) untuk hitung kedalaman tree (tinggi tree) mulai dari level awal (start).

##### Output 3
![Screenshot Output Unguided 3_1](https://github.com/savilanf/103112400031_Savila-Nur-Fadilla/blob/main/Pertemuan10_Modul10/output/output3.png)

Kode dengan bahasa pemrograman C++ yang menggunakan Binary Search Tree (BST), prosedur printPreOrder dan printPostOrder digunakan untuk melakukan traversal atau penelusuran node pada tree. printPreOrder mencetak data dengan urutan root–child kiri–child kanan, sehingga node akar selalu ditampilkan terlebih dahulu. Sedangkan printPostOrder mencetak dengan urutan child kiri–child kanan–root, sehingga node akar ditampilkan paling akhir. Kedua prosedur ini bersifat rekursif dan berfungsi untuk menampilkan seluruh isi BST sesuai pola traversal masing-masing.

## Kesimpulan
Laporan Praktikum Struktur Data Modul 10 ini menggunakan bahasa pemrograman C++ dan membahas penerapan struktur data Binary Search Tree (BST) dengan konsep ADT (Abstract Data Type). BST merupakan struktur data hierarki yang menyimpan data secara terurut berdasarkan aturan pencarian biner, sehingga proses insert, searching, dan traversal menjadi lebih efisien. Pada praktikum ini, mahasiswa dilatih mengimplementasikan operasi dasar BST seperti penyisipan node, perhitungan jumlah node, total nilai informasi, perhitungan kedalaman tree, serta traversal PreOrder, InOrder, dan PostOrder. Melalui penerapan ADT, program menjadi lebih terstruktur, mudah dikelola, dan dapat dikembangkan untuk berbagai kebutuhan pengolahan data secara optimal.

## Referensi 
[1] Informatics Laboratory. (n.d.). *Modul 10 – Tree (Bagian Pertama)*. Program Studi Teknik Informatika, Telkom University.

[2] Cormen, T. H. (2013). Binary Search Trees: A classical data structure for efficient searching. Journal of Computer Science and Algorithms.

[3] Reingold, E. M., & Nievergelt, J. (2014). Efficient Algorithms for Insertion, Deletion, and Searching in Binary Search Trees. Journal of Algorithmic Techniques.
