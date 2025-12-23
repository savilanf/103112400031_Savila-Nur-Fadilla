#include "mll.h"

void createListParent(ListParent &LP) {
    LP.first = NULL;
    LP.last = NULL;
}

void createListChild(ListChild &LC) {
    LC.first = NULL;
    LC.last = NULL;
}

NodeParent* alokasiNodeParent(string id, string nama) {
    NodeParent *P = new NodeParent;
    P->IDGenre = id;
    P->namaGenre = nama;
    P->next = NULL;
    P->prev = NULL;
    createListChild(P->child);
    return P;
}

NodeChild* alokasiNodeChild(string id, string judul, int durasi, int tahun, float rating) {
    NodeChild *C = new NodeChild;
    C->IDFilm = id;
    C->judulFilm = judul;
    C->durasiFilm = durasi;
    C->tahunTayang = tahun;
    C->ratingFilm = rating;
    C->next = NULL;
    C->prev = NULL;
    return C;
}

void dealokasiNodeParent(NodeParent *P) {
    delete P;
}

void dealokasiNodeChild(NodeChild *C) {
    delete C;
}

void insertFirstParent(ListParent &LP, NodeParent *P) {
    if (LP.first == NULL) {
        LP.first = LP.last = P;
    } else {
        P->next = LP.first;
        LP.first->prev = P;
        LP.first = P;
    }
}

void insertLastChild(ListChild &LC, NodeChild *C) {
    if (LC.first == NULL) {
        LC.first = LC.last = C;
    } else {
        LC.last->next = C;
        C->prev = LC.last;
        LC.last = C;
    }
}

void hapusListChild(ListChild &LC) {
    NodeChild *C;
    while (LC.first != NULL) {
        C = LC.first;
        LC.first = C->next;
        dealokasiNodeChild(C);
    }
    LC.last = NULL;
}

void deleteAfterParent(ListParent &LP, NodeParent *prev) {
    NodeParent *P = prev->next;
    if (P != NULL) {
        hapusListChild(P->child);
        prev->next = P->next;
        if (P->next != NULL) {
            P->next->prev = prev;
        } else {
            LP.last = prev;
        }
        dealokasiNodeParent(P);
    }
}

void printStrukturMLL(ListParent LP) {
    NodeParent *P = LP.first;
    int i = 1;
    while (P != NULL) {
        cout << "== parent " << i++ << " ==\n";
        cout << "ID genre : " << P->IDGenre << endl;
        cout << "nama genre : " << P->namaGenre << endl;

        NodeChild *C = P->child.first;
        int j = 1;
        while (C != NULL) {
            cout << "- child " << j++ << " :\n";
            cout << "ID film : " << C->IDFilm << endl;
            cout << "judul film : " << C->judulFilm << endl;
            cout << "durasi film : " << C->durasiFilm << " menit\n";
            cout << "tahun tayang : " << C->tahunTayang << endl;
            cout << "rating film : " << C->ratingFilm << endl;
            C = C->next;
        }
        cout << "--------------------------\n";
        P = P->next;
    }
}

void searchFilmByRatingRange(ListParent LP, float min, float max) {
    NodeParent *P = LP.first;
    int posParent = 1;
    while (P != NULL) {
        NodeChild *C = P->child.first;
        int posChild = 1;
        while (C != NULL) {
            if (C->ratingFilm >= min && C->ratingFilm <= max) {
                cout << "data film ditemukan!\n";
                cout << "--- data film (child) ---\n";
                cout << "judul film : " << C->judulFilm << endl;
                cout << "posisi child : " << posChild << endl;
                cout << "rating : " << C->ratingFilm << endl;
                cout << "--- data genre (parent) ---\n";
                cout << "ID genre : " << P->IDGenre << endl;
                cout << "posisi parent : " << posParent << endl;
                cout << "nama genre : " << P->namaGenre << endl;
                cout << "=========================\n";
            }
            C = C->next;
            posChild++;
        }
        P = P->next;
        posParent++;
    }
}