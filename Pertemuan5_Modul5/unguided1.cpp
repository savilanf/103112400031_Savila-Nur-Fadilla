#include <iostream>
using namespace std;

//struct node
struct Node {
    int data; //data tipenya integer
    Node* next; //pointer ke node berikutnya (makannya next, ada pointernya*)
};

//fungsi untuk menambah node di akhir list
void append(Node*& head, int value) { //parameter head adalah rederensi ke pointer head //value data yang mau dimasukin
    Node* newNode = new Node{value, nullptr}; //alokasi memori untuk node baru
    if (!head) //jika head null, head diisi node baru
        head = newNode; //head diisi node baru
    else {
        Node* temp = head; //mulai dari head
        while (temp->next)
            temp = temp->next; //pindah ke node berikutnya sampai ketemu node terakhir
        temp->next = newNode; //node terakhir dihubungkan ke node baru
    }
}

//cari node tengah antara start dan end
Node* getMiddle(Node* start, Node* end) {
    if (start == nullptr) return nullptr; //kalo listnya kosong langsung keluar

    Node* slow = start; //pointer slow jalan pelan (1 langkah)
    Node* fast = start; //pointer fast jalan cepet (2 langkah)

    //loop buat gerakin dua pointer, berhenti kalo fast udah nyampe atau mau nabrak 'end'
    while (fast != end && fast->next != end) {
        slow = slow->next;         //slow maju 1 langkah
        fast = fast->next->next;   //fast maju 2 langkah (biar dapet tengahnya)
    }

    return slow; //pas loop berhenti, slow udah di posisi tengah, tinggal dikembalikan
}

//binary search pada linked list
Node* binarySearch(Node* head, int key) {
    Node* start = head;   //penanda awal linked list
    Node* end = nullptr;  //penanda akhir (belum ditentuin di awal) MAKANNYA NULL
    int iter = 1;         //buat ngitung iterasi, biar keliatan prosesnya

    cout << "\nProses Pencarian:\n";

    //selama masih ada elemen yang bisa dibandingin
    while (start != end && start != nullptr) {
        Node* mid = getMiddle(start, end); //cari node tengah dari start sampe end
        if (!mid) break; //kalo ga nemu tengah (mungkin udah abis), ya keluar aja

        cout << "Iterasi " << iter++ << ": Mid = " << mid->data << " (indeks tengah)";

        //kalau datanya sama, langsung berhenti (berarti udah ketemu)
        if (mid->data == key) {
            cout << " -> DITEMUKAN!\n";
            cout << "\nHasil: Nilai " << key << " DITEMUKAN pada linked list!\n";
            cout << "Alamat node : " << mid << endl;         //alamat node-nya
            cout << "Data node   : " << mid->data << endl;   //isi datanya
            if (mid->next)
                cout << "Node berikutnya : " << mid->next->data << endl; //node setelahnya kalo ada
            else
                cout << "Node berikutnya : NULL\n"; //kalo udah terakhir
            return mid; //keluar dari fungsi, karena udah ketemu
        }

        //kalo data tengah lebih kecil dari yang dicari, pindah ke kanan (setelah mid)
        else if (mid->data < key) {
            cout << " -> Cari di bagian kanan\n";
            start = mid->next; //mulai dari node setelah mid
        }

        //kalo data tengah lebih besar dari yang dicari, pindah ke kiri (sebelum mid)
        else {
            cout << " -> Cari di bagian kiri\n";
            end = mid; //batas kanan digeser ke posisi mid
        }

        //tambahan biar loop ga terus-terusan
        //kalo start udah sama dengan end, atau udah ngelewatin batas, berarti ga ada lagi yang bisa dicek
        if (start == end || (start && start->next == end))
            break;
    }

    //kalo sampai sini, berarti data yang dicari ga ada
    cout << "Tidak ada elemen tersisa\n";
    cout << "\nHasil: Nilai " << key << " TIDAK DITEMUKAN dalam linked list!\n";
    return nullptr;
}

//cetak linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data;
        if (temp->next) cout << " -> ";
        temp = temp->next;
    }
    cout << " -> NULL\n";
}

int main() {
    Node* head = nullptr;
    append(head, 10);
    append(head, 20);
    append(head, 30);
    append(head, 40);
    append(head, 50);
    append(head, 60);

    cout << "BINARY SEARCH PADA LINKED LIST\n";
    cout << "Linked List yang dibuat: ";
    printList(head);

    //pencarian pertama
    cout << "Mencari nilai: " << 40 << endl;
    Node* result = binarySearch(head, 40);
    cout << endl;

    //pencarian kedua (nilai tidak ada)
    cout << "Mencari nilai: " << 25 << endl;
    result = binarySearch(head, 25);
    return 0;
}
