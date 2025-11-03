#include "Doublylist.h"

int main() {
    List L;
    createList(L);

    char lagi;
    do {
        infotype data;
        cout << "\nmasukkan nomor polisi: ";
        cin >> data.nopol;

        // cek duplikat
        if (findElm(L, data.nopol) != nullptr) {
            cout << "nomor polisi sudah terdaftar\n";
        } else {
            cout << "masukkan warna kendaraan: ";
            cin >> data.warna;
            cout << "masukkan tahun kendaraan: ";
            cin >> data.thnBuat;

            address P = alokasi(data);
            insertLast(L, P);
        }

        cout << "tambah data lagi? (y/n): ";
        cin >> lagi;
    } while (lagi == 'y' || lagi == 'Y');

    printInfo(L);

    // cari data
    cout << "\nMasukkan Nomor Polisi yang dicari: ";
    string cari;
    cin >> cari;
    address found = findElm(L, cari);
    if (found != nullptr) {
        cout << "\nnomor Polisi : " << found->info.nopol
             << "\nwarna        : " << found->info.warna
             << "\ntahun        : " << found->info.thnBuat << endl;
    } else {
        cout << "Data tidak ditemukan.\n";
    }

    // hapus data
    cout << "\nMasukkan Nomor Polisi yang akan dihapus: ";
    string hapus;
    cin >> hapus;
    address target = findElm(L, hapus);

    if (target == nullptr) {
        cout << "Data tidak ditemukan.\n";
    } else {
        address P;
        if (target == L.first)
            deleteFirst(L, P);
        else if (target == L.last)
            deleteLast(L, P);
        else
            deleteAfter(target->prev, P);

        cout << "Data dengan nomor polisi " << hapus << " berhasil dihapus.\n";
        dealokasi(P);
    }

    printInfo(L);
    return 0;
}
