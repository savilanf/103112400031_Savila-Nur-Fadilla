# <h1 align="center">Laporan Praktikum Modul 4 - Singly Linked List (Bagian Pertama)</h1>
<p align="center">Savila Nur Fadilla - 103112400031</p>

## Dasar Teori
### A. Linked List dengan Pointer<br/>
Setiap model ADT Linked list di atas memiliki karakteristik tertentu dan dalam penggunaannya disesuaikan dengan kebutuhan [1].
Secara umum operasi-operasi ADT pada Linked list, yaitu :
1. Penciptaan dan inisialisasi list (Create List)
2. Penyisipan elemen list (Insert)
3. Penghapusan elemen list (Delete)
4. Penelusuran elemen list dan menampilkannya (View)
5. Pencarian elemen list (Searching)
6. Pengubahan isi elemen list (Update)

### B. Singly Linked List<br/>
Istilah-stlah dalam SinglyLinked list: 
1. first/head: pointer pada list yang menunjuk alamat elemen pertama list.
2. next: pointer pada elemen yang berfungsi sebagai successor (penunjuk) alamat elemen di
depannya.om University lab 
3. NULL/Nil: artinya tidak memiliki nilai, atau tidak mengacu ke mana pun, atau kosong.
4. Node/simpul/elemen: merupakan tempat penyimpanan data pada suatu memori tertentu.

### C. Create List<br/>  
Proses pembuatan list dilakukan dengan *menginisialisasi pointer head ke nilai NULL* sebagai tanda bahwa list masih kosong. Proses ini penting untuk mencegah error saat dilakukan operasi lain seperti insert atau delete. Alokasi memori dilakukan secara dinamis menggunakan pointer [2].

*Contoh sintaks:*
```C++
struct Node {
    int data;
    Node* next;
};

void createList(Node*& head) {
    head = NULL;  // list kosong
}
```

### D. Insert List<br/>   
Operasi insert bisa dilakukan di tiga posisi, yaitu di awal, di tengah (setelah node tertentu), dan di akhir. Operasi ini menambahkan node baru dengan cara mengatur ulang pointer agar node baru terhubung ke node lain. Waktu eksekusi untuk insert di awal lebih cepat karena tidak perlu traversal [3].

*Contoh sintaks:*
```C++
void insertFirst(Node*& head, int x) {
    Node* newNode = new Node;
    newNode->data = x;
    newNode->next = head;
    head = newNode;
}

void insertLast(Node*& head, int x) {
    Node* newNode = new Node;
    newNode->data = x;
    newNode->next = NULL;
    if (head == NULL)
        head = newNode;
    else {
        Node* p = head;
        while (p->next != NULL)
            p = p->next;
        p->next = newNode;
    }
}
```

### E. Delete List<br/>   
Operasi delete dilakukan dengan cara menghapus node dari list dan memastikan pointer tidak tertinggal (dangling pointer). Operasi yang umum dilakukan yaitu deleteFirst() dan deleteLast(). Selain itu, penting juga untuk membebaskan memori agar tidak terjadi memory leak [4].

*Contoh sintaks:*
```C++
void deleteFirst(Node*& head) {
    if (head != NULL) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

void deleteLast(Node*& head) {
    if (head == NULL) return;
    if (head->next == NULL) {
        delete head;
        head = NULL;
    } else {
        Node* p = head;
        while (p->next->next != NULL)
            p = p->next;
        delete p->next;
        p->next = NULL;
    }
}
```

### F. View List<br/>   
Proses view atau traversal dilakukan dengan menelusuri setiap node dari head hingga node terakhir (NULL). Tujuan dari operasi ini adalah untuk menampilkan seluruh isi list serta memeriksa apakah data sudah tersimpan dengan benar [5].

*Contoh sintaks:*
```C++
void viewList(Node* head) {
    Node* p = head;
    while (p != NULL) {
        cout << p->data << " -> ";
        p = p->next;
    }
    cout << "NULL" << endl;
}
```

