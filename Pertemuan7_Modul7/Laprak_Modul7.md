# <h1 align="center">Laporan Praktikum Modul 7 - Stack</h1>
<p align="center">Savila Nur Fadilla - 103112400031</p>

## Dasar Teori
### A. Stack atau Tumpukan<br/>
Struktur data yang sangat penting adalah Stack, struktur data linier yang mengikuti prinsip Last In First Out (LIFO). Artinya elemen yang terakhir disisipkan akan menjadi elemen pertama yang keluar [1]. Seperti halnya tumpukan, elemen yang bisa diambil terlebih dahulu adalah elemen yang paling atas, atau elemen yang pertama kali masuk, prinsip ini biasa disebut LIFO (Last In First Out) [2].

### B. Komponen dalam stack<br/>
1. Dalam stack hanya terdapat TOP.
2. Tipe address adalah tipe elemen stack yang sama dengan elemen dalam list lainnya.

### C. Operasi dalam stack<br/>  
1. Push: menyisipkan elemen pada tumpukan data. Fungsi ini sama dengan fungsi insert first
pada list biasa
```C++
/* buat dahulu elemen yang akan disisipkan */
address createElm(int X){
address P = alokasi(X);
P→next = Nil;
return P;
}
/* contoh syntax push */
void push(address P){
P→next = S.Top;
S.Top = P;
}
```
2. Pop : pengambilan data dalam list. Operasi ini mirip dengan operasi delete first dalam list
linear, karena elemen yang paling pertama kali diakses adalah elemen paling atas atau elemen paling
awal saja
```C++
/* contoh syntax pop */
address pop(address P){
P = S.Top;
S.Top = (S.Top)→next;
return P;
}
```

### D. Primitif dalam stack<br/>   
Primitif -primitif dalam stack :
1. createStack().
2. isEmpty().
3. alokasi().
4. dealokasi().
5. Fungsi – fungsi pencarian.
6. Dan fungsi – fungsi primitif lainnya.
Seperti halnya pada model list yang lain, primitif-primitifnya tersimpan pada file *.c dan file *.h.

### E. Stack representasi tabel<br/>   
Sama halnya dengan menggunakan pointer. Perbedaannya terletak pada pendeklarasian struktur datanya, menggunakan array berindeks dan jumlah tumpukan yang terbatas.

### Operasi dalam stack representasi tabel
1. Push
2. Pop

### Primitif dalam stack representasi tabel
1. createStack().
2. isEmpty().
3. Fungsi – fungsi pencarian.
4. Dan fungsi – fungsi primitif lainnya.
Seperti halnya pada model list yang lain, primitif-primitifnya tersimpan pada file *.c dan file *.h.

## Guided 

### 1. guided1

### file: stack.h
```C++
#ifndef STACK_H
#define STACK_H
#define Nil nullptr

#include<iostream>
using namespace std;

typedef struct node *address;

struct node{
    int dataAngka;
    address next;
};

struct stack{
    address top;
};

bool isEmpty(stack listStack);
void createStack(stack &listStack);
address alokasi(int angka);
void dealokasi(address &node);
void push(stack &listStack, address nodeBaru);
void pop(stack &listStack);
void update(stack &listStack, int posisi);
void view(stack listStack);
void searchData(stack listStack, int data);
#endif
```

### file: stack.cpp
```C++
#include "stack.h"
#include <iostream>

using namespace std;

bool isEmpty(stack listStack){
    if(listStack.top == Nil){
        return true;
    } else {
        return false;
    }
}

void createStack(stack &listStack){
    listStack.top = Nil;
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

void push(stack &listStack, address nodeBaru){
    nodeBaru->next = listStack.top;
    listStack.top = nodeBaru;
    cout << "Node " << nodeBaru->dataAngka << " berhasil ditambahkan kedalam stack!" << endl;
}

void pop(stack &listStack){
    address nodeHapus;
    if(isEmpty(listStack) == true){
        cout << "Stack kosong!" << endl;
    } else {
        nodeHapus = listStack.top;
        int data = nodeHapus->dataAngka;
        listStack.top = listStack.top->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "node " <<  data << " berhasil dihapus dari stack!" << endl;
    }
}

void update(stack &listStack, int posisi){
    if(isEmpty(listStack) == true){
        cout << "Stack kosong!" << endl;
    } else {
        if(posisi <= 0){
            cout << "Posisi tidak valid!" << endl;
        } else {
            address nodeBantu = listStack.top;
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

void view(stack listStack){ //mencetak dari tumpukan paling atas ke tumpukan paling bawah
    if(isEmpty(listStack) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = listStack.top;
        while(nodeBantu != Nil){
            cout << nodeBantu->dataAngka << " ";
            nodeBantu = nodeBantu->next;
        }
    }
    cout << endl;
}

void searchData(stack listStack, int data){
    if(isEmpty(listStack) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = listStack.top;
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
            cout << "Data " << data << " tidak ditemukan didalam stack!" << endl;
            cout << endl;
        }
    }
}
```

