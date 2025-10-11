#include "pelajaran.h"
#include <iostream>
using namespace std;

pelajaran create_pelajaran(string namaPel, string kodePel) {
    pelajaran p;
    p.namaPel = namaPel;
    p.kodePel = kodePel;
    return p;
}

void tampil_pelajaran(const pelajaran& p) {
    cout << "nama pelajaran : " << p.namaPel << endl;
    cout << "nilai : " << p.kodePel << endl;
}