### G. Searching List<br/>   
Proses pencarian pada linked list dilakukan secara *linear search*, yaitu dengan menelusuri setiap node dari awal hingga ditemukan data yang dicari atau mencapai akhir list. Metode ini memiliki kompleksitas waktu O(n), artinya semakin banyak data, semakin lama proses pencarian [6].

*Contoh sintaks:*
```C++
Node* search(Node* head, int x) {
    Node* p = head;
    while (p != NULL) {
        if (p->data == x)
            return p;
        p = p->next;
    }
    return NULL;
}
```

## Guided 

### 1. guided1

### file: list.h
```C++
//Header guard digunakan untuk mencegah file header yang sama 
//di-include lebih dari sekali dalam satu program.
#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include<iostream>
using namespace std;

//deklarasi isi data struct mahasiswa
struct mahasiswa{
    string nama; 
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa; //Memberikan nama alias dataMahasiswa untuk struct mahasiswa.

typedef struct node *address; //Mendefinisikan alias address sebagai pointer ke struct node

struct node{ // node untuk isi dari linked listnya, isi setiap node adalah data & pointer next
    dataMahasiswa isidata;
    address next;
};

struct linkedlist{ //ini linked list nya
    address first;
};

//semua function & prosedur yang akan dipakai
bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);

#endif
```

### file: list.cpp
```C++
#include "list.h"
#include <iostream>
using namespace std;

//I.S = Initial State / kondisi awal
//F.S = Final State / kondisi akhir

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedlist &List) {
    /* I.S. sembarang
       F.S. terbentuk list kosong */
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string nim, int umur) { 
    /* I.S. sembarang
       F.S. mengembalikan alamat node baru dengan isidata = sesuai parameter dan next = Nil */
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim; 
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    /* I.S. P terdefinisi
       F.S. memori yang digunakan node dikembalikan ke sistem */
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru) {
    /* I.S. sembarang, P sudah dialokasikan
       F.S. menempatkan elemen list (node) pada awal list */
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    /* I.S. sembarang, nodeBaru dan Prev alamat salah satu elemen list (node)
       F.S. menempatkan elemen (node) sesudah elemen node Prev */
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
    /* I.S. sembarang, nodeBaru sudah dialokasikan
       F.S. menempatkan elemen nodeBaru pada akhir list */
    if (isEmpty(List) == true) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedlist List) {
    /* I.S. list mungkin kosong
       F.S. jika list tidak kosong menampilkan semua info yang ada pada list */
    if (isEmpty(List) == true) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim 
            << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}
```

### file: main.cpp
```C++
#include "list.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);

    return 0;
}
```
Kode dengan bahasa pemrograman C++ untuk mengelola data mahasiswa menggunakan singly linked list. Data berisi nama, NIM, dan umur disimpan dalam node yang saling terhubung. Program membuat list kosong, menambahkan beberapa node dengan fungsi insertFirst, insertAfter, dan insertLast, lalu menampilkan seluruh data mahasiswa secara berurutan.

### 2. guided2

### file: list.h
```C++
//Header guard digunakan untuk mencegah file header yang sama
//di-include lebih dari sekali dalam satu program.
#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include <iostream>
using namespace std;

//deklarasi isi data struct mahasiswa
struct mahasiswa{
    string nama; 
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa; //Memberikan nama alias dataMahasiswa untuk struct mahasiswa.

typedef struct node *address; //Mendefinisikan alias address sebagai pointer ke struct node

struct node{ // node untuk isi dari linked listnya, isi setiap node adalah data & pointer next
    dataMahasiswa isidata;
    address next;
};

struct linkedlist{ //ini linked list nya
    address first;
};

//semua function & prosedur yang akan dipakai
bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);

void delFirst(linkedlist &List);
void delLast(linkedlist &List);
void delAfter(linkedlist &List, address nodeHapus, address nodePrev);
int nbList(linkedlist List);
void deleteList(linkedlist &List);

#endif
```