### file: main.cpp
```C++
#include "stack.h"
#include <iostream>

using namespace std;

int main(){
    stack listStack;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createStack(listStack);

    nodeA = alokasi(1);
    nodeB = alokasi(2);
    nodeC = alokasi(3);
    nodeD = alokasi(4);
    nodeE = alokasi(5);

    push(listStack, nodeA);
    push(listStack, nodeB);
    push(listStack, nodeC);
    push(listStack, nodeD);
    push(listStack, nodeE);
    cout << endl;

    cout << "--- Stack setelah push ---" << endl;
    view(listStack);
    cout << endl;

    pop(listStack);
    pop(listStack);
    cout << endl;

    cout << "--- Stack setelah pop 2 kali ---" << endl;
    view(listStack);
    cout << endl;

    update(listStack, 2);
    update(listStack, 1);
    update(listStack, 4);
    cout << endl;

    cout << "--- Stack setelah update ---" << endl;
    view(listStack);
    cout << endl;

    searchData(listStack, 4);
    searchData(listStack, 9);

    return 0;
}
```
Kode ini merupakan pemrograman bahasa C++ yang mendefinisikan struktur data stack menggunakan Linked List. Setiap elemen stack direpresentasikan sebagai node yang berisi data angka dan pointer ke elemen berikutnya (next). Struktur utama stack hanya menyimpan pointer top, yaitu elemen teratas dalam tumpukan. Ada beberapa fungsi dan prosedur: createStack, isEmpty, alokasi dan dealokasi, push, pop, update, view, searchData.

### 2. guided2

### file: stack.h
```C++
#ifndef STACK_H
#define STACK_H

#include <iostream>
#define MaxEl 20
#define Nil -1

typedef int infotype;

struct Stack{
    infotype info[MaxEl]; //array untuk menyimpan elemen stack
    int top; //indeks top stack
};

void CreateStack(Stack &S);
bool isEmpty(Stack S);
bool isFull(Stack S);
void push(Stack &S, infotype X); //menambahkan elemen ke stack
infotype pop(Stack &S); //mengambil elemen teratas dari stack
void printInfo(Stack S); //menampilkan isi stack
void balikStack(Stack &S); //membalik urutan elemen stack
#endif
```

### file: stack.cpp
```C++
#include "stack.h"
using namespace std;
// Fungsi untuk membuat stack baru dengan menginisialisasi top = Nil
void CreateStack(Stack &S) {
    S.top = Nil;  // Inisialisasi top dengan nilai Nil mendakan stack kosong
}

// Fungsi untuk mengecek apakah stack kosong
bool isEmpty(Stack S) {
    return S.top == Nil;  // Mengembalikan true jika top bernilai Nil, false jika tidak
}

// Fungsi untuk mengecek apakah stack penuh
bool isFull(Stack S) {
    return S.top == MaxEl - 1;  // Mengembalikan true jika top mencapai batas maksimum (MaxEl-1)
}

// Fungsi untuk menambah elemen ke dalam stack (push)
void push(Stack &S, infotype x) {
    if (!isFull(S)) {  // Cek apakah stack belum penuh
        S.top++;  // Increment nilai top
        S.info[S.top] = x;  // Masukkan nilai x ke array info pada indeks top
    } else {
        cout << "Stack Penuh!" << endl;  // Tampilkan pesan jika stack penuh
    }
}

// Fungsi untuk mengambil elemen teratas dari stack (pop)
infotype pop(Stack &S) {
    infotype x = -999;  // Inisialisasi nilai default jika stack kosong
    if (!isEmpty(S)) {  // Cek apakah stack tidak kosong
        x = S.info[S.top];  // Ambil nilai teratas
        S.top--;  // Decrement nilai top
    } else {
        cout << "Stack Kosong!" << endl;  // Tampilkan pesan jika stack kosong
    }
    return x;  // Kembalikan nilai yang diambil
}

// Fungsi untuk menampilkan isi stack
void printInfo(Stack S) {
    if (isEmpty(S)) {  // Cek apakah stack kosong
        cout << "Stack Kosong" << endl;  // Tampilkan pesan jika kosong
    } else {
        cout << "[TOP] ";  // Tampilkan penanda posisi top
        for (int i = S.top; i >= 0; i--) {  // Loop dari top sampai dasar stack
            cout << S.info[i] << " ";  // Tampilkan setiap elemen
        }
        cout << endl;  // Pindah baris setelah selesai
    }
}

// Fungsi untuk membalik urutan elemen dalam stack
void balikStack(Stack &S) {
    if (!isEmpty(S)) {  // Cek apakah stack tidak kosong
        Stack temp1, temp2;  // Deklarasi dua stack temporary
        CreateStack(temp1); CreateStack(temp2);  // Inisialisasi kedua stack temporary

        while (!isEmpty(S)) { push(temp1, pop(S)); }  // Pindahkan semua elemen ke temp1 (urutan terbalik)

        while (!isEmpty(temp1)) { push(temp2, pop(temp1)); }  // Pindahkan ke temp2 (urutan terbalik lagi)

        while (!isEmpty(temp2)) { push(S, pop(temp2)); }  // Kembalikan ke stack asal (urutan sudah benar)
    }
}
```

