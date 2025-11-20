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
