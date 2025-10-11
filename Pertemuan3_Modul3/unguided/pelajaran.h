#ifndef PELAJARAN_H
#define PELAJARAN_H

#include <string>
using namespace std;

struct pelajaran {
    string namaPel;
    string kodePel;
};

pelajaran create_pelajaran(string namaPel, string kodePel);
void tampil_pelajaran(const pelajaran& p);

#endif