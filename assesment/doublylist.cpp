#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next, *prev;
};

Node *head = NULL;

void insert(int value) {
    Node *baru = new Node();
    baru->data = value;
    baru->next = NULL;
    baru->prev = NULL;

    if (head == NULL) {
        head = baru;
    } else {
        Node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = baru;
        baru->prev = temp;
    }
}

void deleteLast() {
    if (head == NULL) {
        cout << "List kosong\n";
        return;
    }

    if (head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }

    Node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->prev->next = NULL;
    delete temp;
}

void view() {
    if (head == NULL) {
        cout << "List kosong\n";
        return;
    }

    Node *temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void reverseList() {
    if (head == NULL) return;

    Node *curr = head;
    Node *temp = NULL;

    while (curr != NULL) {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;  
    }

    if (temp != NULL) {
        head = temp->prev;  
    }

    cout << "List setelah di-reverse: ";
    view();
}

int main() {
    int menu, value;

    do {
        cout << "Menu: 1 insert (end), 2 delete (last), 3 view (depan), "
                "4 reverse & view (depan), 0 exit\n";
        cin >> menu;

        if (menu == 1) {
            cout << "Masukkan nilai: ";
            cin >> value;
            insert(value);
        } 
        else if (menu == 2) {
            deleteLast();
        } 
        else if (menu == 3) {
            view();
        } 
        else if (menu == 4) {
            reverseList();
        }

    } while (menu != 0);

    return 0;
}