#include <iostream>
using namespace std;

void ubahNilai(int* ptr){
    *ptr = 20; //mengubah nilai yang ditunjuk oleh pointer
}

int main(){
    int x = 10;
    cout << "nilai sebelum diubah: " << x << endl;

    ubahNilai(&x); //mengirimkan alamat memori x ke fungsi, tanda & adalah 
    cout << "nilai setelah diubah: " << x << endl;

    return 0;
}