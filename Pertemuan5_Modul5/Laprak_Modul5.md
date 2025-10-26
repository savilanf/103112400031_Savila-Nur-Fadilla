# <h1 align="center">Laporan Praktikum Modul 5 - Singly Linked List (Bagian Kedua)</h1>
<p align="center">Savila Nur Fadilla - 103112400031</p>

## Dasar Teori
### A. Searching List<br/>   
Searching merupakan operasi dasar list dengan melakukan aktivitas pencarian terhadap node tertentu. Proses ini berjalan dengan mengunjungi setiap node dan berhenti setelah node yang dicari ketemu. Dengan melakukan operasi searching, operasi-operasi seperti insert after, delete after, dan update akan lebih mudah.

Semua fungsi dasar di atas merupakan bagian dari ADT dari single linked list, dan aplikasi pada bahasa pemrograman C, semua ADT tersebut tersimpan dalam file *.c dan file *.h [1]. 

*Contoh sintaks:*
```C++
Node* search(Node* head, int x) {
    Node* p = head;
    while (p != NULL) {
        if (p->data == x)
            return p;
        p = p->next;
    }
    return NULL;
}
``` 
### B. Update List<br/>
Merupakan operasi dasar pada list yang digunakan untuk meng-update data yang ada di dalam list.
Dengan operasi update ini kita dapat meng-update data-data node yang ada di dalam list.
Proses update biasanya diawali dengan proses pencarian terhadap data yang akan di-update [2].

*Contoh sintaks:*
```C++
void updateNode(List &L, string key, string newNama, string newNIM) {
    address p = L.first;
    bool found = false;

    // proses pencarian node yang ingin di-update
    while (p != NULL) {
        if (p->info.nim == key) { // misalnya kita cari berdasarkan NIM
            p->info.nama = newNama;
            p->info.nim = newNIM;
            found = true;
            cout << "Data berhasil diupdate.\n";
            break;
        }
        p = p->next;
    }

    if (!found) {
        cout << "Data dengan NIM " << key << " tidak ditemukan.\n";
    }
}
```

### C. Create List<br/>  
Proses pembuatan list dilakukan dengan *menginisialisasi pointer head ke nilai NULL* sebagai tanda bahwa list masih kosong. Proses ini penting untuk mencegah error saat dilakukan operasi lain seperti insert atau delete. Alokasi memori dilakukan secara dinamis menggunakan pointer [3].

*Contoh sintaks:*
```C++
struct Node {
    int data;
    Node* next;
};

void createList(Node*& head) {
    head = NULL;  // list kosong
}
```

### D. Insert List<br/>   
Operasi insert bisa dilakukan di tiga posisi, yaitu di awal, di tengah (setelah node tertentu), dan di akhir. Operasi ini menambahkan node baru dengan cara mengatur ulang pointer agar node baru terhubung ke node lain. Waktu eksekusi untuk insert di awal lebih cepat karena tidak perlu traversal [4].

*Contoh sintaks:*
```C++
void insertFirst(Node*& head, int x) {
    Node* newNode = new Node;
    newNode->data = x;
    newNode->next = head;
    head = newNode;
}

void insertLast(Node*& head, int x) {
    Node* newNode = new Node;
    newNode->data = x;
    newNode->next = NULL;
    if (head == NULL)
        head = newNode;
    else {
        Node* p = head;
        while (p->next != NULL)
            p = p->next;
        p->next = newNode;
    }
}
```

### E. Delete List<br/>   
Operasi delete dilakukan dengan cara menghapus node dari list dan memastikan pointer tidak tertinggal (dangling pointer). Operasi yang umum dilakukan yaitu deleteFirst() dan deleteLast(). Selain itu, penting juga untuk membebaskan memori agar tidak terjadi memory leak [5].

*Contoh sintaks:*
```C++
void deleteFirst(Node*& head) {
    if (head != NULL) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

void deleteLast(Node*& head) {
    if (head == NULL) return;
    if (head->next == NULL) {
        delete head;
        head = NULL;
    } else {
        Node* p = head;
        while (p->next->next != NULL)
            p = p->next;
        delete p->next;
        p->next = NULL;
    }
}
```

