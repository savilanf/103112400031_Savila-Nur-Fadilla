#include <iostream>
#include "mahasiswa.h"
#include <cstdlib> //merupakan sistem pause biar kalo running ga langsung ke close

using namespace std;

int main() {
    mahasiswa mhs;

    inputMhs(mhs);

    cout << "rata-rata nilai adalah : " << rata2
    (mhs) <<endl;
    system ("pause");

    return 0;
}