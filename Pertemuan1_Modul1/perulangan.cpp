#include <iostream>
using namespace std;

int main(){
    int angka1; //deklarasi variabel
    cout << "Masukkan angka 1: ";
    cin >> angka1; //masukin input 1
    
    for(int i = 0; i < angka1; i++){ //increment
        cout << i << " - " ;
    }

    cout << endl;

    int j = 10;
    while (j > angka1){ //decrement
        cout << j << " - ";
        j--;
    }

    cout << endl;
    
    int k = 10;
    do{
        cout << k << " - ";
        k++;
    } while (k < angka1);       

return 0;
}