### F. View List<br/>   
Proses view atau traversal dilakukan dengan menelusuri setiap node dari head hingga node terakhir (NULL). Tujuan dari operasi ini adalah untuk menampilkan seluruh isi list serta memeriksa apakah data sudah tersimpan dengan benar [6].

*Contoh sintaks:*
```C++
void viewList(Node* head) {
    Node* p = head;
    while (p != NULL) {
        cout << p->data << " -> ";
        p = p->next;
    }
    cout << "NULL" << endl;
}
```

## Guided 

### guided1

### file: listBuah.h
```C++
//header guard digunakan untuk mencegah frile header yang sama
#ifndef LISTBUAH_H
#define LISTBUAH_H
#define Nil NULL

#include <iostream>
using namespace std;
struct buah{
    string nama;
    int jumlah;
    float harga;
};

typedef buah dataBuah; //memberikan nama alias databuah untuk struct buah
typedef struct node *address; // mendefinisikan address sebagai pointer ke struct node

struct node{ //node untuk isi linked listnya, isi setiap node adalah data dan pointer
    dataBuah isidata;
    address next;
};

struct linkedlist{ //ini linked listnya
    address first;
};

//semua function dan prosedur yang dipakai
//materi modul 4
bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, int jumlah, float harga);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &list, address nodeBaru);
void insertAfter(linkedlist &list, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);
void delFirst(linkedlist &List);
void delLast(linkedlist &List);
void delAfter(linkedlist &List, address nodeHapus, address nodePrev);
int nbList(linkedlist List);
void deleteList(linkedlist &List);

//materi modul 5
void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address Prev);

#endif
```

### file: listBuah.cpp
```C++
#include "listBuah.h"
#include <iostream>
using namespace std;

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedlist &List) {
    List.first = Nil;
}
//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, int jumlah, float harga) { 
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jumlah = jumlah; 
    nodeBaru->isidata.harga = harga;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru) {
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

//prosedur-prosedur untuk delete / menghapus node yang ada didalam list
void delFirst(linkedlist &List){
    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "Node pertama berhasil terhapus!" << endl;
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedlist &List){
    address nodeHapus, nodePrev;
    if(isEmpty(List) == false){
        nodeHapus = List.first;
        if(nodeHapus->next == Nil){
            List.first->next = Nil;
            dealokasi(nodeHapus);
        } else { 
            while(nodeHapus->next != Nil){
                nodePrev = nodeHapus; 
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil; 
            dealokasi(nodeHapus);
        }
        cout << "Node terakhir berhasil terhapus!" << endl;
    } else {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedlist &List, address nodeHapus, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else { //jika list tidak kosong
        if (nodePrev != Nil && nodePrev->next != Nil) { 
            nodeHapus = nodePrev->next;       
            nodePrev->next = nodeHapus->next;  
            nodeHapus->next = Nil;         
            dealokasi(nodeHapus);
            cout << "Node setelah node " << nodePrev->isidata.nama << " berhasil terhapus!" << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedlist List) {
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

//function untuk menampilkan jumlah node didalam list
int nbList(linkedlist List) {
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next; 
    }
    return count;
}

//prosedur untuk menghapus list (menghapus semua node didalam list)
void deleteList(linkedlist &List){
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while(nodeBantu != Nil){
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus); 
    }
    List.first = Nil; 
    cout << "List berhasil terhapus!" << endl;
}

/*----- MATERI PERTEMUAN 5 - SINGLY LINKED LIST (BAGIAN KEDUA) - PART 1 (UPDATE) -----*/
//prosedur-prosedur untuk melakukan update data node
void updateFirst(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama buah : ";
        cin >> List.first->isidata.nama;
        cout << "Jumlah : ";
        cin >> List.first->isidata.jumlah;
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateLast(linkedlist List){
    if (isEmpty(List) == true) {
        cout << "List Kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        cout << "masukkan update data node terakhir : " << endl;
        cout << "Nama buah : ";
        cin >> nodeBantu->isidata.nama;
        cout << "Jumlah : ";
        cin >> nodeBantu->isidata.jumlah;
        cout << "Harga : ";
        cin >> nodeBantu->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateAfter(linkedlist List, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodePrev != Nil && nodePrev->next != Nil){
            address nodeBantu = nodePrev->next;
            cout << "masukkan update data node setelah node " << nodePrev->isidata.nama << " : " << endl;
            cout << "Nama buah : ";
            cin >> nodeBantu->isidata.nama;
            cout << "Jumlah : ";
            cin >> nodeBantu->isidata.jumlah;
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}
```

