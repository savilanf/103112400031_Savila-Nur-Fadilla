# <h1 align="center">Laporan Praktikum Modul 3 - Abstract Data Type (ADT)</h1>
<p align="center">Savila Nur Fadilla - 103112400031</p>

## Dasar Teori
### A. Konsep Dasar<br/>
ADT adalah sebuah tipe data yang didefinisikan melalui operasi-operasi yang dapat dilakukan pada data tersebut dan aturan perilakunya (law/axioms). Representasi internal (bagaimana data disimpan) disembunyikan dari pengguna — pengguna hanya berinteraksi lewat antarmuka operasi [1].

### B. Tipe Data Primitif dan Kompotif<br/>
Menurut Cook (1990), ADT merupakan tipe data buatan pengguna yang menyerupai tipe data primitif, tetapi memiliki operasi dan perilaku yang didefinisikan sendiri [2].

#### Kategori tipe data:
#### 1. Tipe Data Primitif (Primitive Data Type)
Merupakan tipe dasar yang sudah disediakan oleh bahasa pemrograman, misalnya:
int, float, double, char, bool.
Tipe-tipe ini digunakan untuk menyimpan nilai sederhana, seperti angka dan karakter.
#### 2. Tipe Data Komposit (Composite / Non-Primitif)
Tipe yang dibentuk dari satu atau lebih tipe data primitif.
Contoh:
array → sekumpulan elemen bertipe sama
struct → pengelompokan beberapa variabel dengan tipe berbeda
class (C++) → perluasan dari struct yang dapat memiliki fungsi anggota

ADT termasuk dalam kategori tipe data komposit, karena ia menyatukan data dan operasi menjadi satu kesatuan yang dapat digunakan seperti tipe data primitif, tapi disembunyikan implementasinya.

### C. Struct sebagai ADT<br/>
Menurut Zeil (2021), di dalam bahasa C++ sebuah class berfungsi sebagai implementasi dari Abstract Data Type (ADT). Struktur kelas ini menjaga prinsip ADT dengan memisahkan bagian publik dan privat dari suatu tipe data, sehingga representasi internal dapat disembunyikan dari pengguna [3].

Hal yang sama dijelaskan oleh Tantalo (2023) bahwa dalam C++, ADT didefinisikan sebagai sekumpulan nilai dan operasi yang diimplementasikan menggunakan class, di mana bagian publik menyediakan operasi yang dapat diakses, sementara bagian privat menyembunyikan detail data [4].

### D. Abstract Data Type <br/>
ADT adalah type dan sekumpulan primitif (operasi dasar) terhadap type tersebut. Selain itu, dalam sebuah ADT yang lengkap, disertakan pula definisi invariant dari type dan aksioma yang berlaku. ADT merupakan definisi statik [5].

#### Definisi type dari sebuah ADT dapat mengandung sebuah definisi ADT lain. Misalnya:
1. ADT waktu yang terdiri dari ADT JAM dan ADT DATE
2. Garis terdiri dari dua buah ADT POINT

#### SEGI4 terdiri dari pasangan dua buah POINT (Top, Left) dan (Bottom, Right)

TYPE diterjemahkan menjadi type terdefinisi dalam bahasa yang bersangkutan. Jika dalam bahasa C menggunakan struct primitif, dalam konteks prosedural, diterjemahkan menjadi fungsi atau prosedur.

#### PRIMITIF dikelompokkan menjadi:
1. Konstruktor/Kreator, pembentuk nilai tipe. Semua objek (variabel) bertipe tersebut harus melalui konstruktor. Biasanya dinamai Make.
2. Selector, untuk mengakses komponen (biasanya dinamai Get).
3. Prosedur pengubah, yaitu komponen yang bisa diubah nilainya.
4. Tipe validasi dan operasi logika untuk menentukan apakah dapat membentuk tipe sesuai dengan batasannya.
5. Destruktor/Deallocator, yaitu untuk menghancurkan nilai objek/variabel (sekaligus memori penyimpanannya).
6. Baca/Tulis, untuk interface dengan input/output device.
7. Operator relasional, terhadap tipe tersebut untuk mendefinisikan lebih besar, lebih kecil, sama dengan, dan sebagainya.
8. Aritmatika terhadap tipe tersebut, karena biasanya aritmatika dalam bahasa C hanya terdefinisi untuk bilangan numerik.
9. Konversi dari tipe tersebut ke tipe dasar dan sebaliknya.

