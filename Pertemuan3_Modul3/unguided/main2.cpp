#include "pelajaran.h"
#include <iostream>
using namespace std;

int main() {
    string namaPel = "Struktur Data";
    string kodePel = "STD";
    pelajaran pel = create_pelajaran(namaPel, kodePel);
    tampil_pelajaran(pel);
    return 0;
}