### file: main.cpp
```C++
#include "listBuah.h"
#include <iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE;
    createList(List);

    dataBuah dtBuah;
    nodeA = alokasi("Jeruk", 100, 3000);
    nodeB = alokasi("Apel", 75, 4000);
    nodeC = alokasi("Pir", 87, 5000);
    nodeD = alokasi("Semangka", 43, 11500);
    nodeE = alokasi("Durian", 15, 31450);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    // A C D B E
    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);
    cout << "Jumlah node: " << nbList(List) << endl;
    cout << endl;

    updateFirst(List);
    updateLast(List);
    updateAfter(List, nodeD);

    cout << "--- ISI LIST SETELAH DILAKUKAN UPDATE ---" << endl;
    printList(List);
    cout << "Jumlah node: " << nbList(List) << endl;
    cout << endl;
    return 0;
}
```
Kode dengan bahasa pemrograman C++ untuk membuat, menampilkan, dan memperbarui isi Linked List yang menyimpan data buah. Struktur buah berisi nama, jumlah, dan harga buah. Prosedur alokasi digunakan untuk membuat node baru, insertFirst insertAfter dan insertLast untuk menambah node di berbagai posisi, sedangkan printList menampilkan seluruh isi list. Selain itu, terdapat fungsi updateFirst, updateLast dan updateAfter untuk memperbarui data pada node tertentu.  Program utama membuat list berisi data buah (Jeruk, Apel, Pir, Semangka, Durian), menampilkan isi list sebelum dan sesudah dilakukan pembaruan, serta menghitung jumlah node yang ada.

### guided2 (linear search)

```C++
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
```

Kode dengan bahasa pemrograman C++ untuk membuat dan menampilkan isi Linked List serta menerapkan Linear Search. Struktur Node berisi data dan pointer next. Prosedur append digunakan untuk menambah node baru di akhir list, sedangkan fungsi linearSearch digunakan untuk mencari data tertentu dengan menelusuri setiap node secara berurutan. Program utama membuat list berisi (10, 20, 30), lalu mencari data bernilai 20 dan menampilkan hasilnya di layar.

### guided2 (binary search)

```C++
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

    Node* result = binarySearch(head, 0); //result ini pointer untk mencari data 40
    cout << (result ? "Found" : "Not Found") << endl; // condition ? value_if_true : value_if_false
    return 0;

}
```

Kode dengan bahasa pemrograman C++ untuk mengelola data mahasiswa menggunakan singly linked list. Data mahasiswa berupa nama, NIM, dan umur disimpan dalam node yang saling terhubung. Program membuat list kosong, menambahkan beberapa node, menampilkan isi list, menghitung jumlah data, menghapus node tertentu, dan menghapus seluruh isi list. Fungsi dan prosedur yang digunakan antara lain createList, insertFirst, insertAfter, insertLast, printList, nbList, delFirst, delAfter, delLast, dan deleteList.

## Unguided 

### 1. Implementasikan program C++ yang menggunakan algoritma Binary Search pada Linked List untuk mencari elemen tertentu. Program harus mampu:
1. Membuat linked list dengan menambahkan node di akhir
2. Mengimplementasikan binary search pada linked list
3. Menampilkan detail proses pencarian dan hasil akhir
Petunjuk Tugas 1:
• Gunakan struktur Node dengan data integer dan pointer next
• Implementasikan fungsi append() untuk menambah node
• Implementasikan fungsi binarySearch() yang mengembalikan pointer ke node yang ditemukan
• Data dalam linked list harus terurut (ascending) untuk binary search bekerja dengan benar
• Tampilkan langkah-langkah pencarian dan posisi tengah setiap iterasi
• Program utama harus membuat linked list dengan minimal 5 elemen dan melakukan pencarian

```C++
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
```
### Output Unguided 1