ADT biasanya diimplementasikan menjadi dua buah modul utama dan satu modul interface program utama (driver).

#### Dua modul tersebut adalah sebagai berikut:
#### 1. Definisi/Spesifikasi Type dan Primitif/Header fungsi (.h)
-  Spesifikasi type sesuai dengan kaidah bahasa yang dipakai.
- Spesifikasi dari primitif sesuai dengan kaidah dalam konteks prosedural, yaitu:
- Fungsi: nama, domain, dan precondition.
- Prosedur: Initial state, Final state, dan proses yang dilakukan.

#### 2. Body/Realisasi dari primitif (.c)
Beberapa kode program dalam bahasa yang bersangkutan (dalam praktikum ini berarti dengan bahasa C/C++). Realisasi fungsi dan prosedur harus sedapat mungkin memanfaatkan selector dan konstruktor.

## Guided 

### 1. ADT

### file: mahasiswa.h
```C++
#ifndef MAHASISWA_H
#define MAHASISWA_H
struct mahasiswa {
    char nim[10];
    int nilai1, nilai2;
};
void inputMhs (mahasiswa &m);
float rata2 (mahasiswa m);

#endif
```

### file: mahasiswa.cpp
```C++
#include <iostream>
#include "mahasiswa.h"

using namespace std;
void inputMhs (mahasiswa &m) {
    cout << "input NIM : ";
    cin >> m.nim;
    cout << "input nilai 1 : ";
    cin >> m.nilai1;
    cout << "input nilai 2 : ";
    cin >> m.nilai2;
}
float rata2 (mahasiswa m) {
    return (float) (m.nilai1 + m.nilai2) / 2;
}
```

### file: main.cpp
```C++
#include <iostream>
#include "mahasiswa.h"
#include <cstdlib>
using namespace std;

int main() {
    mahasiswa mhs;

    inputMhs(mhs);

    cout << "rata-rata nilai adalah : " << rata2
    (mhs) <<endl;
    system ("pause");

    return 0;
}
```
Kode dengan bahasa pemrograman C++ yang bertujuan untuk membaca data mahasiswa (nama, nim, nilai1, dan nilai2), lalu program juga akan menghitung rata rata dari nilai mahasiswa tersebut. Untuk menghitung rata rata ada di bagian mahasiswa.cpp (file). Program meminta kita menginput nama, nim, nilai1, nilai2. Lalu data dimasukkan ke fungsi dan program menghitung rata ratanya. Output berupa hasil rata rata dari nilai mahasiswa.

### 1. Struct

```C++
#include <iostream>
using namespace std;

struct mahasiswa {
    char nim[10];
    float nilai1, nilai2;
};

void inputMhs(mahasiswa &m){
    cout << "Masukkan NIM: ";
    cin >> m.nim;
    cout << "Masukkan nilai 1: ";
    cin >> m.nilai1;
    cout << "Masukkan nilai 2: ";
    cin >> m.nilai2;
}

float rata2(mahasiswa m){
    return(float)(m.nilai1 + m.nilai2) / 2;
}

int main(){
    mahasiswa mhs;

    inputMhs(mhs);

    cout << "Rata-rata nilai adalah :" << rata2(mhs) << endl;

    system("read -p 'Press Enter to continue...' var");

    return 0;
}
```
Kode dengan bahasa pemrograman C++ yang bertujuan untuk membaca data mahasiswa (nim, nilai1, dan nilai2), itu nanti disimpan di dalam struct mahasiswa, lalu program juga akan menghitung rata rata dari nilai mahasiswa tersebut. Output berupa hasil rata rata dari nilai mahasiswa.  

## Unguided 

### 1. Buat program yang dapat menyimpan data mahasiswa (max. 10) ke dalam sebuah array dengan field nama, nim, uts, uas, tugas, dan nilai akhir. Nilai akhir diperoleh dari FUNGSI dengan rumus: 0.3 * uts + 0.4 * uas + 0.3 * tugas

