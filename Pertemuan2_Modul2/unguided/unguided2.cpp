#include <iostream>
using namespace std;

void ubahNilai(int *ptrPanjang, int *ptrLebar, int &refLuas, int &refKeliling){
    refLuas = (*ptrPanjang) * (*ptrLebar);
    refKeliling = 2 * ((*ptrPanjang) + (*ptrLebar));

}

int main(){
    int panjang = 10;
    int lebar = 5;
    int luas = 0;
    int keliling = 0;
    cout << "\n--- Nilai Awal ---" << endl;
    cout << "Panjang: " << panjang << endl;
    cout << "Lebar: " << lebar << endl;
    ubahNilai(&panjang, &lebar, luas, keliling);
    cout << "\n--- Hasil Perhitungan ---" << endl;
    cout << "Luas persegi panjang: " << luas << endl;
    cout << "Keliling persegi panjang: " << keliling << endl;
    cout << "\n--- Nilai Setelah Diubah Melalui Pointer ---" << endl;
    cout << "Panjang baru: ";
    cin >> panjang;
    cout << "Lebar baru: ";
    cin >> lebar;
    ubahNilai(&panjang, &lebar, luas, keliling);
    cout << "Luas baru: " << luas << endl;
    cout << "Keliling baru: " << keliling << endl;
    return 0;
}