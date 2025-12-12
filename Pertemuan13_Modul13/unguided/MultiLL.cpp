#include "MultiLL.h"

bool isEmptyParent(listParent LParent) {
    return (LParent.first == NULL);
}

bool isEmptyChild(listChild LChild) {
    return (LChild.first == NULL);
}

void createListParent(listParent &LParent) {
    LParent.first = NULL;
    LParent.last = NULL;
}

void createListChild(listChild &LChild) {
    LChild.first = NULL;
    LChild.last = NULL;
}

NodeParent allocNodeParent(string idGol, string namaGol) {
    NodeParent NParent = new nodeParent;
    NParent->isidata.idGolongan = idGol;
    NParent->isidata.namaGolongan = namaGol;
    NParent->next = NULL;
    NParent->prev = NULL;

    createListChild(NParent->L_Child);

    return NParent;
}

NodeChild allocNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight) {
    NodeChild NChild = new nodeChild;
    NChild->isidata.idHewan = idHwn;
    NChild->isidata.namaHewan = namaHwn;
    NChild->isidata.habitat = habitat;
    NChild->isidata.ekor = tail;
    NChild->isidata.bobot = weight;

    NChild->next = NULL;
    NChild->prev = NULL;
    return NChild;
}

void deallocNodeParent(NodeParent &NParent) {
    delete NParent;
}

void deallocNodeChild(NodeChild &NChild) {
    delete NChild;
}

void insertFirstParent(listParent &LParent, NodeParent newNode) {
    if (isEmptyParent(LParent)) {
        LParent.first = newNode;
        LParent.last = newNode;
    } else {
        newNode->next = LParent.first;
        LParent.first->prev = newNode;
        LParent.first = newNode;
    }
}

void insertLastParent(listParent &LParent, NodeParent newNode) {
    if (isEmptyParent(LParent)) {
        insertFirstParent(LParent, newNode);
    } else {
        LParent.last->next = newNode;
        newNode->prev = LParent.last;
        LParent.last = newNode;
    }
}

void deleteFirstParent(listParent &LParent) {
    if (!isEmptyParent(LParent)) {
        NodeParent del = LParent.first;

        if (LParent.first == LParent.last) {  
            LParent.first = NULL;
            LParent.last = NULL;
        } else {
            LParent.first = del->next;
            LParent.first->prev = NULL;
        }

        deleteListChild(del->L_Child);
        deallocNodeParent(del);
    }
}

void deleteAfterParent(listParent &LParent, NodeParent NPrev) {
    if (NPrev != NULL && NPrev->next != NULL) {
        NodeParent del = NPrev->next;

        NPrev->next = del->next;
        if (del == LParent.last) {
            LParent.last = NPrev;
        } else {
            del->next->prev = NPrev;
        }

        deleteListChild(del->L_Child);
        deallocNodeParent(del);
    }
}

void insertFirstChild(listChild &LChild, NodeChild newNode) {
    if (isEmptyChild(LChild)) {
        LChild.first = newNode;
        LChild.last = newNode;
    } else {
        newNode->next = LChild.first;
        LChild.first->prev = newNode;
        LChild.first = newNode;
    }
}

void insertLastChild(listChild &LChild, NodeChild newNode) {
    if (isEmptyChild(LChild)) {
        insertFirstChild(LChild, newNode);
    } else {
        LChild.last->next = newNode;
        newNode->prev = LChild.last;
        LChild.last = newNode;
    }
}

void deleteFirstChild(listChild &LChild) {
    if (!isEmptyChild(LChild)) {
        NodeChild del = LChild.first;

        if (LChild.first == LChild.last) {
            LChild.first = NULL;
            LChild.last = NULL;
        } else {
            LChild.first = del->next;
            LChild.first->prev = NULL;
        }

        deallocNodeChild(del);
    }
}

void deleteAfterChild(listChild &LChild, NodeChild NPrev) {
    if (NPrev != NULL && NPrev->next != NULL) {
        NodeChild del = NPrev->next;

        NPrev->next = del->next;
        if (del == LChild.last) {
            LChild.last = NPrev;
        } else {
            del->next->prev = NPrev;
        }

        deallocNodeChild(del);
    }
}

void deleteListChild(listChild &LChild) {
    while (!isEmptyChild(LChild)) {
        deleteFirstChild(LChild);
    }
}

void printMLLStructure(listParent LParent) {
    NodeParent PParent = LParent.first;
    int parentPos = 1;

    while (PParent != NULL) {
        cout << "=== Parent " << parentPos << " ===" << endl;
        cout << "ID golongan : " << PParent->isidata.idGolongan << endl;
        cout << "Nama golongan : " << PParent->isidata.namaGolongan << endl;

        NodeChild PChild = PParent->L_Child.first;

        if (PChild == NULL) {
            cout << "(tidak ada child)" << endl;
        } else {
            int childPos = 1;
            while (PChild != NULL) {
                cout << "- Child " << childPos << " :" << endl;
                cout << "   ID hewan : " << PChild->isidata.idHewan << endl;
                cout << "   Nama hewan : " << PChild->isidata.namaHewan << endl;
                cout << "   Habitat : " << PChild->isidata.habitat << endl;
                cout << "   Ekor : " << (PChild->isidata.ekor ? 1 : 0) << endl;
                cout << "   Bobot : " << PChild->isidata.bobot << endl;
                PChild = PChild->next;
                childPos++;
            }
        }
        cout << "--------------------------" << endl;
        PParent = PParent->next;
        parentPos++;
    }
}

void searchHewanByEkor(listParent LParent, bool tail) {

    NodeParent PParent = LParent.first;
    int parentPos = 1; //posisi parent dimulai 1

    while (PParent != NULL) {

        NodeChild PChild = PParent->L_Child.first;
        int childPos = 1; //posisi child dimulai 1

        while (PChild != NULL) {

            if (PChild->isidata.ekor == tail) {

                cout << "Data ditemukan pada list anak dari node parent "
                     << PParent->isidata.namaGolongan
                     << " pada posisi ke-" << childPos << "!\n";

                cout << "--- Data Child ---" << endl;
                cout << "ID Child : " << PChild->isidata.idHewan << endl;
                cout << "Posisi dalam list anak : posisi ke-" << childPos << endl;
                cout << "Nama Hewan : " << PChild->isidata.namaHewan << endl;
                cout << "Habitat : " << PChild->isidata.habitat << endl;
                cout << "Ekor : " << (PChild->isidata.ekor ? 1 : 0) << endl;
                cout << "Bobot : " << PChild->isidata.bobot << endl;
                cout << "-------------------------" << endl;

                cout << "--- Data Parent ---" << endl;
                cout << "ID Parent : " << PParent->isidata.idGolongan << endl;
                cout << "Posisi dalam list induk : posisi ke-" << parentPos << endl;
                cout << "Nama golongan : " << PParent->isidata.namaGolongan << endl;
                cout << "-------------------------" << endl;
            }
            PChild = PChild->next;
            childPos++;    //ke child berikutnya
        }
        PParent = PParent->next;
        parentPos++; //ke parent berikutnya
    }
}