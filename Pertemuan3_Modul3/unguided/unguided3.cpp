#include <iostream>
using namespace std;

// Fungsi untuk menampilkan isi array 2D
void tampilArray(int arr[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}

// Fungsi untuk menukar isi dua array 2D pada posisi tertentu
void tukarPosisi(int arr1[3][3], int arr2[3][3], int baris, int kolom) {
    int temp = arr1[baris][kolom];
    arr1[baris][kolom] = arr2[baris][kolom];
    arr2[baris][kolom] = temp;
}

// Fungsi untuk menukar nilai dari dua variabel yang ditunjuk oleh pointer
void tukarPointer(int* p1, int* p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int main() {
    int A[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int B[3][3] = {
        {10, 11, 12},
        {13, 14, 15},
        {16, 17, 18}
    };


    int a = 10, b = 20;
    int *ptr1 = &a, *ptr2 = &b;

    cout << "Array A awal:\n";
    tampilArray(A);
    cout << "\nArray B awal:\n";
    tampilArray(B);

    int baris, kolom;
    cout << "\nMasukkan posisi baris (1-3): ";
    cin >> baris;
    cout << "Masukkan posisi kolom (1-3): ";
    cin >> kolom;

    baris -= 1;
    kolom -= 1;

    // Validasi biar gak out of range
    if (baris < 0 || baris > 2 || kolom < 0 || kolom > 2) {
        cout << "\n⚠️  Posisi tidak valid! Harus antara 1 dan 3.\n";
        return 0;
    }

    tukarPosisi(A, B, baris, kolom);

    cout << "\nSetelah tukar posisi (" << baris + 1 << "," << kolom + 1 << "):\n";
    cout << "Array A:\n";
    tampilArray(A);
    cout << "\nArray B:\n";
    tampilArray(B);

    cout << "\nSebelum tukar pointer: a = " << a << ", b = " << b << endl;
    tukarPointer(ptr1, ptr2);
    cout << "Setelah tukar pointer: a = " << a << ", b = " << b << endl;

    return 0;
}