### file: main.cpp
```C++
#include "stack.h"
#include <iostream>

using namespace std;

int main() {
    Stack S;
    CreateStack(S);

    push(S, 3);
    push(S, 4);
    push(S, 8);
    pop(S);
    push(S, 2);
    push(S, 3);
    pop(S);
    push(S, 9);

    cout << "Stack Awal:" << endl;
    printInfo(S);

    cout << "balik stack" << endl;
    balikStack(S);

    cout << "Stack Setelah dibalik:" << endl;
    printInfo(S);

    return 0;
}
```
Kode ini merupakan pemrograman bahasa C++ yang mendefinisikan struktur data stack menggunakan array statis. Setiap elemen stack disimpan dalam array info dengan kapasitas maksimum MaxEl, dan variabel top digunakan untuk menunjukkan posisi elemen teratas. Program ini menggunakan beberapa fungsi dan prosedur yaitu CreateStack, isEmpty, isFull, push, pop, printInfo, dan balikStack.

## Unguided

### 1. Buatlah ADT Stack menggunakan ARRAY sebagai berikut di dalam file “stack.h”:
Type infotype : integer
Type Stack <
info : array [20] of integer
top : integer
>
procedure CreateStack( input/output S : Stack )
procedure push(input/output S : Stack,
input x : infotype)
function pop(input/output t S : Stack )
→ infotype
procedure printInfo( input S : Stack )
procedure balikStack(input/output S :
Stack )

### Buatlah implementasi ADT Stack menggunakan Array pada file “stack.cpp” dan “main.cpp”
```C++
int main(){
    cout << "Hello world!" <<
    endl;
    Stack S;
    createStack(S);
    Push(S,3);
    Push(S,4);
    Push(S,8);
    pop(S)
    Push(S,2);
    Push(S,3);
    pop(S);
    Push(S,9);
    printInfo(S);
    cout<<"balik stack"<<endl;
    balikStack(S);
    printInfo(S);
    return 0;
}
```

### 2. Tambahkan prosedur pushAscending( in/out S : Stack, in x : integer)
```C++
int main(){
    cout << "Hello world!" << endl;
    Stack S;
    createStack(S);
    pushAscending(S,3);
    pushAscending(S,4);
    pushAscending(S,8);
    pushAscending(S,2);
    pushAscending(S,3);
    pushAscending(S,9);
    printInfo(S);
    cout<<"balik stack"<<endl;
    balikStack(S);
    printInfo(S);
    return 0;
}
```

### 3. Tambahkan prosedur getInputStream( in/out S : Stack ). Prosedur akan terus membaca dan menerima input user dan memasukkan setiap input ke dalam stack hingga user menekan tombol enter. Contoh: gunakan cin.get() untuk mendapatkan inputan user.
```C++
int main(){
    cout << "Hello world!" << endl;
    Stack S;
    createStack(S);
    getInputStream(S);
    printInfo(S);
    cout<<"balik stack"<<endl;
    balikStack(S);
    printInfo(S);
    return 0;
}
```

