# <h1 align="center">Laporan Praktikum Modul 8 - Queue</h1>
<p align="center">Savila Nur Fadilla - 103112400031</p>

## Dasar Teori
### A. Queue atau Antrian<br/>
Queue adalah struktur data linier yang menerapkan prinsip FIFO (First In First Out), yaitu elemen pertama yang masuk akan menjadi elemen pertama yang keluar [1].

### B. Komponen dalam queue<br/>
Komponen utama queue terdiri dari:
Front (HEAD) → menunjuk elemen yang akan dikeluarkan
Rear (TAIL) → menunjuk elemen terakhir untuk penambahan
Storage → seperti array atau linked list untuk menyimpan elemen

Hindriani et al. menjelaskan bahwa pada queue berbasis array, front dan rear bergerak sesuai operasi antrian, dan kondisi kosong/penuh ditentukan oleh kedua pointer tersebut [2].

### C. Operasi dalam queue<br/>  
Operasi dasar queue meliputi [3]:
1. enqueue, menambahkan elemen pada rear,
2. dequeue, menghapus elemen pada front,

Penjelasan:
1. insert / enqueue
```C++
/* buat dahulu elemen yang akan disisipkan */
address createElm(int X){
address P = alokasi(X);
P→next = Nil;
return P;
}
/* contoh syntax queue insert */
void queue(address P){
(Q.tail)→next = P;
Q.tail = P;
}
```

2. delete / dequeue:
```C++
/*contoh syntax dequeue */
address dequeue(address P) {
P = Q.head;
Q.head = P→next;
P→next = Nil;
return P;
}
```

### D. Primitif dalam queue<br/>   
Primitif tersimpan pada file *.c dan file *.h [4].

1. Algoritma isEmpty(Q)
Jika Q.head = Nil  
    return true  
else  
    return false

2. Algoritma createQueue(Q)
Q.head ← Nil  
Q.tail ← Nil

3. Algoritma alokasi(X)
Alokasi node baru → P  
Jika P ≠ Nil  
    P.info ← X  
    P.next ← Nil  
return P

4. Algoritma dealokasi(P)
P.next ← Nil  
Hapus node P dari memori

5. Algoritma insertQueue(Q, P)   // Enqueue
Jika Q.head = Nil          // queue kosong  
    Q.head ← P  
    Q.tail ← P  
else                       // queue tidak kosong  
    Q.tail.next ← P  
    Q.tail ← P

6. Algoritma deleteQueue(Q, P)   // Dequeue
Jika Q.head = Nil  
    P ← Nil  
else  
    P ← Q.head  
    Q.head ← Q.head.next  
    P.next ← Nil  
    Jika Q.head = Nil  
        Q.tail ← Nil

7. Algoritma printInfo(Q)
P ← Q.head  
while P ≠ Nil do  
    Tampilkan P.info  
    P ← P.next

8. Algoritma nbList(Q)
count ← 0  
P ← Q.head  
while P ≠ Nil do  
    count ← count + 1  
    P ← P.next  
return count

9. Algoritma delAll(Q)
while Q.head ≠ Nil do  
    deleteQueue(Q, P)  
    dealokasi(P)

### E. Queue representasi tabel<br/>   
### Pengertian queue representasi tabel
Queue representasi tabel adalah implementasi queue menggunakan array berindeks tetap. Posisi head dan tail digunakan untuk menentukan elemen pertama dan terakhir dalam antrian. Operasi insert (enqueue) dan delete (dequeue) dilakukan dengan memodifikasi posisi head dan tail sesuai strategi yang digunakan. Representasi tabel memiliki keterbatasan ukuran (fixed size) sehingga diperlukan manajemen indeks yang efisien agar array dapat dimanfaatkan secara optimal [4].

### Perbedaan
Representasi queue berbasis tabel dapat dibedakan menjadi tiga alternatif utama:
• Alternatif 1: Head tetap dan tail bergerak. Ketika dequeue, seluruh elemen digeser ke kiri.  
• Alternatif 2: Head dan tail keduanya bergerak ke kanan. Tidak ada penggeseran, tetapi ruang kosong di awal tidak dipakai lagi.  
• Alternatif 3: Circular queue, head dan tail bergerak melingkar dengan operasi modulo sehingga seluruh array dapat dimanfaatkan kembali tanpa penggeseran.

