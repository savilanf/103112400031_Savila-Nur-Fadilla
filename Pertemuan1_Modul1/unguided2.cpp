#include <iostream>
using namespace std;

int main(){
    int angka;
    cout << "Masukkan angka: ";
    cin >> angka;
    if (angka < 0 || angka > 100) {
        cout << "error, angka tidak valid" << endl;
        return 0;
    } else if (angka == 100) {
        cout << "seratus" << endl;
    } else if (angka == 0) {
        cout << "nol" << endl;
    } else if (angka == 1) {
        cout << "satu" << endl;
    } else if (angka == 2) {
        cout << "dua" << endl;
    } else if (angka == 3) {
        cout << "tiga" << endl;
    } else if (angka == 4) {
        cout << "empat" << endl;
    } else if (angka == 5) {
        cout << "lima" << endl;
    } else if (angka == 6) {
        cout << "enam" << endl;
    } else if (angka == 7) {
        cout << "tujuh" << endl;
    } else if (angka == 8) {
        cout << "delapan" << endl;
    } else if (angka == 9) {
        cout << "sembilan" << endl;
    } else if (angka == 10) {
        cout << "sepuluh" << endl;
    } else if (angka == 11) {
        cout << "sebelas" << endl;
    } else if (angka == 12) {
        cout << "dua belas" << endl;
    } else if (angka == 13) {
        cout << "tiga belas" << endl;
    } else if (angka == 14) {
        cout << "empat belas" << endl;
    } else if (angka == 15) {
        cout << "lima belas" << endl;
    } else if (angka == 16) {
        cout << "enam belas" << endl;
    } else if (angka == 17) {
        cout << "tujuh belas" << endl;
    } else if (angka == 18) {
        cout << "delapan belas" << endl;
    } else if (angka == 19) {
        cout << "sembilan belas" << endl;
    } else if (angka == 20) {
        cout << "dua puluh" << endl;
    } else if (angka == 30) {
        cout << "tiga puluh" << endl;
    } else if (angka == 40) {
        cout << "empat puluh" << endl;
    } else if (angka == 50) {
        cout << "lima puluh" << endl;
    } else if (angka == 60) {
        cout << "enam puluh" << endl;
    } else if (angka == 70) {
        cout << "tujuh puluh" << endl;
    } else if (angka == 80) {
        cout << "delapan puluh" << endl;
    } else if (angka == 90) {
        cout << "sembilan puluh" << endl;
    } 

    else {
        int puluhan = angka / 10;
        int satuan = angka % 10;

        if (puluhan == 2) cout << "dua puluh";
        else if (puluhan == 3) cout << "tiga puluh";
        else if (puluhan == 4) cout << "empat puluh";
        else if (puluhan == 5) cout << "lima puluh";
        else if (puluhan == 6) cout << "enam puluh";
        else if (puluhan == 7) cout << "tujuh puluh";
        else if (puluhan == 8) cout << "delapan puluh";
        else if (puluhan == 9) cout << "sembilan puluh";

        if (satuan == 1) cout << " satu";
        else if (satuan == 2) cout << " dua";
        else if (satuan == 3) cout << " tiga";
        else if (satuan == 4) cout << " empat";
        else if (satuan == 5) cout << " lima";
        else if (satuan == 6) cout << " enam";
        else if (satuan == 7) cout << " tujuh";
        else if (satuan == 8) cout << " delapan";
        else if (satuan == 9) cout << " sembilan";

        cout << endl;
    } 
    return 0;
}