#include "mll.h"

int main() {
    ListParent LP;
    createListParent(LP);

    NodeParent *G1 = alokasiNodeParent("G001", "action");
    NodeParent *G2 = alokasiNodeParent("G002", "comedy");
    NodeParent *G3 = alokasiNodeParent("G003", "horror");
    NodeParent *G4 = alokasiNodeParent("G004", "romance");

    insertFirstParent(LP, G4);
    insertFirstParent(LP, G3);
    insertFirstParent(LP, G2);
    insertFirstParent(LP, G1);

    insertLastChild(G1->child, alokasiNodeChild("FA001","The Raid",101,2011,7.6));
    insertLastChild(G2->child, alokasiNodeChild("FC001","Agak Laen",119,2024,8.0));
    insertLastChild(G2->child, alokasiNodeChild("FC002","My Stupid Boss",108,2016,6.8));
    insertLastChild(G3->child, alokasiNodeChild("FH001","Pengabdi Setan",107,2017,8.4));
    insertLastChild(G4->child, alokasiNodeChild("FR001","Habibie & Ainun",118,2012,7.6));
    insertLastChild(G4->child, alokasiNodeChild("FR002","Dilan 1990",110,2018,6.6));

    printStrukturMLL(LP);

    cout << "\nsearch rating 8.0 - 8.5\n";
    searchFilmByRatingRange(LP, 8.0, 8.5);

    deleteAfterParent(LP, G1); //hapus G002
    cout << "\nsetelah delete:\n";
    printStrukturMLL(LP);

    return 0;
}