### Alternatif 1 – head diam, tail bergerak
Konsep:
Head tetap berada di posisi awal array, sedangkan tail bergerak ke kanan setiap kali enqueue. Saat dequeu, elemen pada head diambil dan seluruh elemen array digeser ke kiri. Implementasi ini sederhana tetapi tidak efisien karena memerlukan penggeseran data setiap kali menghapus elemen.

Primitif:
• isEmpty: queue kosong ketika head = 0 dan tail = 0  
• isFull: queue penuh ketika tail = MaxEl  
• enqueue: jika kosong head = tail = 1, jika tidak tail maju satu langkah lalu data disimpan  
• dequeue: mengambil elemen head dan menggeser seluruh data satu indeks ke kiri  

### Alternatif 2 – head dan tail bergerak
Konsep:
Baik head maupun tail bergerak ke kanan. Setelah enqueue, tail bertambah; setelah dequeue, head bertambah. Tidak ada penggeseran elemen, namun jika tail mencapai indeks maksimum, queue akan dianggap penuh meskipun masih ada ruang kosong di awal array.

Primitif:
• isEmpty: head = 0 dan tail = 0  
• isFull: tail = MaxEl  
• enqueue: jika kosong head = tail = 1, jika tidak tail bertambah  
• dequeue: mengambil elemen head lalu head bertambah. Jika head melewati tail, queue kembali kosong  

### Alternatif 3 – circular queue
Konsep:
Circular queue menggunakan operasi modulo sehingga head dan tail dapat kembali ke indeks awal ketika mencapai ujung array. Dengan cara ini, seluruh elemen array bisa dimanfaatkan tanpa memindahkan data dan tanpa membiarkan ruang kosong tidak terpakai.

Primitif:
• isFull: (tail + 1) mod MaxEl = head  
• enqueue: jika kosong head = tail = 0, jika tidak tail = (tail + 1) mod MaxEl  
• dequeue: mengambil elemen head lalu head = (head + 1) mod MaxEl  
• queue kosong lagi jika head = tail setelah satu elemen tersisa dihapus  

## Guided 

### 1. guided1

### file: queue.h
```C++
#ifndef QUEUE_H
#define QUEUE_H
#define Nil NULL

#include <iostream>
using namespace std;

typedef struct node *address;

struct node{
    int dataAngka;
    address next;
};

struct queue{
    address head;
    address tail;
};

bool isEmpty(queue Q);
void createQueue(queue &Q);
address alokasi(int angka);
void dealokasi(queue &node);

void enQueue(queue &Q, address nodeBaru);
void deQueue(queue &Q);
void updateQueue(queue &Q, int posisi);
void viewQueue(queue Q);
void searchData(queue Q, int data);

#endif
```

### file: queue.cpp
```C++
#include "queue.h"
#include <iostream>

using namespace std;

bool isEmpty(queue Q){
    if(Q.head == Nil){
        return true;
    } else {
        return false;
    }
}

void createQueue(queue &Q){
    Q.head =  Q.tail = Nil;
}

address alokasi(int angka){
    address nodeBaru = new node;
    nodeBaru->dataAngka = angka;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node){
    node->next = Nil;
    delete node;
}

void enQueue(queue &Q, address nodeBaru){
    if(isEmpty(Q) == true){
        Q.head = Q.tail = nodeBaru;
    } else {
        Q.tail->next = nodeBaru;
        Q.tail = nodeBaru;
    }
    cout << "Node " << nodeBaru->dataAngka << " berhasil ditambahkan kedalam queue!" << endl;
}

void deQueue(queue &Q){
    address nodeHapus;
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        nodeHapus = Q.head;
        Q.head = Q.head->next;
        nodeHapus->next = Nil;
        if(Q.head == Nil){
            Q.tail = Nil;
        }
        dealokasi(nodeHapus);
        cout << "node " <<  nodeHapus->dataAngka << " berhasil dihapus dari queue!" << endl;
    }
}

void updateQueue(queue &Q, int posisi){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        if(posisi == 0){
            cout << "Posisi tidak valid!" << endl;
        } else {
            address nodeBantu = Q.head;
            int count = 1;
            bool found = false;
            while(nodeBantu != Nil){
                if(count < posisi){
                    nodeBantu = nodeBantu->next;
                    count++;
                } else if(count == posisi){
                    cout << "Update node poisisi ke-" << posisi << endl;
                    cout << "Masukkan angka : ";
                    cin >> nodeBantu->dataAngka;
                    cout << "Data berhasil diupdate!" << endl;
                    cout << endl;
                    found = true;
                    break;
                }
            }
            if(found == false){
                cout << "Posisi " << posisi << " tidak valid!" << endl;
            }
        }
    }
}

void viewQueue(queue Q){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        address nodeBantu = Q.head;
        while(nodeBantu != Nil){
            cout << nodeBantu->dataAngka << " ";
            nodeBantu = nodeBantu->next;
        }
    }
    cout << endl;
}

void searchData(queue Q, int data){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        address nodeBantu = Q.head;
        int posisi = 1;
        bool found = false;
        cout << "Mencari data " << data << "..." << endl;
        while(nodeBantu != Nil){
            if(nodeBantu->dataAngka == data){
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << endl;
                found = true;
                cout << endl;
                break;
            } else {
                posisi++;
                nodeBantu = nodeBantu->next;
            }
        }
        if(found == false){
            cout << "Data " << data << " tidak ditemukan didalam queue!" << endl;
            cout << endl;
        }
    }
}
```