### file: list.cpp
```C++
#include "list.h"
#include <iostream>
using namespace std;

//I.S = Initial State / kondisi awal
//F.S = Final State / kondisi akhir

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedlist &List) {

    List.first = Nil;
}

//pembuatan node baru
address alokasi(string nama, string nim, int umur) { 

    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim; 
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node
void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru) {

    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {

    if (Prev != Nil) { //Previous (sebelumnya) tidak boleh NULL
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {

    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

//prosedur-prosedur untuk delete / menghapus node yang ada didalam list
void delFirst(linkedlist &List){

    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedlist &List){

    address nodeHapus, nodePrev;
    if(isEmpty(List) == false){
        nodeHapus = List.first;
        if(nodeHapus->next == Nil){
            List.first->next = Nil;
            dealokasi(nodeHapus);
        } else { 
            while(nodeHapus->next != Nil){
                nodePrev = nodeHapus; 
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil; 
            dealokasi(nodeHapus);
        }
    } else {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedlist &List, address nodeHapus, address nodePrev){

    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else { //jika list tidak kosong
        if (nodePrev != Nil && nodePrev->next != Nil) { 
            nodeHapus = nodePrev->next;       
            nodePrev->next = nodeHapus->next;  
            nodeHapus->next = Nil;         
            dealokasi(nodeHapus);
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedlist List) {

    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

//function untuk menampilkan jumlah node didalam list
int nbList(linkedlist List) {

    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next; 
    }
    return count;
}

//prosedur untuk menghapus list (menghapus semua node didalam list)
void deleteList(linkedlist &List){

    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while(nodeBantu != Nil){
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus); 
    }
    List.first = Nil; 
    cout << "List sudah terhapus!" << endl;
}
```

### file: main.cpp
```C++
#include "list.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "ISI LIST SETELAH DILAKUKAN INSERT" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    delFirst(List);
    delLast(List);
    delAfter(List, nodeD, nodeC);

    cout << "ISI LIST SETELAH DILAKUKAN DELETE" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    deleteList(List);
    cout << "ISI LIST SETELAH DILAKUKAN HAPUS LIST" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    return 0;
}
```
Kode dengan bahasa pemrograman C++ untuk mengelola data mahasiswa menggunakan singly linked list. Data mahasiswa berupa nama, NIM, dan umur disimpan dalam node yang saling terhubung. Program membuat list kosong, menambahkan beberapa node, menampilkan isi list, menghitung jumlah data, menghapus node tertentu, dan menghapus seluruh isi list. Fungsi dan prosedur yang digunakan antara lain createList, insertFirst, insertAfter, insertLast, printList, nbList, delFirst, delAfter, delLast, dan deleteList.

## Unguided 

### 1. Buatlah ADT Singly Linked list sebagai berikut di dalam file `Singlylist.h`
```pascal
Type infotype : int
Type address : pointer to ElmList

Type ElmList <
    info : infotype
    next : address
>

Type List : < First : address >

procedure CreateList( input/output L : List )
function alokasi( x : infotype ) -> address
procedure dealokasi( input/output P : address )
procedure printInfo( input L : List )
procedure insertFirst( input/output L : List, input P : address )
```

### Kemudian buatlah implementasi dari procedure-procedure yang digunakan didalam file Singlylist.cpp
### Kemudian buat program utama didalam file main.cpp dengan implementasi sebagai berikut :
```C++
int main() {
    List L;
    address P1, P2, P3, P4, P5 = Nil;
    createList(L);

    P1 = alokasi(2);
    insertFirst(L, P1);

    P2 = alokasi(0);
    insertFirst(L, P2);

    P3 = alokasi(8);
    insertFirst(L, P3);

    P4 = alokasi(12);
    insertFirst(L, P4);

    P5 = alokasi(9);
    insertFirst(L, P5);

    printInfo(L);
    return 0;
}
```
### Sehingga linked list yang dibuat akan seperti ini:
First
↓
[9] → [12] → [8] → [0] → [2]

