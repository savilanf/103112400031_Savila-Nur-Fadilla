#include <iostream>
using namespace std;

// DEFINISI NODE
struct Node{ 
    int data;
    Node* next; // pointer ke node berikutnya
};

// fungsi untuk pencarian linear
Node* linearSearch(Node* head, int key) { //node* ini pointer (kembalian) //fs linear search
    Node* current = head; // current ini pointer yang nunjuk ke node
    while(current != nullptr){ // melakukan pengecekan apakah current tidak bernilai null
        if(current->data == key) return current; //jika ketemu data
        current = current->next; //pindah ke node berikutnya
    }
    return nullptr; // tidak ditemukan
}

void append(Node*& head, int value){ //parameter head adalah rederensi ke pointer head //value data yang mau dimasukin
    Node* newNode = new Node{value,nullptr}; //alokasi memori untuk node baru

    if(!head)head = newNode; //jika head null, head diisi node baru
    else{
        Node*temp = head; // mulai dari head
        while (temp->next) temp = temp->next; //pindah ke node berikutnya sampai ketemu node terakhir
        temp->next = newNode; //node terakhir dihubungkan ke node baru
    }
}

Node* binarySearch(Node* head, int key){
    int size = 0; //var size diisi 0
    for(Node* current = head; current; current = current->next) //current pointer untuk menelusuri linked list
        size++;

    Node* start = head; //start: pointer yang menunjuk ke node pertama
    Node* end = nullptr; //end: pointer yang menunjuk ke node setelah node terakhir

    while (size > 0 && start != end) { //selagi masih ada elemen
        int mid = size / 2;
        Node* midNode = start; //midNode: pointer yang menunjuk ke node tengah
        for (int i = 0; i < mid; i++) 
            midNode = midNode->next; //pindah ke node tengah

        if (midNode == nullptr) break;

        if (midNode->data == key) return midNode; //jika ketemu
        else if (midNode->data < key) {
            start = midNode->next; //cari di bagian kanan, startnya pindah ke node setelah midNode
            size = size - mid - 1; //sisa di kanan
        } else {
            end = midNode; //cari di bagian kiri, endnya pindah ke midNode
            size = mid; //sisa di kiri
        }
    }
    return nullptr;
}


int main(){
    Node*head = nullptr; //inisialisasi head list masih kosong
    append(head, 10); append(head, 20); append(head, 30); //menambah node ke list
    append(head, 40); append(head, 50);

    Node* result = binarySearch(head, 40); //result ini pointer untk mencari data 40
    cout << (result ? "Found" : "Not Found") << endl; // condition ? value_if_true : value_if_false
    return 0;

}