### file: main.cpp
```C++
#include "queue.h"
#include <iostream>
using namespace std;

int main(){
    queue Q;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createQueue(Q);

    nodeA = alokasi(1);
    nodeB = alokasi(2);
    nodeC = alokasi(3); 
    nodeD = alokasi(4);
    nodeE = alokasi(5);

    enQueue(Q, nodeA);
    enQueue(Q, nodeB);
    enQueue(Q, nodeC);
    enQueue(Q, nodeD);
    enQueue(Q, nodeE);
    cout << endl;

    cout << "--- Queue setelah enQueue ---" << endl;
    viewQueue(Q);
    cout << endl;

    deQueue(Q);
    deQueue(Q);
    cout << endl;

    cout << "--- Queue setelah deQueue 2 kali ---" << endl;
    viewQueue(Q);
    cout << endl;

    updateQueue(Q, 2);
    updateQueue(Q, 1);
    updateQueue(Q, 4);
    cout << endl;

    cout << "--- Queue setelah update ---" << endl;
    viewQueue(Q);
    cout << endl;

    searchData(Q, 4);
    searchData(Q, 9);
    return 0;
}
```
Kode ini merupakan pemrograman bahasa C++ yang mengimplementasikan struktur data queue (antrian) menggunakan Linked List. Setiap elemen queue berbentuk node yang menyimpan dataAngka dan pointer next sebagai penghubung ke elemen berikutnya. Struktur queue hanya menyimpan pointer head (elemen paling depan) dan tail (elemen paling belakang). Ada beberapa operasi penting, yaitu createQueue untuk membuat, isEmpty sebagai pengecekan kondisi kosong, alokasi dan dealokasi untuk membuat dan menghapus node, enQueue untuk menambah data ke belakang antrian, deQueue untuk menghapus data dari depan, updateQueue untuk mengubah nilai pada posisi tertentu, viewQueue untuk menampilkan isi antrian, dan searchData untuk mencari posisi data di dalam queue.

### 2. guided2

### file: queue.h
```C++
#ifndef QUEUE_H
#define QUEUE_H

#define MAX_QUEUE 5

struct Queue{
    int info[MAX_QUEUE];
    int head;
    int tail;
    int count;
};

void createQueue(Queue &Q);
bool isEmpty(Queue Q);
bool isFull(Queue Q);
void enqueue(Queue &Q, int x);
int dequeue(Queue &Q);
void printInfo(Queue Q);
#endif
```

