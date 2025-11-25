#include "StackMahasiswa.h"

void CreateStack(StackMahasiswa &S) {
    S.top = -1;
}

bool isEmpty(const StackMahasiswa &S) {
    return S.top == -1;
}

bool isFull(const StackMahasiswa &S) {
    return S.top == MAX - 1;
}

void Push(StackMahasiswa &S, Mahasiswa m) {
    if (isFull(S)) {
        cout << "Stack penuh\n";
    } else {
        S.top++;
        S.data[S.top] = m;
        cout << "Data berhasil ditambahkan\n";
    }
}

void Pop(StackMahasiswa &S) {
    if (isEmpty(S)) {
        cout << "Stack kosong\n";
    } else {
        cout << "Menghapus: " << S.data[S.top].Nama << endl;
        S.top--;
    }
}

void View(const StackMahasiswa &S) {
    if (isEmpty(S)) {
        cout << "Stack kosong!\n";
    } else {
        cout << "\nIsi Stack:\n";
        for (int i = S.top; i >= 0; i--) {
            cout << i << ". "
                 << S.data[i].NIM << " - "
                 << S.data[i].Nama << endl;
        }
    }
}

void Update(StackMahasiswa &S, int posisi, Mahasiswa baru) {
    if (isEmpty(S)) {
        cout << "Stack kosong\n";
        return;
    }

    if (posisi < 0 || posisi > S.top) {
        cout << "Posisi tidak valid\n";
        return;
    }

    S.data[posisi] = baru;
    cout << "Data berhasil diperbarui\n";
}

float HitungNilaiAkhir(const Mahasiswa &m) {
    return 0.2f * m.NilaiTugas + 0.4f * m.NilaiUTS + 0.4f * m.NilaiUAS;
}

float MaxNilaiAkhir(const StackMahasiswa &S) {
    if (isEmpty(S)) {
        cout << "Stack kosong!\n";
        return -1;
    }

    float maks = HitungNilaiAkhir(S.data[0]);

    for (int i = 1; i <= S.top; i++) {
        float akhir = HitungNilaiAkhir(S.data[i]);
        if (akhir > maks)
            maks = akhir;
    }

    return maks;
}