### JAWABAN
### file: stack.h
```C++
#ifndef STACK_H
#define STACK_H

#include <iostream>
#define MaxEl 20
#define Nil -1

typedef int infotype;

struct Stack{
    infotype info[MaxEl]; //array untuk menyimpan elemen stack
    int top; //indeks top stack
};

void CreateStack(Stack &S);
bool isEmpty(Stack S);
bool isFull(Stack S);
void push(Stack &S, infotype X); //menambahkan elemen ke stack
infotype pop(Stack &S); //mengambil elemen teratas dari stack
void printInfo(Stack S); //menampilkan isi stack
void balikStack(Stack &S); //membalik urutan elemen stack
void pushAscending(Stack &S,infotype X); //menambahkan elemen ke stack secara ascending
void getInputStream(Stack &S); //mengambil input stream dan memasukkannya ke stack
#endif
```

### file: stack.cpp
```C++
#include "stack.h"
using namespace std;
//Fungsi untuk membuat stack baru dengan menginisialisasi top = Nil
void CreateStack(Stack &S) {
    S.top = Nil;  // Inisialisasi top dengan nilai Nil mendakan stack kosong
}

//Fungsi untuk mengecek apakah stack kosong
bool isEmpty(Stack S) {
    return S.top == Nil;  // Mengembalikan true jika top bernilai Nil, false jika tidak
}

//Fungsi untuk mengecek apakah stack penuh
bool isFull(Stack S) {
    return S.top == MaxEl - 1;  // Mengembalikan true jika top mencapai batas maksimum (MaxEl-1)
}

//Fungsi untuk menambah elemen ke dalam stack (push)
void push(Stack &S, infotype x) {
    if (!isFull(S)) {  // Cek apakah stack belum penuh
        S.top++;  // Increment nilai top
        S.info[S.top] = x;  // Masukkan nilai x ke array info pada indeks top
    } else {
        cout << "Stack Penuh!" << endl;  // Tampilkan pesan jika stack penuh
    }
}

//Fungsi untuk mengambil elemen teratas dari stack (pop)
infotype pop(Stack &S) {
    infotype x = -999;  // Inisialisasi nilai default jika stack kosong
    if (!isEmpty(S)) {  // Cek apakah stack tidak kosong
        x = S.info[S.top];  // Ambil nilai teratas
        S.top--;  // Decrement nilai top
    } else {
        cout << "Stack Kosong!" << endl;  // Tampilkan pesan jika stack kosong
    }
    return x;  // Kembalikan nilai yang diambil
}

//Fungsi untuk menampilkan isi stack
void printInfo(Stack S) {
    if (isEmpty(S)) {  // Cek apakah stack kosong
        cout << "Stack Kosong" << endl;  // Tampilkan pesan jika kosong
    } else {
        cout << "[TOP] ";  // Tampilkan penanda posisi top
        for (int i = S.top; i >= 0; i--) {  // Loop dari top sampai dasar stack
            cout << S.info[i] << " ";  // Tampilkan setiap elemen
        }
        cout << endl;  // Pindah baris setelah selesai
    }
}

//Fungsi untuk membalik urutan elemen dalam stack
void balikStack(Stack &S) {
    if (!isEmpty(S)) {  // Cek apakah stack tidak kosong
        Stack temp1, temp2;  // Deklarasi dua stack temporary
        CreateStack(temp1); CreateStack(temp2);  // Inisialisasi kedua stack temporary

        while (!isEmpty(S)) { push(temp1, pop(S)); }  // Pindahkan semua elemen ke temp1 (urutan terbalik)

        while (!isEmpty(temp1)) { push(temp2, pop(temp1)); }  // Pindahkan ke temp2 (urutan terbalik lagi)

        while (!isEmpty(temp2)) { push(S, pop(temp2)); }  // Kembalikan ke stack asal (urutan sudah benar)
    }
}

//Fungsi untuk push elemen secara ascending
void pushAscending(Stack &S, infotype x) {
    Stack temp;
    CreateStack(temp);

    while (!isEmpty(S) && S.info[S.top] > x) { //selama elemen tidak kosong dan elemen teratas lebih besar dari x
        push(temp, pop(S)); //pindahkan elemen dari S ke temp
    }

    push(S, x); //push x ke S

    while (!isEmpty(temp)) { //selama temp tidak kosong
        push(S, pop(temp)); //pindahkan elemen dari temp ke S
    }
}

//Fungsi untuk membaca input stream (setiap digit angka jadi elemen stack)
void getInputStream(Stack &S) {
    // Versi interaktif — kalau mau otomatis, sudah diatur di main.cpp
    char c;
    while (cin.get(c)) {
        if (c == '\n') break;
        if (isdigit(c)) {
            push(S, c - '0');
        }
    }
}
```