### Output yang diharapkan:
9 12 8 0 2

Process returned 0 (0x0)   execution time : 0.019 s
Press any key to continue.

### file: Singlylist.h
```C++
#ifndef SINGLYLIST_H
#define SINGLYLIST_H
#define Nil NULL

#include <iostream>
using namespace std;

typedef int infotype;
typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address next;
};

struct List {
    address First;
};

void CreateList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertFirst(List &L, address P);

#endif

```

### file: Singlylist.cpp
```C++
#include "Singlylist.h"

void CreateList(List &L) {
    L.First = Nil;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = Nil;
}

void printInfo(List L) {
    address P = L.First;
    while (P != Nil) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}

void insertFirst(List &L, address P) {
    P->next = L.First;
    L.First = P;
}

```

### file: main.cpp
```C++
#include "Singlylist.h"

int main() {
    List L;
    address P1, P2, P3, P4, P5;

    CreateList(L);

    P1 = alokasi(2);
    insertFirst(L, P1);

    P2 = alokasi(0);
    insertFirst(L, P2);

    P3 = alokasi(8);
    insertFirst(L, P3);

    P4 = alokasi(12);
    insertFirst(L, P4);

    P5 = alokasi(9);
    insertFirst(L, P5);

    printInfo(L);

    return 0;
}
```
### Output Unguided 1 :

