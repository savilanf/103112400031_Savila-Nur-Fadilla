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