### file: queue.cpp
```C++
#include "queue.h" 
#include <iostream>

using namespace std;

void createQueue(Queue &Q) {
    Q.head = 0; 
    Q.tail = 0; 
    Q.count = 0;
}

bool isEmpty(Queue Q) {
    return Q.count == 0; //Kembalikan true jika jumlah elemen adalah 0
}

bool isFull(Queue Q) {
    return Q.count == MAX_QUEUE; // Kembalikan true jika jumlah elemen sama dengan maks
}

// Definisi prosedur untuk menambahkan elemen (enqueue)
void enqueue(Queue &Q, int x) {
    if (!isFull(Q)) { 
        Q.info[Q.tail] = x; // Masukkan data (x) ke posisi ekor (tail)
        // Pindahkan ekor secara circular (memutar)
        Q.tail = (Q.tail + 1) % MAX_QUEUE; 
        Q.count++; //Tambah jumlah elemen
    } else { 
        cout << "Antrean Penuh!" << endl;
    }
}

//Definisi fungsi untuk menghapus elemen (dequeue)
int dequeue(Queue &Q) {
    if (!isEmpty(Q)) { 
        int x = Q.info[Q.head]; // Ambil data di posisi  (head)
        Q.head = (Q.head + 1) % MAX_QUEUE;
        Q.count--; // Kurangi jumlah elemen
        return x;
    } else {
        cout << "Antrean Kosong!" << endl;
        return -1;
    }
}

// Definisi prosedur untuk menampilkan isi queue 
void printInfo(Queue Q) {
    cout << "Isi Queue: [ ";
    if (!isEmpty(Q)) { 
        int i = Q.head; // Mulai dari head
        int n = 0; //Penghitung elemen yang sudah dicetak
        while (n < Q.count) { // Ulangi sebanyak jumlah elemen
            cout << Q.info[i] << " "; // Cetak info
            i = (i + 1) % MAX_QUEUE; // Geser i secara circular
            n++; // Tambah penghitung
        }
    }
    cout << "]" << endl;
}
```

### file: main.cpp
```C++
#include <iostream>
#include "queue.h"
using namespace std;

//fungsi utama
int main(){
    Queue Q;
    createQueue(Q);
    printInfo(Q);

    cout << "\n Enqueue 3 elemen" << endl;
    enqueue(Q, 5);
    printInfo(Q);
    enqueue(Q, 2);
    printInfo(Q);
    enqueue(Q, 7);
    printInfo(Q);

    cout << "\n Dequeue 1 elemen" << endl;
    cout << "Elemen keluar:" << dequeue(Q) << endl;
    printInfo(Q);

    cout << "\n Enqueue 1 elemen" << endl;
    enqueue(Q, 4);
    printInfo(Q);

    cout << "\n Dequeue 2 elemen" << endl;
    cout << "Elemen keluar:" << dequeue(Q) << endl;
    cout << "Elemen keluar:" << dequeue(Q) << endl;
    printInfo(Q);
    return 0;
}
```
Kode ini merupakan program C++ yang mengimplementasikan struktur data queue berbasis array dengan konsep circular queue. Setiap elemen disimpan dalam array info, sementara posisi head, tail, dan jumlah elemen dicatat di variabel queue. Program menyediakan operasi dasar seperti createQueue untuk membuat, isEmpty dan isFull untuk pengecekan kondisi antrean, enqueue untuk menambahkan data di posisi tail secara melingkar, dequeue untuk mengambil data dari head, serta printInfo untuk menampilkan seluruh elemen queue dengan pergerakan indeks circular. Struktur ini membuat pemakaian memori array lebih efisien tanpa perlu menggeser elemen.

## Unguided

### Buatlah ADT Queue menggunakan ARRAY sebagai berikut di dalam file “queue.h”:
Type infotype: integer
Type Queue: <
info : array [5] of infotype {index array dalam C++
dimulai dari 0}
head, tail : integer
>
procedure CreateQueue (input/output Q: Queue)
function isEmptyQueue (Q: Queue) → boolean
function isFullQueue (Q: Queue) → boolean
procedure enqueue (input/output Q: Queue, input x: infotype)
function dequeue (input/output Q: Queue) → infotype
procedure printInfo (input Q: Queue)

Dalam file "main.cpp":
```C++
int main() {
cout << "Hello World" << endl;
Queue Q;
createQueue(Q);
cout<<"----------------------"<<endl;
cout<<" H - T \t | Queue info"<<endl;
cout<<"----------------------"<<endl;
printInfo(Q);
enqueue(Q,5); printInfo(Q);
enqueue(Q,2); printInfo(Q);
enqueue(Q,7); printInfo(Q);
dequeue(Q); printInfo(Q);
enqueue(Q,4); printInfo(Q);
dequeue(Q); printInfo(Q);
dequeue(Q); printInfo(Q);
return 0;
}
```

### 1. Buatlah implementasi ADT Queue pada file “queue.cpp” dengan menerapkan mekanisme queue Alternatif 1 (head diam, tail bergerak).

