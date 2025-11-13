#include "stack.h"
using namespace std;

int main() {
    Stack S;
    CreateStack(S);

    int pilihan;
    cout << "\n=== MENU STACK ===" << endl;
    cout << "1. Stack Biasa" << endl;
    cout << "2. Push Ascending" << endl;
    cout << "3. Get Input Stream" << endl;
    cout << "Pilih menu: ";
    cin >> pilihan;
    cin.ignore(); //hapus newline sisa input

    switch (pilihan) {
        case 1: {
            cout << "\n-- Stack Biasa --" << endl;
            cout << "Hello world!" << endl;
            push(S, 3);
            push(S, 4);
            push(S, 8);
            pop(S);
            push(S, 2);
            push(S, 9);
            printInfo(S);

            cout << "balik stack" << endl;
            balikStack(S);
            printInfo(S);
            break;
        }
        case 2: {
            cout << "\n-- Push Ascending --" << endl;
            cout << "Hello world!" << endl;

            Stack S;
            CreateStack(S);

            pushAscending(S,3);
            pushAscending(S,4);
            pushAscending(S,8);
            pushAscending(S,2);
            pushAscending(S,3);
            pushAscending(S,9);

            printInfo(S);
            cout<< "balik stack" <<endl;
            balikStack(S);
            printInfo(S);
            break;
        }
        case 3: {
            cout << "\n-- Get Input Stream --" << endl;
            cout << "Masukkan angka (ENTER untuk selesai): " << endl;
            cout << "Hello world!" << endl;
            getInputStream(S);
            printInfo(S);

            cout << "balik stack" << endl;
            balikStack(S);
            printInfo(S);
            break;
        }
        default:
            cout << "Pilihan tidak valid!" << endl;
            break;
    }
    return 0;
}
