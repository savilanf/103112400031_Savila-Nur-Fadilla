#include "QueuePengiriman.h"

bool isEmpty(QueueEkspedisi Q) {
    return (Q.head == -1 && Q.tail == -1);
}

bool isFull(QueueEkspedisi Q) {
    return (Q.tail == MAX - 1);
}

void createQueue(QueueEkspedisi &Q) {
    Q.head = -1;
    Q.tail = -1;
}

void enQueue(QueueEkspedisi &Q, Paket data) {
    if (isFull(Q)) {
        cout << "Queue penuh!\n";
        return;
    }
    if (isEmpty(Q)) {
        Q.head = Q.tail = 0;
    } else {
        Q.tail++;
    }
    Q.dataPaket[Q.tail] = data;
}

void deQueue(QueueEkspedisi &Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong!\n";
        return;
    }
    for (int i = Q.head; i < Q.tail; i++) {
        Q.dataPaket[i] = Q.dataPaket[i + 1];
    }
    Q.tail--;

    if (Q.tail < Q.head) {
        Q.head = Q.tail = -1;
    }
}

void viewQueue(QueueEkspedisi Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong!\n";
        return;
    }
    cout << "\n--- Data Queue Paket ---\n";
    for (int i = Q.head; i <= Q.tail; i++) {
        cout << i + 1 << ".\n";
        cout << "KodeResi : " << Q.dataPaket[i].KodeResi << endl;
        cout << "NamaPengirim : " << Q.dataPaket[i].NamaPengirim << endl;
        cout << "BeratBarang : " << Q.dataPaket[i].BeratBarang << endl;
        cout << "Tujuan : " << Q.dataPaket[i].Tujuan << endl << endl;
    }
}

int TotalBiayaPengiriman(QueueEkspedisi Q) {
    int total = 0;
    for (int i = Q.head; i <= Q.tail; i++) {
        total += Q.dataPaket[i].BeratBarang * 8250;
    }
    return total;
}