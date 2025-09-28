#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "input: ";
    cin >> n;
    cout << "output: " << endl;

    for(int i = n; i >= 1; i--){ 
        for(int spasi = n; spasi > i; spasi--){ //buat spasi
            cout << "  ";
        }
        for(int j = i; j >= 1; j--){ //buat decrement
            cout << j << " ";
        }
        cout << "* "; //nyetak bintang di antara dec sama inc
        for(int k = 1; k <= i; k++){ //buat increment
            cout << k << " ";
        }
        cout << endl;
    }

    for(int spasi = 0; spasi < n; spasi++){
        cout << "  ";
    }
    cout << "*" << endl;
    return 0;
}