##### Output
![Screenshot Output Unguided 1_1](https://github.com/savilanf/103112400031_Savila-Nur-Fadilla/blob/main/Pertemuan5_Modul5/output/output-unguided1.png)

Kode dengan bahasa pemrograman C++ untuk membuat dan menampilkan isi Linked List serta menerapkan Binary Search. Struktur Node berisi data dan pointer next. Prosedur append menambah node di akhir list, prosedur printList menampilkan isi list, dan fungsi binarySearch mencari data dengan membagi list menjadi dua bagian hingga data ditemukan atau habis. Program utama membuat list berisi (10, 20, 30, 40, 50), lalu , mencari serta menampilkan proses dan hasil pencarian nilai tertentu (di soal 40 dan 25).

### 2. Implementasikan program C++ yang menggunakan algoritma Linear Search pada Linked List untuk mencari elemen tertentu. Program
harus mampu:
1. Membuat linked list dengan menambahkan node di akhir
2. Mengimplementasikan linear search pada linked list
3. Menampilkan detail proses pencarian dan hasil akhir
Petunjuk Tugas 2:
• Gunakan struktur Node dengan data integer dan pointer next
• Implementasikan fungsi append() untuk menambah node
• Implementasikan fungsi linearSearch() yang mengembalikan pointer ke node yang ditemukan
• Data dalam linked list tidak perlu terurut untuk linear search
• Tampilkan setiap langkah pencarian dan node yang sedang diperiksa
• Program utama harus membuat linked list dengan minimal 3 elemen dan melakukan pencarian

```C++
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
```

### Output Unguided 2

##### Output
![Screenshot Output Unguided 2_1](https://github.com/savilanf/103112400031_Savila-Nur-Fadilla/blob/main/Pertemuan5_Modul5/output/output-unguided2.png)

Kode dengan bahasa pemrograman C++ untuk membuat dan menampilkan isi Linked List serta menerapkan Linear Search. Struktur Node berisi data dan pointer next. Prosedur append menambah node di akhir list, prosedur printList menampilkan isi list, dan fungsi linearSearch mencari data secara berurutan. Program utama membuat list berisi (10, 20, 30, 40, 50), lalu mencari dan menampilkan hasil pencarian nilai (di soal 30 dan 25) beserta prosesnya.

##### Kesimpulan
Kesimpulan modul 5 ini ada modul 5 ini adalah linear search dan binary search merupakan dua metode pencarian data yang memiliki cara kerja berbeda. Linear search melakukan pencarian secara berurutan dari awal hingga akhir, sedangkan binary search membagi data menjadi dua bagian untuk mempercepat proses pencarian. Binary search lebih efisien karena hanya memeriksa sebagian kecil data pada setiap langkah, namun metode ini hanya bisa digunakan jika data sudah terurut. Sementara itu, penerapan binary search pada linked list memerlukan logika tambahan untuk menemukan elemen tengah, sehingga tidak secepat pada array. Kalau linear itu bisa lebih lama karena mencari data satu satu sampai ketemu.

## Referensi 

[1] Informatics Laboratory. (n.d.). *Modul 5 – Singly Linked List (Bagian Kedua)*. Program Studi Teknik Informatika, Telkom University.

[2] Informatics Laboratory. (n.d.). *Modul 4 – Singly Linked List (Bagian Pertama)*. Program Studi Teknik Informatika, Telkom University.

[3] IJCA (2018). Data Structure Implementation: Singly Linked List Using Dynamic Memory Allocation. International Journal of Computer Applications, Vol. 179, No. 41. Diakses dari https://www.researchgate.net/publication/329412511_Data_Structure_Implementation_Singly_Linked_List_using_Dynamic_Memory_Allocation  

[4] IJCSMC (2022). A New Vista of Performing Insertion and Deletion in Linked Lists. International Journal of Computer Science and Mobile Computing, Vol. 11, Issue 7. Diakses dari https://ijcsmc.com/docs/papers/July2022/V11I7202208.pdf  

[5] IJIRCCE (2017). Enhanced Deletion Operation in Linked List Data Structure. International Journal of Innovative Research in Computer and Communication Engineering, Vol. 5, Issue 4. Diakses dari https://ijircce.com/upload/2017/april/140_Enhanced.pdf  

[6] IJACSA (2021). Visualizing Data Structures: A Study on Linked List Traversal. International Journal of Advanced Computer Science and Applications, Vol. 12, No. 9. Diakses dari https://thesai.org/Publications/ViewPaper?Volume=12&Issue=9&Code=IJACSA&SerialNo=58 