#include "Singlylist.h"

// bikin list kosong
void CreateList(List &L) {
    L.First = Nil;
}

// alokasi node baru
address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    return P;
}

// dealokasi atau delete (hapus node)
void dealokasi(address &P) {
    delete P;
    P = Nil;
}

// tampilin isi list
void printInfo(List L) {
    address P = L.First;
    while (P != Nil) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}

// insert first/awal
void insertFirst(List &L, address P) {
    P->next = L.First;
    L.First = P;
}
