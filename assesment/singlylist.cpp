#include <iostream>
#include <string>
using namespace std;

struct Node {
    string nama;
    Node* next;
};

Node* head = nullptr;

void insert(string nama) {
    Node* baru = new Node{nama, nullptr};
    if (head == nullptr) {
        head = baru;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) temp = temp->next;
    temp->next = baru;
}

void deleteName(string nama) {
    if (head == nullptr) return;

    if (head->nama == nama) {
        Node* p = head;
        head = head->next;
        delete p;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr && temp->next->nama != nama)
        temp = temp->next;

    if (temp->next != nullptr) {
        Node* p = temp->next;
        temp->next = temp->next->next;
        delete p;
    }
}

void viewList() {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->nama;
        if (temp->next != nullptr) cout << " ";
        temp = temp->next;
    }
    cout << endl;
}

int hitungGenap() {
    int count = 0;
    Node* temp = head;

    while (temp != nullptr) {
        if (temp->nama.length() % 2 == 0)
            count++;
        temp = temp->next;
    }

    return count;
}

int main() {
    int menu;
    string nama;

    do {
        cout << "Menu: 1 insert, 2 delete, 3 view, 4 hitung genap, 0 exit\n";
        cin >> menu;

        if (menu == 1) {
            cout << "masukkan nama: ";
            cin >> nama;
            insert(nama);
        }
        else if (menu == 2) {
            cout << "masukkan nama untuk delete: ";
            cin >> nama;
            deleteName(nama);
        } 
        else if (menu == 3) {
            viewList();
        } 
        else if (menu == 4) {
            cout << "jumlah nama dengan huruf genap: " << hitungGenap() << endl;
        }

    } while (menu != 0);

    return 0;
}