//header guard digunakan untuk mencegah frile header yang sama
#ifndef LISTBUAH_H
#define LISTBUAH_H
#define Nil NULL

#include <iostream>
using namespace std;
struct buah{
    string nama;
    int jumlah;
    float harga;
};

typedef buah dataBuah; //memberikan nama alias databuah untuk struct buah
typedef struct node *address; // mendefinisikan address sebagai pointer ke struct node

struct node{ //node untuk isi linked listnya, isi setiap node adalah data dan pointer
    dataBuah isidata;
    address next;
};

struct linkedlist{ //ini linked listnya
    address first;
};

//semua function dan prosedur yang dipakai
//materi modul 4
bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, int jumlah, float harga);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &list, address nodeBaru);
void insertAfter(linkedlist &list, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);
void delFirst(linkedlist &List);
void delLast(linkedlist &List);
void delAfter(linkedlist &List, address nodeHapus, address nodePrev);
int nbList(linkedlist List);
void deleteList(linkedlist &List);

//materi modul 5
void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address Prev);

#endif