### 2. Buatlah implementasi ADT Queue pada file “queue.cpp” dengan menerapkan mekanisme queue Alternatif 2 (head bergerak, tail bergerak).

### 3. Buatlah implementasi ADT Queue pada file “queue.cpp” dengan menerapkan mekanisme queue Alternatif 3 (head dan tail berputar).

### JAWABAN
### file: queue.h
```C++
#ifndef QUEUE_H
#define QUEUE_H

#define MAX_QUEUE 5

typedef int infotype;

struct Queue {
    infotype info[MAX_QUEUE];
    int head;
    int tail;
};

void createQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(Queue Q);

#endif
```

### file: main.cpp
```C++
#include <iostream>
#include "queue.h"

using namespace std;

int main() {
    cout << "Hello World" << endl;
    Queue Q;
    createQueue(Q);
    cout<<"----------------------"<<endl;
    cout<<" H - T \t | Queue info"<<endl;
    cout<<"----------------------"<<endl;
    printInfo(Q);
    enqueue(Q,5); printInfo(Q);
    enqueue(Q,2); printInfo(Q);
    enqueue(Q,7); printInfo(Q);
    dequeue(Q); printInfo(Q);
    enqueue(Q,4); printInfo(Q);
    dequeue(Q); printInfo(Q);
    dequeue(Q); printInfo(Q);
    dequeue(Q); printInfo(Q);

    return 0;
}
```

### file: queue_1.cpp
### NOMOR 1 queue alternatif 1 (head diam, tail bergerak)
```C++
#include "queue.h"
#include <iostream>
using namespace std;

// queue alternatif 1 (head diam, tail bergerak)

void createQueue(Queue &Q) {
    // inisialisasi queue kosong, head dan tail di -1
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q) {
    // queue dianggap kosong kalau head dan tail sama-sama -1
    return Q.head == -1 && Q.tail == -1;
}

bool isFullQueue(Queue Q) {
    // queue penuh kalau tail sudah di index terakhir array/mencapai Max-1
    return (Q.tail == MAX_QUEUE - 1);
}

void enqueue(Queue &Q, infotype x) {
    // cek apakah queue penuh
    if (isFullQueue(Q)) { // kalau penuh
        cout << "Queue penuh!" << endl;
        return;
    }
    // kalau masih kosong, head dan tail = 0
    if (isEmptyQueue(Q)) {
        Q.head = 0;
        Q.tail = 0;
    } else {
        // kalau sudah ada isinya, geser tail ke kanan
        Q.tail++;
    }
    // simpan x di tail
    Q.info[Q.tail] = x;
}

infotype dequeue(Queue &Q) {
    // cek kalau queue kosong
    if (isEmptyQueue(Q)) {
        cout << "Queue kosong!" << endl;
        return -1; // penanda kosong
    }
    infotype x = Q.info[Q.head]; // ambil data paling depan (sesuai konsep queue: FIFO)
    // kalau cuma ada 1 elemen, setelah dihapus jadi kosong lagi
    if (Q.head == Q.tail) {
        Q.head = -1;
        Q.tail = -1;
    } else {
        // geser semua elemen ke kiri, karena head diam
        for (int i = Q.head; i < Q.tail; i++) {
            Q.info[i] = Q.info[i + 1];
        }
        // tail mundur karena elemen bergeser
        Q.tail--;
    }
    return x; // kembalikan x
}

void printInfo(Queue Q) {
    // tampilin posisi head dan tail
    cout << Q.head << " - " << Q.tail << " \t | ";
    // kalau kosong
    if (isEmptyQueue(Q)) {
        cout << "empty queue" << endl;
        return;
    }
    // cetak semua data dari head sampai tail
    for (int i = Q.head; i <= Q.tail; i++) {
        cout << Q.info[i] << " ";
    }
    cout << endl;
}
```

