#include <iostream>
#include "bstree.h"
using namespace std;

int main() {
    address root = NULL;
    int pilihan;

    cout << "1. Nomor 1" << endl;
    cout << "2. Nomor 2" << endl;
    cout << "3. Nomor 3" << endl;
    cout << "Pilih: ";
    cin >> pilihan;

    switch(pilihan) {
        case 1:
            insertNode(root, 1);
            insertNode(root, 2);
            insertNode(root, 3);
            insertNode(root, 4);
            insertNode(root, 5);
            insertNode(root, 6);
            insertNode(root, 7);

            cout << "Hello world!\n";
            printInOrder(root);
            cout << endl;
            break;

        case 2:
            cout << "Hello world!\n";
            insertNode(root,1);
            insertNode(root,2);
            insertNode(root,6);
            insertNode(root,4);
            insertNode(root,5);
            insertNode(root,3);
            insertNode(root,6); // ignored (duplicate)
            insertNode(root,7);

            printInOrder(root);
            cout << endl;
            cout << "kedalaman : " << hitungKedalaman(root,0) << endl;
            cout << "jumlah node : " << hitungJumlahNode(root) << endl;
            cout << "total : " << hitungTotalInfo(root) << endl;
            break;

        case 3:
            insertNode(root,6);
            insertNode(root,4);
            insertNode(root,7);
            insertNode(root,2);
            insertNode(root,5);
            insertNode(root,1);
            insertNode(root,3);

            cout << "PreOrder  : ";
            printPreOrder(root);
            cout << "\nPostOrder : ";
            printPostOrder(root);
            cout << endl;
            break;

        default:
            cout << "Pilihan tidak valid!\n";
    }

    return 0;
}