##### Output
![Screenshot Output Unguided 1_1](https://github.com/savilanf/103112400031_Savila-Nur-Fadilla/blob/main/Pertemuan4_Modul4/output/output-unguided1.png)

kekurangan output: belum ada waktu eksekusinya karena masih bingung

Kode dengan bahasa pemrograman C++ untuk membuat dan menampilkan isi Singly Linked List. File Singlylist.h berisi struktur node dan list serta prosedur seperti CreateList, alokasi, insertFirst, dealokasi, dan printInfo. Program utama membuat list, menambahkan beberapa elemen (9, 12, 8, 0, 2), lalu menampilkan hasilnya di layar dengan output 9 12 8 0 2.

### 2. Dari soal Latihan pertama, Lakukan penghapusan node 9 menggunakan deleteFirst(), node 2 menggunakan deleteLast(), dan node 8 menggunakan deleteAfter(). Kemudian tampilkan jumlah node yang tersimpan menggunakan nbList() dan lakukan penghapusan seluruh node menggunakan deleteList().

### file: Singlylist.h
```C++
#ifndef SINGLYLIST_H
#define SINGLYLIST_H
#define Nil NULL

#include <iostream>
using namespace std;

typedef int infotype;
typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address next;
};

struct List {
    address first;
};

void createList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void printInfo(List L);
void insertFirst(List &L, address P);
void delFirst(List &L);
void delLast(List &L);
void delAfter(address Prec, List &L);
int nbList(List L);
void deleteList(List &L);

#endif
```

### file: Singlylist.cpp
```C++
#include "Singlylist.h"

void createList(List &L) {
    L.first = Nil;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = Nil;
}

void insertFirst(List &L, address P) {
    P->next = L.first;
    L.first = P;
}

void delFirst(List &L) {
    if (L.first != Nil) {
        address P = L.first;
        L.first = L.first->next;
        dealokasi(P);
    }
}

void delLast(List &L) {
    if (L.first != Nil) {
        address P = L.first, Q = Nil;
        while (P->next != Nil) {
            Q = P;
            P = P->next;
        }
        if (Q == Nil)
            L.first = Nil;
        else
            Q->next = Nil;
        dealokasi(P);
    }
}

void delAfter(address Prec, List &L) {
    if (Prec != Nil && Prec->next != Nil) {
        address P = Prec->next;
        Prec->next = P->next;
        dealokasi(P);
    }
}

void printInfo(List L) {
    address P = L.first;
    while (P != Nil) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}

int nbList(List L) {
    int count = 0;
    address P = L.first;
    while (P != Nil) {
        count++;
        P = P->next;
    }
    return count;
}

void deleteList(List &L) {
    address P = L.first;
    while (P != Nil) {
        address temp = P;
        P = P->next;
        dealokasi(temp);
    }
    L.first = Nil;
}
```

### file: main.cpp
```C++
#include "Singlylist.h"
#include <iostream>
using namespace std;

int main() {
    List L;
    address P1, P2, P3, P4, P5;

    createList(L);
  
    P1 = alokasi(2);
    insertFirst(L, P1);

    P2 = alokasi(0);
    insertFirst(L, P2);

    P3 = alokasi(8);
    insertFirst(L, P3);

    P4 = alokasi(12);
    insertFirst(L, P4);

    P5 = alokasi(9);
    insertFirst(L, P5);

    delFirst(L);       // hapus node 9
    delLast(L);        // hapus node 2
    delAfter(P4, L);   // hapus node 8
    printInfo(L);
    cout << "Jumlah node : " << nbList(L) << endl;
    cout << endl;
    deleteList(L);
    cout << "- List Berhasil Terhapus -" << endl;
    cout << "Jumlah node : " << nbList(L) << endl;
    cout << endl;

    return 0;
}
```
### Output Unguided 2 :

##### Output
![Screenshot Output Unguided 2_1](https://github.com/savilanf/103112400031_Savila-Nur-Fadilla/blob/main/Pertemuan4_Modul4/output/output-unguided2.png)

Kode dengan bahasa pemrograman C++ untuk membuat Singly Linked List dengan prosedur seperti createList, alokasi, insertFirst, delFirst, delLast, delAfter, nbList, deleteList, dan printInfo. Program menambahkan elemen (9, 12, 8, 0, 2), menghapus beberapa node, menampilkan sisa list serta jumlah node, dan menghapus seluruh list.

## Kesimpulan
Laporan Praktikum Struktur Data Modul 4 ini menggunakan kode bahasa pemrograman C++. Pada praktikum ini dipelajari penerapan Struct dan Abstract Data Type (ADT) dalam pengelolaan Singly Linked List. Melalui latihan 1 dan 2, melatih untuk memahami cara membuat list, menambah, menampilkan, serta menghapus elemen secara dinamis menggunakan pointer. Penerapan ADT membuat program lebih terstruktur, efisien, dan mudah dikembangkan untuk pengolahan data yang kompleks.

## Referensi 

[1] Informatics Laboratory. (n.d.). *Modul 4 – Singly Linked List (Bagian Pertama)*. Program Studi Teknik Informatika, Telkom University.

[2] IJCA (2018). Data Structure Implementation: Singly Linked List Using Dynamic Memory Allocation. International Journal of Computer Applications, Vol. 179, No. 41. Diakses dari https://www.researchgate.net/publication/329412511_Data_Structure_Implementation_Singly_Linked_List_using_Dynamic_Memory_Allocation  

[3] IJCSMC (2022). A New Vista of Performing Insertion and Deletion in Linked Lists. International Journal of Computer Science and Mobile Computing, Vol. 11, Issue 7. Diakses dari https://ijcsmc.com/docs/papers/July2022/V11I7202208.pdf  

[4] IJIRCCE (2017). Enhanced Deletion Operation in Linked List Data Structure. International Journal of Innovative Research in Computer and Communication Engineering, Vol. 5, Issue 4. Diakses dari https://ijircce.com/upload/2017/april/140_Enhanced.pdf  

[5] IJACSA (2021). Visualizing Data Structures: A Study on Linked List Traversal. International Journal of Advanced Computer Science and Applications, Vol. 12, No. 9. Diakses dari https://thesai.org/Publications/ViewPaper?Volume=12&Issue=9&Code=IJACSA&SerialNo=58  

[6] IJCSE (2019). Analysis of ArrayList and Linked List Searching Efficiency. International Journal of Computer Sciences and Engineering, Vol. 7, Issue 4. Diakses dari https://ijcseonline.isroset.org/pub_paper/263-IJCSE-07046-23.pdf