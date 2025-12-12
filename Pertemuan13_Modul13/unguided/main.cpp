#include "MultiLL.h"

int main() {
    listParent LParent;
    createListParent(LParent);

    insertLastParent(LParent, allocNodeParent("G001", "Aves"));
    insertLastParent(LParent, allocNodeParent("G002", "Mamalia"));
    insertLastParent(LParent, allocNodeParent("G003", "Pisces"));
    insertLastParent(LParent, allocNodeParent("G004", "Amfibi"));
    insertLastParent(LParent, allocNodeParent("G005", "Reptil"));

    NodeParent PParent;

    PParent = LParent.first; // G001
    insertLastChild(PParent->L_Child, allocNodeChild("AV001", "Cendrawasih", "Hutan", true, 0.3));
    insertLastChild(PParent->L_Child, allocNodeChild("AV002", "Bebek", "Air", true, 2));

    PParent = PParent->next; // G002
    insertLastChild(PParent->L_Child, allocNodeChild("M001", "Harimau", "Hutan", true, 200));
    insertLastChild(PParent->L_Child, allocNodeChild("M003", "Gorila", "Hutan", false, 160));
    insertLastChild(PParent->L_Child, allocNodeChild("M002", "Kucing", "Darat", true, 4));

    PParent = LParent.first->next->next->next; // G004
    insertLastChild(PParent->L_Child, allocNodeChild("AM001", "Kodok", "Sawah", false, 0.2));

    //nomor 1 print struktur MLL
    printMLLStructure(LParent);

    //nomor2 search ekor = false
    searchHewanByEkor(LParent, false);

    //nomor 3 delete G004
    PParent = LParent.first;
    while (PParent != NULL && PParent->isidata.idGolongan != "G004") {
        PParent = PParent->next;
    }

    if (PParent != NULL) {
        if (PParent == LParent.first) {
            deleteFirstParent(LParent);
        } else {
            deleteAfterParent(LParent, PParent->prev);
        }
    }
    printMLLStructure(LParent); //print setelah delete G004
    return 0;
}