### file: queue_2.cpp
### NOMOR 2 queue alternatif 2 (head bergerak, tail bergerak)
```C++
#include "queue.h"
#include <iostream>
using namespace std;

// queue alternatif 2 (head bergerak, tail bergerak)

void createQueue(Queue &Q) {
    // inisialisasi queue kosong, head dan tail di -1
    Q.head = -1;
    Q.tail = -1;  
}

bool isEmptyQueue(Queue Q) {
    // queue dianggap kosong kalau head dan tail sama-sama -1
    return (Q.head == -1 && Q.tail == -1); 
}

bool isFullQueue(Queue Q) {
    // queue penuh kalau tail sudah di index terakhir array/mencapai Max-1, karena tidak circular
    return (Q.tail == MAX_QUEUE - 1);
}

void enqueue(Queue &Q, infotype x) {
    // cek apakah queue penuh
    if (isFullQueue(Q)) {
        cout << "queue penuh!" << endl;
        return;
    }

    if (isEmptyQueue(Q)) {
        // kalau masih kosong, head dan tail = 0
        Q.head = 0;
        Q.tail = 0;
    } else {
        // kalau sudah ada isinya, geser tail ke kanan
        Q.tail++;
    }
    // simpan x di tail
    Q.info[Q.tail] = x; 
}

infotype dequeue(Queue &Q) {
    // cek kalau queue kosong
    if (isEmptyQueue(Q)) {
        cout << "queue kosong!" << endl;
        return -1;   // penanda kosong
    }
    infotype x = Q.info[Q.head];   // ambil data paling depan (sesuai konsep queue: FIFO)
    // kalau cuma ada 1 elemen, setelah dihapus jadi kosong lagi
    if (Q.head == Q.tail) {
        Q.head = -1;
        Q.tail = -1;
    } else {
        // head maju ke kanan, data lama tidak digeser
        Q.head++;
    }
    return x;   // kembalikan x
}

void printInfo(Queue Q) {
    cout << Q.head << " - " << Q.tail << " \t | ";

    if (isEmptyQueue(Q)) {
        cout << "empty queue" << endl;
        return;
    }
    // print isi queue dari head sampai tail
    for (int i = Q.head; i <= Q.tail; i++) {
        cout << Q.info[i] << " ";
    }
    cout << endl;
}
```

### file: queue_3.cpp
### NOMOR 3 queue alternatif 3 (circular queue: head & tail berputar)
```C++
#include "queue.h"
#include <iostream>
using namespace std;

// queue alternatif 3 (circular queue: head & tail berputar)

void createQueue(Queue &Q) {
    // inisialisasi queue kosong, head dan tail di -1
    Q.head = -1;   
    Q.tail = -1;  
}

bool isEmptyQueue(Queue Q) {
    // queue dianggap kosong kalau head dan tail sama-sama -1
    return (Q.head == -1 && Q.tail == -1);
}

bool isFullQueue(Queue Q) {
    // queue penuh kalau posisi tail berikutnya = head
    // pake modulo biar circular
    if (isEmptyQueue(Q)) return false;         
    return ((Q.tail + 1) % MAX_QUEUE == Q.head);
}

void enqueue(Queue &Q, infotype x) {
    // cek apakah queue penuh
    if (isFullQueue(Q)) {
        cout << "queue penuh!" << endl;
        return;
    }
    if (isEmptyQueue(Q)) {
        // kalau masih kosong, head dan tail = 0
        Q.head = 0;
        Q.tail = 0;
    } else {
        // tail circular
        Q.tail = (Q.tail + 1) % MAX_QUEUE;
    }
    // simpan x di tail
    Q.info[Q.tail] = x;
}

infotype dequeue(Queue &Q) {
    // cek kalau queue kosong
    if (isEmptyQueue(Q)) {
        cout << "queue kosong!" << endl;
        return -1;   // penanda kosong
    }
    infotype x = Q.info[Q.head];   // ambil data paling depan
    // kalau cuma ada 1 elemen, setelah dihapus jadi kosong lagi
    if (Q.head == Q.tail) {
        Q.head = -1;
        Q.tail = -1;
    } else {
        // head circular
        Q.head = (Q.head + 1) % MAX_QUEUE;
    }
    return x;   // kembalikan x
}

void printInfo(Queue Q) {
    cout << Q.head << " - " << Q.tail << " \t | ";

    if (isEmptyQueue(Q)) {
        cout << "empty queue" << endl;
        return;
    }
    // looping dari head ke tail sambil muter
    int i = Q.head;
    while (true) {
        cout << Q.info[i] << " ";

        if (i == Q.tail) break;           // berhenti kalau sudah sampai tail

        i = (i + 1) % MAX_QUEUE;          // maju melingkar
    }

    cout << endl;
}
```

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/savilanf/103112400031_Savila-Nur-Fadilla/blob/main/Pertemuan8_Modul8/output/output1.png)

