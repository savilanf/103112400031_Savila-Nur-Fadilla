#include "Singlylist.h"

// bikin list kosong
void createList(List &L) {
    L.first = Nil;
}

// alokasi node baru
address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    return P;
}

// hapus/delet node
void dealokasi(address &P) {
    delete P;
    P = Nil;
}

// insert forst/awal
void insertFirst(List &L, address P) {
    P->next = L.first;
    L.first = P;
}

// hapus node pertama
void delFirst(List &L) {
    if (L.first != Nil) {
        address P = L.first;
        L.first = L.first->next;
        dealokasi(P);
    }
}

// hapus node terakhir
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

// hapus node after
void delAfter(address Prec, List &L) {
    if (Prec != Nil && Prec->next != Nil) {
        address P = Prec->next;
        Prec->next = P->next;
        dealokasi(P);
    }
}

// tampilin isi list
void printInfo(List L) {
    address P = L.first;
    while (P != Nil) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}

// hitung jumlah node
int nbList(List L) {
    int count = 0;
    address P = L.first;
    while (P != Nil) {
        count++;
        P = P->next;
    }
    return count;
}

// hapus seluruh node list
void deleteList(List &L) {
    address P = L.first;
    while (P != Nil) {
        address temp = P;
        P = P->next;
        dealokasi(temp);
    }
    L.first = Nil;
}
