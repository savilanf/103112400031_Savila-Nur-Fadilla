#include <iostream>
using namespace std;

void tampilkanHasil(int arr[3][3]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void jumlahMatriks(int arrA[3][3], int arrB[3][3], int arrC[3][3]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            arrC[i][j] = arrA[i][j] + arrB[i][j];
        }
    }
}

void kurangMatriks(int arrA[3][3], int arrB[3][3], int arrC[3][3]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            arrC[i][j] = arrA[i][j] - arrB[i][j];
        }
    }
}

void kaliMatriks(int arrA[3][3], int arrB[3][3], int arrC[3][3]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            arrC[i][j] = 0; 
            for(int k = 0; k < 3; k++){
                arrC[i][j] += arrA[i][k] * arrB[k][j];
            }
        }
    }
}

int main(){
    int arrA[3][3] = {
        {7, 12, 22},
        {31, 6, 41},
        {15, 19, 36}
    };
    int arrB[3][3] = {
        {11, 34, 7},
        {3, 25, 41},
        {5, 18, 33}
    };
    int arrC[3][3];

    int menu;
    cout << "\n--- MENU OPERASI MATRIKS ---" << endl;
    cout << "1. Penjumlahan matriks" << endl;
    cout << "2. Pengurangan matriks" << endl;
    cout << "3. Perkalian matriks" << endl;
    cout << "4. Keluar" << endl;
    cout << "Pilih (1-4): ";
    cin >> menu;
    switch(menu){
        case 1:
            jumlahMatriks(arrA, arrB, arrC);
            cout << "\nHasil penjumlahan matriks A dan B:\n";
            tampilkanHasil(arrC);
            break;
        case 2:
            kurangMatriks(arrA, arrB, arrC);
            cout << "\nHasil pengurangan matriks A dan B:\n";
            tampilkanHasil(arrC);
            break;
        case 3:
            kaliMatriks(arrA, arrB, arrC);
            cout << "\nHasil perkalian matriks A dan B:\n";
            tampilkanHasil(arrC);
            break;
        case 4:
            cout << "Keluar dari program.\n";
            break;
        default:
            cout << "Pilihan tidak valid\n";
    }
}