### file: main.cpp
```C++
#include "stack.h"
using namespace std;

int main() {
    Stack S;
    CreateStack(S);

    int pilihan;
    cout << "\n=== MENU STACK ===" << endl;
    cout << "1. Stack Biasa" << endl;
    cout << "2. Push Ascending" << endl;
    cout << "3. Get Input Stream" << endl;
    cout << "Pilih menu: ";
    cin >> pilihan;
    cin.ignore(); //hapus newline sisa input

    switch (pilihan) {
        case 1: {
            cout << "\n-- Stack Biasa --" << endl;
            cout << "Hello world!" << endl;
            push(S, 3);
            push(S, 4);
            push(S, 8);
            pop(S);
            push(S, 2);
            push(S, 9);
            printInfo(S);

            cout << "balik stack" << endl;
            balikStack(S);
            printInfo(S);
            break;
        }
        case 2: {
            cout << "\n-- Push Ascending --" << endl;
            cout << "Hello world!" << endl;

            Stack S;
            CreateStack(S);

            pushAscending(S,3);
            pushAscending(S,4);
            pushAscending(S,8);
            pushAscending(S,2);
            pushAscending(S,3);
            pushAscending(S,9);

            printInfo(S);
            cout<< "balik stack" <<endl;
            balikStack(S);
            printInfo(S);
            break;
        }
        case 3: {
            cout << "\n-- Get Input Stream --" << endl;
            cout << "Masukkan angka (ENTER untuk selesai): " << endl;
            cout << "Hello world!" << endl;
            getInputStream(S);
            printInfo(S);

            cout << "balik stack" << endl;
            balikStack(S);
            printInfo(S);
            break;
        }
        default:
            cout << "Pilihan tidak valid!" << endl;
            break;
    }
    return 0;
}
```

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/savilanf/103112400031_Savila-Nur-Fadilla/blob/main/Pertemuan7_Modul7/output/output1.png)

##### Output 2
![Screenshot Output Unguided 2_1](https://github.com/savilanf/103112400031_Savila-Nur-Fadilla/blob/main/Pertemuan7_Modul7/output/output2.png)

##### Output 3
![Screenshot Output Unguided 3_1](https://github.com/savilanf/103112400031_Savila-Nur-Fadilla/blob/main/Pertemuan7_Modul7/output/output3.png)

Kode dengan bahasa progpemrograman C++ yang memanfaatkan struktur data stack (tumpukan). Stack merupakan struktur data dengan prinsip LIFO (Last In First Out), yaitu elemen yang terakhir dimasukkan akan keluar lebih dulu. Dalam program ini, stack diimplementasikan menggunakan array dengan kapasitas maksimum MaxEl = 20. Setiap elemen stack bertipe infotype (integer). Program ini memiliki beberapa prosedur dan fungsi, yaitu:
CreateStack, isEmpty dan isFull, push dan pop, printInfo, balikStack, pushAscending, dan getInputStream

## Kesimpulan
Laporan Praktikum Struktur Data Modul 7 ini menggunakan kode bahasa pemrograman C++. Pada praktikum ini dipelajari penerapan Stack atau tumpukan dengan struktur ADT. Stack merupakan struktur data dengan prinsip LIFO (Last In First Out), yaitu elemen yang terakhir dimasukkan akan keluar lebih dulu. Melalui latihan, melatih untuk memahami cara membuat stack, menambah stack, menampilkan isi stack, mencari stack, mengeluarkan stack, menghapus stack, dan lain sebagainya. Penerapan ADT membuat program lebih terstruktur, efisien, dan mudah dikembangkan untuk pengolahan data yang kompleks.

## Referensi 

[1] Setiyawan, R. D., Hermawan, D., Abdillah, A. F., Mujayanah, A., & Vindua, R. (2024). Penggunaan Struktur Data Stack dalam Pemrograman C++ dengan Pendekatan Array dan Linked List. JUTECH: Journal Education and Technology, 5(2), 484-498. Fakultas Ilmu Komputer, Universitas Pamulang.

[2] Informatics Laboratory. (n.d.). *Modul 7 – Stack*. Program Studi Teknik Informatika, Telkom University.