Kode dengan bahasa pemrograman C++ yang menggunakan Queue atau antrian alternatif 1 dengan konsep head tetap, tail yang bergerak. Queue dibuat kosong dengan head = -1 dan tail = -1. Fungsi isEmptyQueue dan isFullQueue dipakai untuk mengecek apakah queue kosong atau sudah penuh. Saat enqueue, jika queue kosong maka head–tail jadi 0; kalau sudah ada isinya, tail cukup digeser satu langkah ke kanan lalu data disimpan. Pada dequeue, elemen paling depan diambil; jika tinggal satu elemen maka queue kembali kosong, dan kalau masih ada elemen lain semuanya digeser ke kiri karena head tidak pernah bergerak. Terakhir, printInfo menampilkan posisi head–tail serta isi queue, atau menampilkan pesan “empty queue” jika kosong.

##### Output 2
![Screenshot Output Unguided 2_1](https://github.com/savilanf/103112400031_Savila-Nur-Fadilla/blob/main/Pertemuan8_Modul8/output/output2.png)

Kode dengan bahasa pemrograman C++ yang menggunakan Queue atau antrian alternatif 2, yaitu mekanisme di mana head dan tail sama-sama bergerak tanpa pergeseran elemen. Queue dimulai kosong (head = tail = -1). Pada enqueue, jika queue kosong maka head dan tail di-set ke 0, dan jika tidak, tail cukup maju satu langkah untuk menambah data baru. Pada dequeue, elemen di posisi head diambil sesuai prinsip FIFO; jika hanya satu elemen maka queue kembali kosong, tetapi jika masih ada elemen lain, head maju ke kanan tanpa menggeser isi array. Fungsi isEmptyQueue dan isFullQueue mengecek kondisi queue, sedangkan printInfo menampilkan posisi head–tail dan isi queue dari head hingga tail, atau menampilkan “empty queue” jika kosong.

##### Output 3
![Screenshot Output Unguided 3_1](https://github.com/savilanf/103112400031_Savila-Nur-Fadilla/blob/main/Pertemuan8_Modul8/output/output3.png)

Kode dengan bahasa pemrograman C++ yang menggunakan Queue atau antrian alternatif 3 atau Circular Queue, yaitu queue yang head dan tail-nya berputar (bisa memutari array menggunakan operasi modulo). Queue diawali kosong dengan head = tail = –1. Saat enqueue, jika queue penuh (posisi tail berikutnya bertemu head), proses dihentikan; jika kosong maka head dan tail = 0, kalau tidak tail cukup bergerak ke posisi (tail + 1) % MAX_QUEUE. Pada dequeue, data di head diambil; jika hanya satu elemen maka queue kembali kosong, kalau masih ada elemen lain maka head digeser melingkar dengan (head + 1) % MAX_QUEUE. Fungsi printInfo akan mencetak posisi head–tail dan isi queue dengan loop melingkar dari head sampai tail.

## Kesimpulan
Laporan Praktikum Struktur Data Modul 8 ini menggunakan bahasa pemrograman C++ dan membahas penerapan struktur data Queue (antrean) dengan pendekatan ADT (Abstract Data Type). Queue bekerja dengan prinsip FIFO (First In First Out), yaitu elemen yang pertama masuk akan dikeluarkan lebih dulu. Dalam praktikum ini, mahasiswa dilatih memahami cara membuat queue, menambah elemen (enqueue), menghapus elemen (dequeue), menampilkan isi antrean, serta melakukan operasi lain seperti pencarian atau pembaruan data. Penerapan ADT membuat program lebih terstruktur, efisien, dan mudah dikembangkan untuk pengolahan data yang lebih kompleks.

## Referensi 
[1] Trijayanti, A., Aulia, I., Khairunisa, N., Asyrof, F., & Gunawan, I. (2021). Implementasi Struktur Data Antrian Queue dalam Sistem Penjadwalan Proses. Jurnal JUPTI. 

[2] Hindriani, N., Narwen, & Yozza, H. (2015). Implementasi Antrian dengan Menggunakan Array. Jurnal Matematika Universitas Andalas.

[3] Sarevska, M. (2024). Data Structures Comparison for Element Deletion Including Queues. WSEAS Transactions on Communications.

[4] Informatics Laboratory. (n.d.). *Modul 8 – Queue*. Program Studi Teknik Informatika, Telkom University.