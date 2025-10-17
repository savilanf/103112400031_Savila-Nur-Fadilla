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

// deklarasi fungsi dan prosedur
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
