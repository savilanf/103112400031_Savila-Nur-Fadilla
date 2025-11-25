#ifndef STACKMAHASISWA_H
#define STACKMAHASISWA_H

#include <iostream>
using namespace std;

const int MAX = 10;

struct Mahasiswa {
    string NIM;
    string Nama;
    float NilaiTugas;
    float NilaiUTS;
    float NilaiUAS;
};

struct StackMahasiswa {
    Mahasiswa data[MAX];
    int top;
};

void CreateStack(StackMahasiswa &S);
bool isEmpty(const StackMahasiswa &S);
bool isFull(const StackMahasiswa &S);
void Push(StackMahasiswa &S, Mahasiswa m);
void Pop(StackMahasiswa &S);
void View(const StackMahasiswa &S);
void Update(StackMahasiswa &S, int posisi, Mahasiswa baru);

float HitungNilaiAkhir(const Mahasiswa &m);
float MaxNilaiAkhir(const StackMahasiswa &S);

#endif