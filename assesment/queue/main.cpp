#include <iostream>
#include "QueuePengiriman.h"
using namespace std;

int main() {
    QueueEkspedisi Q;
    createQueue(Q);

    int pilih;
    Paket P;

    do {
        cout << "\n--- Komaniya Ekspress ---\n";
        cout << "1. Input Data Paket\n";
        cout << "2. Hapus Data Paket\n";
        cout << "3. Tampilkan Queue Paket\n";
        cout << "4. Hitung Total Biaya Pengiriman\n";
        cout << "0. Keluar\n";
        cout << "Pilihan anda : ";
        cin >> pilih;

        switch (pilih) {
        case 1:
            cout << "Kode Resi: ";
            cin >> P.KodeResi;
            cout << "Nama Pengirim: ";
            cin >> P.NamaPengirim;
            cout << "Berat Barang: ";
            cin >> P.BeratBarang;
            cout << "Tujuan: ";
            cin >> P.Tujuan;
            enQueue(Q, P);
            break;

        case 2:
            deQueue(Q);
            break;

        case 3:
            viewQueue(Q);
            break;

        case 4:
            cout << "Total biaya pengiriman: Rp "
                 << TotalBiayaPengiriman(Q) << endl;
            break;

        case 0:
            cout << "Program selesai.\n";
            break;

        default:
            cout << "Pilihan tidak valid!\n";
        }

    } while (pilih != 0);

    return 0;
}