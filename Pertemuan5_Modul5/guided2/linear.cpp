#include <iostream>
using namespace std;

//definisi node
struct Node{ //memiliki 2 bagian (data dan pointer)
    int data;
    Node* next;
};

//fungsi pencarian linear
Node* linearSearch(Node* head, int key){
    Node* current = head;
    while(current != nullptr){ //selama masih ada node
        if(current -> data == key) return current; //jika data ketemu
        current = current -> next; //pindah node berikutnya
    }
    return nullptr; //jika data tidak ditemukan
}

//prosedur menambah node
void append(Node*& head, int value){ //parameter head adalah refrence ke pointer head
    Node* newNode = new Node{value, nullptr}; //membuat pointer baru
    if(!head) head = newNode; //jika head null, head diisi node baru
    else{
        Node* temp = head; //mulai dari head
        while(temp->next) temp = temp->next; //pindah ke node terakhir
        temp->next = newNode; //sambungkan node terakhir ke node baru
    }
}

int main(){
    Node* head = nullptr;//inisialilasi head sebagai null
    append(head, 10); append(head, 20); append(head, 30); //menambah node
    Node* result = linearSearch(head, 20); //result mencari node dengan data 20
    cout << (result ? "Found" : "Not found") << endl; 
    //condition ? value_if_true : value_if_false;
    return 0;

}