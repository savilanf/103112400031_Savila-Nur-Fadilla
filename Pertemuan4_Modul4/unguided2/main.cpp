#include "Singlylist.h"
#include <iostream>
using namespace std;

int main() {
    List L;
    address P1, P2, P3, P4, P5;

    createList(L);

    // insert elemen ke list
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

    // nampilin sisa isi list
    printInfo(L);
    cout << "Jumlah node : " << nbList(L) << endl;
    cout << endl;

    // hapus seluruh list
    deleteList(L);
    cout << "- List Berhasil Terhapus -" << endl;
    cout << "Jumlah node : " << nbList(L) << endl;
    cout << endl;

    return 0;
}
