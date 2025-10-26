#include <iostream>
using namespace std;

//struktur Node
struct Node {
    int data;
    Node* next;
};

//fungsi untuk menambah node di akhir linked list
void append(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr}; //bikin node baru, nextnya masih null, soalnya masih baru
    if (!head) head = newNode; //jika linked list masih kosong
    else {
        Node* temp = head; //mulai dari head atau node pertama
        while (temp->next) temp = temp->next; //cari node terakhir
        temp->next = newNode; //sambungkan ke node baru
    }
}

//fungsi untuk mencetak seluruh isi linked list
void printList(Node* head) {
    cout << "Linked List yang dibuat: ";
    Node* temp = head; //node bantu
    while (temp) { //selama masih ada node
        cout << temp->data; //nampilin data
        if (temp->next) cout << " -> "; //panah kalau belum di akhir
        temp = temp->next; //pindah node berikutnya
    }
    cout << " -> NULL" << endl; //buat di akhir list
}

//fungsi pencarian linear
Node* linearSearch(Node* head, int key) {
    Node* current = head; //pointer nelusuri head
    int i = 1; //untuk menampilkan iterasi keberapa
    cout << "\nProses Pencarian:\n";
    while (current != nullptr) { //selama node sekarang gak null/masih ada node
        cout << "Memeriksa node " << i << ": " << current->data;
        if (current->data == key) { //jika data ketemu dan sama kayak yang dicari atau si keynya itu
            cout << " (SAMA) - DITEMUKAN!\n";
            return current; //return node yang ketemu
        } else { //ni kalau datanya masih belum sama
            cout << " (tidak sama)\n";
        }
        current = current->next; //pindah ke node berikutnya
        i++; //iterasinya nambah
    }
    cout << "Tidak ada node lagi yang tersisa\n"; //ni berarti udah sampe node terakhir, makannya keluar teks gaada node tersisa
    return nullptr; //jika data tidak ditemukan
}

int main() {
    cout << "LINEAR SEARCH PADA LINKED LIST\n";

    //membuat linked list
    Node* head = nullptr; //head masih null
    append(head, 10);
    append(head, 20);
    append(head, 30);
    append(head, 40);
    append(head, 50);

    printList(head);

    //cari 30
    int key = 30; //ni keynya atau data yang dicari, bebas diubah"
    cout << "Mencari nilai: " << key << endl;
    Node* result = linearSearch(head, key);

    if (result) {
        cout << "\nHasil: Nilai " << key << " DITEMUKAN pada linked list!\n";
        cout << "Alamat node: " << result << endl;
        cout << "Data node: " << result->data << endl;
        if (result->next)
            cout << "Node berikutnya: " << result->next->data << endl;
        else
            cout << "Node berikutnya: NULL\n";
    } else {
        cout << "\nHasil: Nilai " << key << " TIDAK DITEMUKAN dalam linked list!\n";
    }

    //cari 25
    key = 25; //ni keynya atau data yang dicari, bebas diubah
    cout << "Mencari nilai: " << key << endl;
    result = linearSearch(head, key);

    if (result) {
        cout << "\nHasil: Nilai " << key << " DITEMUKAN pada linked list!\n";
        cout << "Alamat node: " << result << endl;
        cout << "Data node: " << result->data << endl;
        if (result->next)
            cout << "Node berikutnya: " << result->next->data << endl;
        else
            cout << "Node berikutnya: NULL\n";
    } else {
        cout << "\nHasil: Nilai " << key << " TIDAK DITEMUKAN dalam linked list!\n";
    }

    return 0;
}
