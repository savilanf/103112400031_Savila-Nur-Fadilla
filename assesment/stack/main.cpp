#include <iostream>
#include "StackMahasiswa.h"
using namespace std;

int main() {
    StackMahasiswa S;
    CreateStack(S);

    int menu;
    do {
        cout << "1. Push data mahasiswa\n";
        cout << "2. Pop data\n";
        cout << "3. View stack\n";
        cout << "4. Cari nilai akhir maksimum\n";
        cout << "5. Update data\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
        cin >> menu;

        if (menu == 1) {
            Mahasiswa m;
            cout << "Nama        : "; cin >> m.Nama;
            cout << "NIM         : "; cin >> m.NIM;
            cout << "Nilai Tugas: "; cin >> m.NilaiTugas; //input pake titik bukan koma
            cout << "Nilai UTS  : "; cin >> m.NilaiUTS;
            cout << "Nilai UAS  : "; cin >> m.NilaiUAS;
            Push(S, m);

        } else if (menu == 2) {
            Pop(S);

        } else if (menu == 3) {
            View(S);

        } else if (menu == 4) {
            float m = MaxNilaiAkhir(S);
            if (m != -1)
                cout << "Nilai akhir tertinggi = " << m << endl;

        } else if (menu == 5) {
            int pos;
            cout << "Masukkan posisi data yang ingin diupdate: ";
            cin >> pos;

            Mahasiswa m;
            cout << "NIM baru        : "; cin >> m.NIM;
            cout << "Nama baru       : "; cin >> m.Nama;
            cout << "Nilai Tugas baru: "; cin >> m.NilaiTugas;
            cout << "Nilai UTS baru  : "; cin >> m.NilaiUTS;
            cout << "Nilai UAS baru  : "; cin >> m.NilaiUAS;

            Update(S, pos, m);
        }

    } while (menu != 0);

    return 0;
}