```C++
#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    string nama, nim;
    float uts, uas, tugas, akhir;
};

float nilaiAkhir(float uts, float uas, float tugas) {
    return 0.3 * uts + 0.4 * uas + 0.3 * tugas;
}

int main() {
    Mahasiswa mhs[10];
    int n;
    cout << "Masukkan jumlah mahasiswa (maks 10): ";
    cin >> n;
    if (n > 10) n = 10;

    for (int i = 0; i < n; i++) {
        cout << "\nData ke-" << i + 1 << endl;
        cout << "Nama  : "; cin >> mhs[i].nama;
        cout << "NIM   : "; cin >> mhs[i].nim;
        cout << "UTS   : "; cin >> mhs[i].uts;
        cout << "UAS   : "; cin >> mhs[i].uas;
        cout << "Tugas : "; cin >> mhs[i].tugas;

        mhs[i].akhir = nilaiAkhir(mhs[i].uts, mhs[i].uas, mhs[i].tugas);
    }
    cout << "\n=== Daftar Nilai Mahasiswa ===\n";
    for (int i = 0; i < n; i++) {
        cout << mhs[i].nama << " (" << mhs[i].nim << ")"
             << " -> Nilai Akhir: " << mhs[i].akhir << endl;
    }

    return 0;
}
```
### Output Unguided 1 :

