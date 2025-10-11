// mahasiswa.cpp guided 2

#include <iostream>
#include "mahasiswa.h"

using namespace std;

// realisasi dari fungsi inputMhs
void inputMhs (mahasiswa &m) {
    cout << "input NIM : ";
    cin >> m.nim;
    cout << "input nilai 1 : ";
    cin >> m.nilai1;
    cout << "input nilai 2 : ";
    cin >> m.nilai2;
}

// realisasi dari fungsi rata rata
float rata2 (mahasiswa m) {
    return (float) (m.nilai1 + m.nilai2) / 2;
}