##### Output
![Screenshot Output Unguided 1_1](https://github.com/savilanf/103112400031_Savila-Nur-Fadilla/blob/main/Pertemuan3_Modul3/output/output-unguided1.png)

Kode dengan bahasa pemrograman C++ yang bertujuan untuk menyimpan data mahasiswa (max 10). Bagian include iostream itu untuk memasukkan file header iostream. Di dalam program ada struct mahasiswa yang akan menyimpan data mahasiswa seperti nama, nim, dan nilai nilainya. Ada float umtuk menghitung rumus untuk nilai akhir. Kemudian program menjalanlan fungsi main, di fungsi main kita diminta input jumlah mahasiswa (maks 10) lalu diminta input nama, nim, dan lainnya. Ada perulangan (input data sampai jumlah mahassiwa yang diinput tadi terpenuhi). Data itu disimpan di struct dan ditampilkan di output beserta nilai akhirnya yang dihitung dengan rumus di float nilai akhir.

### 2. Buatlah ADT pelajaran sebagai berikut di dalam file "pelajaran.h":
Type pelajaran < 
    namaMapel : string 
    kodeMapel : string 
>
function create_pelajaran(namapel : string, kodepel : string) -> pelajaran procedure tampil_pelajaran(input pel : pelajaran)

### Buatlah implementasi ADT pelajaran pada file "pelajaran.cpp" Cobalah hasil implementasi ADT pada file "main.cpp" 
using namespace std;

int main() {
    string namapel = "Struktur Data";
    string kodepel = "STD";
    pelajaran pel = create_pelajaran(namapel, kodepel);
    tampil_pelajaran(pel);
    return 0;
}

### file: pelajaran.h
```C++
#ifndef PELAJARAN_H
#define PELAJARAN_H

#include <string>
using namespace std;

struct pelajaran {
    string namaPel;
    string kodePel;
};

pelajaran create_pelajaran(string namaPel, string kodePel);
void tampil_pelajaran(const pelajaran& p);

#endif
```

### file: pelajaran.cpp
```C++
#include "pelajaran.h"
#include <iostream>
using namespace std;

pelajaran create_pelajaran(string namaPel, string kodePel) {
    pelajaran p;
    p.namaPel = namaPel;
    p.kodePel = kodePel;
    return p;
}

void tampil_pelajaran(const pelajaran& p) {
    cout << "nama pelajaran : " << p.namaPel << endl;
    cout << "nilai : " << p.kodePel << endl;
}
```

### file: main2.cpp
```C++
#include "pelajaran.h"
#include <iostream>
using namespace std;

int main() {
    string namaPel = "Struktur Data";
    string kodePel = "STD";
    pelajaran pel = create_pelajaran(namaPel, kodePel);
    tampil_pelajaran(pel);
    return 0;
}
```
### Output Unguided 2 :

##### Output
![Screenshot Output Unguided 2_1](https://github.com/savilanf/103112400031_Savila-Nur-Fadilla/blob/main/Pertemuan3_Modul3/output/output-unguided2.png)

Kode dengan bahasa pemrograman C++ yang bertujuan untuk membuat dan menampilkan data pelajaran dengan konsep ADT. Data pelajaran (nama dan kode) dikemas dalam satu tipe data (pelajaran). Inputnya berupa nama pelajaran (struktur data) dan kode pelajaran (STD). Output berupa string nama pelajaran dan nilai atau kode pelajaran yang sudah kita inputkan.

### 3. Buatlah program dengan ketentuan:
### - 2 buah array 2D integer berukuran 3x3 dan 2 buah pointer integer
### - fungsi/prosedur yang menampilkan isi sebuah array integer 2D
### - fungsi/prosedur yang akan menukarkan isi dari 2 array integer 2D pada posisi tertentu
### - fungsi/prosedur yang akan menukarkan isi dari variabel yang ditunjuk oleh 2 buah pointer

```C++
#include <iostream>
using namespace std;

void tampilArray(int arr[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}

void tukarPosisi(int arr1[3][3], int arr2[3][3], int baris, int kolom) {
    int temp = arr1[baris][kolom];
    arr1[baris][kolom] = arr2[baris][kolom];
    arr2[baris][kolom] = temp;
}

void tukarPointer(int* p1, int* p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int main() {
    int A[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int B[3][3] = {
        {10, 11, 12},
        {13, 14, 15},
        {16, 17, 18}
    };


    int a = 10, b = 20;
    int *ptr1 = &a, *ptr2 = &b;

    cout << "Array A awal:\n";
    tampilArray(A);
    cout << "\nArray B awal:\n";
    tampilArray(B);

    int baris, kolom;
    cout << "\nMasukkan posisi baris (1-3): ";
    cin >> baris;
    cout << "Masukkan posisi kolom (1-3): ";
    cin >> kolom;
    baris -= 1;
    kolom -= 1;
    if (baris < 0 || baris > 2 || kolom < 0 || kolom > 2) {
        cout << "\n⚠️  Posisi tidak valid! Harus antara 1 dan 3.\n";
        return 0;
    }

    tukarPosisi(A, B, baris, kolom);

    cout << "\nSetelah tukar posisi (" << baris + 1 << "," << kolom + 1 << "):\n";
    cout << "Array A:\n";
    tampilArray(A);
    cout << "\nArray B:\n";
    tampilArray(B);
    cout << "\nSebelum tukar pointer: a = " << a << ", b = " << b << endl;
    tukarPointer(ptr1, ptr2);
    cout << "Setelah tukar pointer: a = " << a << ", b = " << b << endl;

    return 0;
}
```
### Output Unguided 3 :

##### Output
![Screenshot Output Unguided 3_1](https://github.com/savilanf/103112400031_Savila-Nur-Fadilla/blob/main/Pertemuan3_Modul3/output/output-unguided3.png)

Kode dengan bahasa pemrograman C++ yang bertujuan untuk menampilkan isi sebuah array integer 2D, menukarkan isi dari 2 array integer 2D pada posisi tertentu, menukarkan isi dari variabel yang ditunjuk oleh 2 buah pointer. Bagian include iostream itu untuk memasukkan file header iostream. Ada prosedur tukar posisi array, tukar pointer, dan tampilkan array. Kemudian program menjalanlan fungsi main, di sini akan mengeluarkan output, ada menampilkan array, lalu array setelah tukar posisi, menampilkan isi variabel sebelum pointer ditukar dan setelah pointer ditukar.

## Kesimpulan
Laporan Praktikum Struktur Data Modul 3 ini menggunakan kode bahasa pemrograman C++. Pada praktikum ini, dipelajari penggunaan struct dan Abstract Data Type (ADT) untuk mengelola data secara terstruktur. Dengan ADT, data dan fungsinya dapat dipisahkan sehingga program menjadi lebih rapi, mudah dibaca, dan mudah dikembangkan.

## Referensi

[1] Gibbons, J. (2016). *Algebraic Data Types*. University of Oxford. Diakses dari https://www.cs.ox.ac.uk/jeremy.gibbons/publications/adt.pdf  

[2] Cook, W. R. (1990). *Object-Oriented Programming versus Abstract Data Types*. University of Texas at Austin. Diakses dari https://www.cs.utexas.edu/~wcook/papers/OOPvsADT/CookOOPvsADT90.pdf  

[3] Zeil, S. J. (n.d.). *Implementing Abstract Data Types*. Old Dominion University. Diakses dari https://www.cs.odu.edu/~zeil/cs330/latest/Public/implementingADTS/index.html  

[4] Tantalo, P. (2023). *ADTs in C++*. University of California, Santa Cruz. Diakses dari https://people.ucsc.edu/~ptantalo/cse101/Spring23/Handouts/ADTs-in-C%2B%2B.pdf  

[5] Informatics Laboratory. (n.d.). *Modul 3 – Abstract Data Type (ADT)*. Program Studi Teknik Informatika, Telkom University.    