# <h1 align="center">Laporan Praktikum Modul 13 - Multi Linked List</h1>
<p align="center">Savila Nur Fadilla - 103112400031</p>

## Dasar Teori
### A. Multi Linked List<br/>
Multi Linked List (MLL) adalah struktur data yang terdiri dari beberapa linked list yang terhubung dalam bentuk hierarki. Setiap elemen pada list induk (parent) dapat memiliki list anak (child) tersendiri sehingga membentuk hubungan one-to-many. Struktur ini digunakan ketika data memiliki keterkaitan bertingkat seperti kategori–produk, folder–file, atau golongan–hewan.

Model ini sejalan dengan konsep nested relational data, di mana sebuah node dapat menyimpan turunan (sub-node) yang perlu dikelola melalui struktur terhubung. Jagadish dkk. menjelaskan bahwa representasi data bertingkat memerlukan mekanisme pointer yang efektif untuk memudahkan proses traversal dan pengolahan data secara efisien [1].

### B. Operasi pada Multi Linked List<br/>
Operasi dasar dalam MLL merupakan pengembangan dari operasi pada linked list biasa, namun dilakukan pada dua level sekaligus: induk dan anak. Beberapa operasi yang umum digunakan yaitu:
1. createListParent & createListChild – menginisialisasi list induk dan anak.
2. Alokasi node – membuat simpul induk/anak secara dinamis.
3. Insert node – menambahkan parent atau child pada posisi tertentu (first/last).
4. Delete node – menghapus node induk atau anak, termasuk seluruh anak ketika induk dihapus.
5. Searching – menelusuri parent dan child berdasarkan ID atau kriteria tertentu.
6. Traversal – mencetak struktur MLL secara hierarki.

Dietz menyatakan bahwa efisiensi struktur list sangat bergantung pada pengelolaan pointer dalam operasi insert, delete, serta pemeliharaan urutan elemen—konsep yang juga diterapkan pada MLL [2].

### C. Jenis MLL dan Sintaks Struktur Umum<br/>
1. Jenis–Jenis MLL
Implementasi MLL dapat bervariasi, antara lain:
- Single-child MLL: setiap parent memiliki satu list anak (digunakan pada praktikum).
- Multi-level linked structure: child memiliki sub-child, membentuk hierarki lebih dalam.
- Doubly Multi Linked List: list anak menggunakan doubly linked list sehingga traversal dapat dilakukan dua arah.

Konsep struktur bertingkat ini sejalan dengan pembahasan Buneman terkait semistructured data, di mana elemen data dapat memiliki turunan yang direpresentasikan dalam bentuk node-node terhubung [3].

2. Sintaks Struktur Dasar MLL
Struktur umum MLL dalam C++ adalah:
```C++
struct NodeChild {
    dataChild info;
    NodeChild *next;
    NodeChild *prev;
};

struct ListChild {
    NodeChild *first;
    NodeChild *last;
};

struct NodeParent {
    dataParent info;
    NodeParent *next;
    NodeParent *prev;
    ListChild LChild;
};

struct ListParent {
    NodeParent *first;
    NodeParent *last;
};
```

### D. Implementasi Multi Linked List dalam Modul 13 Struktur Data<br/>   
Modul 13 membahas penerapan langsung konsep Multi Linked List melalui contoh kasus hubungan pegawai–anak, di mana setiap node induk (pegawai) memiliki satu list anak yang berisi daftar anak pegawai tersebut. Modul menyediakan ilustrasi lengkap mengenai proses penyisipan anak, penghapusan anak, pencarian node induk dan anak, serta penghapusan induk beserta seluruh list anaknya. Di sini menjelaskan bagaimana pointer dalam list induk dan list anak diatur sehingga membentuk struktur hierarki yang konsisten. Selain itu, modul mendefinisikan fungsi-fungsi standar seperti findElm, findElmAnak, insertLast, deleteLast, dan printInfo yang menjadi dasar implementasi MLL pada pemrograman C++ [4].

## Guided 

### 1. MLL

### file: multilist.h
```C++
#ifndef MULTILIST_H
#define MULTILIST_H
#include <iostream>
using namespace std;

typedef struct nodeParent *NodeParent; //alias pointer ke struct nodeParent
typedef struct nodeChild *NodeChild;   //alias pointer ke struct nodeChild

struct nodeChild{ //node child
    string idMakanan;
    string namaMakanan;
    NodeChild next;
    NodeChild prev;
};

struct listAnak{ //list child
    NodeChild first;
    NodeChild last;
};

struct nodeParent{ //node parent
    string idKategoriMakanan;
    string namaKategoriMakanan;
    NodeParent next;
    NodeParent prev;
    listAnak L_Anak;
};

struct listInduk{ //list parent
    NodeParent first;
    NodeParent last;
};

//create list
void createListInduk(listInduk &LInduk);
void createListAnak(listAnak &LAnak);

//alokasi & dealokasi parent
NodeParent alokasiNodeParent(string idKategoriMakanan, string namaKategoriMakanan);
void dealokasiNodeParent(NodeParent &nodeInduk);

//alokasi & dealokasi child
NodeChild alokasiNodeChild(string idMakanan, string namaMakanan);
void dealokasiNodeChild(NodeChild &nodeAnak);

//operasi pada parent
void insertLastParent(listInduk &LInduk, NodeParent nodeBaruParent);
void hapusListAnak(listAnak &LAnak);
void deleteAfterParent(listInduk &LInduk, NodeParent nodePrev);

//operasi pada child
void insertLastChild(listAnak &LAnak, NodeChild nodeBaruChild);
void deleteAfterChild(listAnak &LAnak, NodeChild nodePrev);
void findChildByID(listInduk &LInduk, string IDCari);

//operasi print
void printStrukturMLL(listInduk &LInduk);

#endif
```

### file: multilist.cpp
```C++
#include "multilist.h"
#include <iostream>

using namespace std;

//create list
void createListInduk(listInduk &LInduk){
    LInduk.first = LInduk.last = NULL;
}

void createListAnak(listAnak &LAnak){
    LAnak.first = LAnak.last = NULL;
}

//alokasi & dealokasi parent
NodeParent alokasiNodeParent(string idKategoriMakanan, string namaKategoriMakanan){
    NodeParent nodeBaruParent = new nodeParent;
    nodeBaruParent->idKategoriMakanan = idKategoriMakanan;
    nodeBaruParent->namaKategoriMakanan = namaKategoriMakanan;
    nodeBaruParent->next = NULL;
    nodeBaruParent->prev = NULL;
    createListAnak(nodeBaruParent->L_Anak);
    return nodeBaruParent;
}

void dealokasiNodeParent(NodeParent &nodeInduk){
    if(nodeInduk != NULL) {
        nodeInduk->next = nodeInduk->prev = NULL;
        delete nodeInduk;
        nodeInduk = NULL;
    }
}

//alokasi & delaokasi child
NodeChild alokasiNodeChild(string idMakanan, string namaMakanan){
    NodeChild nodeBaruChild = new nodeChild;
    nodeBaruChild->idMakanan = idMakanan;
    nodeBaruChild->namaMakanan = namaMakanan;
    nodeBaruChild->next = NULL;
    nodeBaruChild->prev = NULL;
    return nodeBaruChild;
}

void dealokasiNodeChild(NodeChild &nodeAnak){
    if(nodeAnak != NULL) {
        nodeAnak->next = nodeAnak->prev = NULL;
        delete nodeAnak;
        nodeAnak = NULL;
    }
}

//operasi pada parent
void insertLastParent(listInduk &LInduk, NodeParent nodeBaruParent){
    if(LInduk.first == NULL) {
        LInduk.first = LInduk.last = nodeBaruParent;
    } else {
        nodeBaruParent->prev = LInduk.last;
        LInduk.last->next = nodeBaruParent;
        LInduk.last = nodeBaruParent;
    }
    cout << "Node parent "<< nodeBaruParent->namaKategoriMakanan << " berhasil ditambahkan kedalam urutan terakhir di list Induk!" << endl;
}

void hapusListAnak(listAnak &LAnak){
    NodeChild nodeBantu = LAnak.first;
    while(nodeBantu != NULL) {
        NodeChild nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasiNodeChild(nodeHapus);
    }
    LAnak.first = LAnak.last = NULL;
}

void deleteAfterParent(listInduk &LInduk, NodeParent nodePrev){
    if(LInduk.first == NULL){
        cout << "List induk kosong!" << endl;
    } else {
        if(nodePrev != NULL && nodePrev->next != NULL){
            NodeParent nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            if (nodeHapus->next != NULL){
                (nodeHapus->next)->prev = nodePrev;
            } else {
                LInduk.last = nodePrev;
            }
            nodeHapus->next = NULL;
            if(nodeHapus->L_Anak.first != NULL){
                hapusListAnak(nodeHapus->L_Anak);
            }
            dealokasiNodeParent(nodeHapus);
            cout << "Node parent setelah node " << nodePrev->namaKategoriMakanan << " berhasil dihapus beserta anak-anaknya!" << endl;
        } else {
            cout << "Node prev tidak valid!" << endl;
        }
    }
}

//operasi pada child
void insertLastChild(listAnak &LAnak, NodeChild nodeBaruChild){
    if(LAnak.first == NULL) {
        LAnak.first = LAnak.last = nodeBaruChild;
    } else {
        nodeBaruChild->prev = LAnak.last;
        LAnak.last->next = nodeBaruChild;
        LAnak.last = nodeBaruChild;
    }
    cout << "Node child "<< nodeBaruChild->namaMakanan << " berhasil ditambahkan kedalam urutan terakhir di list Anak!" << endl;
}

void deleteAfterChild(listAnak &LAnak, NodeChild nodePrev){
    if(LAnak.first == NULL){
        cout << "List anak kosong!" << endl;
    } else {
        if(nodePrev != NULL && nodePrev->next != NULL){
            NodeChild nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            if (nodeHapus->next != NULL){
                (nodeHapus->next)->prev = nodePrev;
            } else {
                LAnak.last = nodePrev;
            }
            nodeHapus->next = NULL;
            dealokasiNodeChild(nodeHapus);
            cout << "Node child setelah node " << nodePrev->namaMakanan << " berhasil dihapus!" << endl;
        } else {
            cout << "Node prev tidak valid!" << endl;
        }
    }
}
void findChildByID(listInduk &LInduk, string IDCari){
    if(LInduk.first == NULL){
        cout << "List induk kosong!" << endl;
    } else {
        NodeParent nodeBantuParent = LInduk.first;
        int indexParent = 1;
        int ketemu = false;
        while(nodeBantuParent != NULL){
            NodeChild nodeBantuChild = nodeBantuParent->L_Anak.first;
            int indexChild = 1;
            while(nodeBantuChild != NULL){
                if(nodeBantuChild->idMakanan == IDCari) {
                    cout << "Data ID child ditemukan pada list anak dari node parent " << nodeBantuParent->namaKategoriMakanan << " pada posisi ke-" << indexChild << "!" << endl;
                    cout << "--- Data Child ---" << endl;
                    cout << "ID Child (ID Makanan) : " << nodeBantuChild->idMakanan << endl;
                    cout << "Posisi dalam list anak : posisi ke-" << indexChild << endl;
                    cout << "Nama Makanan : " << nodeBantuChild->namaMakanan << endl;
                    cout << "---------------------------" << endl;
                    cout << "--- Data Parent ---" << endl;
                    cout << "ID Parent (ID Kategori Makanan): " << nodeBantuParent->idKategoriMakanan << endl;
                    cout << "Posisi dalam list induk : posisi ke-" << indexParent << endl;
                    cout << "Nama Kategori Makanan : " << nodeBantuParent->namaKategoriMakanan << endl;
                    ketemu = true;
                    break;
                } else {
                    nodeBantuChild = nodeBantuChild->next;
                    indexChild++;
                }
            }
            if(ketemu){
                break;
            } else {
                nodeBantuParent = nodeBantuParent->next;
                indexParent++;
            }
        }
        if(!ketemu){
            cout << "Data ID child tidak ditemukan didalam list anak!" << endl;
        }
    }
}

//operasi print
void printStrukturMLL(listInduk &LInduk){
    if(LInduk.first == NULL) {
        cout << "List induk kosong!" << endl;
    } else {
        NodeParent nodeBantuParent = LInduk.first;
        int indexParent = 1;
        while(nodeBantuParent != NULL) {
            cout << "=== Parent " << indexParent << " ===" << endl;
            cout << "ID Kategori Makanan : " << nodeBantuParent->idKategoriMakanan << endl;
            cout << "Nama Kategori Makanan : " << nodeBantuParent->namaKategoriMakanan << endl;

            //print list anak dari node parentnya
            NodeChild nodeBantuChild = nodeBantuParent->L_Anak.first;
            if(nodeBantuChild == NULL) {
                cout << "  (tidak ada child)" << endl;
            } else {
                int indexChild = 1;
                while(nodeBantuChild != NULL) {
                    cout << "  - Child " << indexChild << " :" << endl;
                    cout << "      ID Makanan : " << nodeBantuChild->idMakanan << endl;
                    cout << "      Nama Makanan : " << nodeBantuChild->namaMakanan << endl;
                    nodeBantuChild = nodeBantuChild->next;
                    indexChild++;
                }
            }
            cout << "---------------------------" << endl;
            nodeBantuParent = nodeBantuParent->next;
            indexParent++;
        }
    }
}
```

### file: main.cpp
```C++
#include "multilist.h"
#include <iostream>
using namespace std;

int main(){
    //1. inisialisasi list
    listInduk LInduk;
    createListInduk(LInduk);

    //2. membuat data parent (kategori makanan)
    NodeParent K01 = alokasiNodeParent("K01", "Makanan Berat");
    insertLastParent(LInduk, K01);
    NodeParent K02 = alokasiNodeParent("K02", "Minuman");
    insertLastParent(LInduk, K02);
    NodeParent K03 = alokasiNodeParent("K03", "Dessert");
    insertLastParent(LInduk, K03);
    cout << endl;

    //3. memasukkan data child (menu makanan) ke kategori tertentu
    //isi kategori K01
    NodeChild M01 = alokasiNodeChild("M01", "Nasi Goreng Spesial");
    insertLastChild(K01->L_Anak, M01);
    NodeChild M02 = alokasiNodeChild("M02", "Ayam Bakar Madu");
    insertLastChild(K01->L_Anak, M02);
    //isi kategori K02
    NodeChild D02 = alokasiNodeChild("D02", "Jus Alpukat");
    insertLastChild(K02->L_Anak, D02);
    NodeChild D01 = alokasiNodeChild("D01", "Es Teh Manis");
    insertLastChild(K02->L_Anak, D01);
    //isi kategori K03
    NodeChild S01 = alokasiNodeChild("S01", "Puding Coklat");
    insertLastChild(K03->L_Anak, S01);
    cout << endl;
    
    //4. print mll setelah insert
    printStrukturMLL(LInduk);
    cout << endl;

    //5. searching node child
    findChildByID(LInduk, "D01");
    cout << endl;

    //6. delete node child
    deleteAfterChild(K01->L_Anak, M01); //menghapus node child ayam bakar madu
    cout << endl;

    //7. delete node parent
    deleteAfterParent(LInduk, K02); //menghapus node parent dessert
    cout << endl;

    //8. print mll setelah delete
    printStrukturMLL(LInduk);
    cout << endl;
    return 0;
}
```
Kode ini merupakan pemrograman bahasa C++ yang menggunakan struktur Multi Linked List yang berisi daftar kategori makanan sebagai parent dan daftar menu makanan sebagai child. Program dimulai dengan membuat list induk, menambahkan node parent untuk setiap kategori, lalu memasukkan beberapa node child ke dalam kategori masing masing. Setelah itu struktur MLL ditampilkan. Program juga melakukan pencarian menu berdasarkan ID, menghapus salah satu child dalam kategori, serta menghapus salah satu parent beserta anaknya. Pada akhir program, struktur list dicetak kembali untuk menunjukkan hasil perubahan setelah proses delete.

## Unguided

### 1. Buatlah ADT Multi Linked List sebagai berikut didalam file “MultiLL.h” :
Type Struct golonganHewan <
 idGolongan : String
 namaGolongan : String
>
Type Struct dataHewan < 
 idHewan : String
 namaHewan : String
 habitat : String
 ekor : Boolean //TRUE jika berekor, FALSE jika tidak berekor
 bobot : float //dalam kg
>
typedef struct nodeParent *NodeParent; //alias pointer ke struct 
 nodeParent
typedef struct nodeChild *NodeChild; //alias pointer ke struct 
 nodeChild
Type Struct nodeChild <
 isidata : dataHewan
 next : NodeChild
 prev : NodeChild
>
Type Struct listChild <
 first : NodeChild 
 last : NodeChild
>
Type Struct nodeParent <
 isidata : golonganHewan
 next : NodeParent
 prev : NodeParent
 L_Child : listChild
>
Type Struct listParent <
 first : NodeParent
 last : NodeParent
>
Function isEmptyParent(input/output LParent : listParent) : Boolean
Function isEmptyChild(input/output LChild : listChild) : Boolean
Procedure createListParent(input/output LParent : listParent)
Procedure createListChild(input/output LChild : listChild)
Function allocNodeParent(input idGol : String, namaGol : String) : NodeParent
Function allocNodeChild(input idHwn : String, namaHwn : String, habitat :  String, tail : Boolean, weight : float) : NodeChild
Procedure deallocNodeParent(input/output NParent : NodeParent)
Procedure deallocNodeChild(input/output NChild : NodeChild)
Procedure insertFirstParent(input/output LParent : listParent, newNParent : NodeParent)
Procedure insertLastParent(input/output LParent : listParent, newNParent : NodeParent)
Procedure deleteFirstParent(input/output LParent : listParent)
Procedure deleteAfterParent(input/output LParent : listParent, NPrev : NodeParent)
Procedure insertFirstChild(input/output LChild : listChild, newNChild : NodeChild)
Procedure insertLastChild(input/output LChild : listChild, newNChild : NodeChild)
Procedure deleteFirstChild(input/output LChild : listChild)
Procedure deleteAfterChild(input/output LChild : listChild, NPrev : NodeChild)
Procedure printMLLStructure(input/output LParent : listParent)
Procedure deleteListChild(input/output LChild : listChild)

Kemudian buatlah implementasi ADT Multi Linked List tersebut pada file “MultiLL.cpp”.
Kemudian pada file “main.cpp” lakukan operasi INSERT sebagaimana sehingga bentuk dari multi linked listnya seperti ini :
(https://github.com/savilanf/103112400031_Savila-Nur-Fadilla/blob/main/Pertemuan13_Modul13/soal/soal1.png)

Keterangan isi data setiap node :
❖ List Parent : 
1) idGolongan : G001
namaGolongan : Aves
2) idGolongan : G002
namaGolongan : Mamalia
3) idGolongan : G003
namaGolongan : Pisces
4) idGolongan : G004
namaGolongan : Amfibi
5) idGolongan : G005
namaGolongan : Reptil
❖ List Child G001 : 
1) idHewan : AV001
namaHewan : Cendrawasih
habitat : Hutan
ekor : True
bobot : 0,3
2) idHewan : AV002
namaHewan : Bebek
habitat : Air
ekor : True
bobot : 2
❖ List Child G002 : 
1) idHewan : M001
namaHewan : Harimau
habitat : Hutan
ekor : True
bobot : 200
2) idHewan : M003
namaHewan : Gorila
habitat : Hutan
ekor : False
bobot : 160
3) idHewan : M002
namaHewan : Kucing
habitat : Darat
ekor : True
bobot : 4
❖ List Child G004 : 
1) idHewan : AM001
namaHewan : Kodok
habitat : Sawah
ekor : False
bobot : 0,2

Setelah melakukan INSERT, lakukan operasi PRINT dengan memanggil prosedur printMLLStructure().

### 2. Tambahkan prosedur searchHewanByEkor(input/output LParent : listParent, input tail : Boolean) yang digunakan untuk melakukan operasi SEARCHING hewan-hewan yang memiliki EKOR FALSE (pencarian dilakukan dengan menelusuri list child yang ada pada masing-masing node parent). Kemudian panggil prosedur tersebut pada main.cpp.

### 3. Lakukan operasi DELETE dengan menghapus node G004 yang ada pada list parent (list child dari node tersebut juga terhapus), kemudian lakukan lagi operasi PRINT dengan memanggil prosedur printMLLStructure(). Sehingga bentuk dari multi linked listnya berubah seperti ini :
(https://github.com/savilanf/103112400031_Savila-Nur-Fadilla/blob/main/Pertemuan13_Modul13/soal/soal3.png)

### JAWABAN
### file: MultiLL.h
```C++
#ifndef MULTILL_H
#define MULTILL_H
#include <iostream>
using namespace std;

typedef struct nodeParent *NodeParent; //alias pointer ke struct nodeParent
typedef struct nodeChild *NodeChild; //alias pointer ke struct nodeChild

struct golonganHewan {
    string idGolongan;
    string namaGolongan;
};

struct dataHewan {
    string idHewan;
    string namaHewan;
    string habitat;
    bool ekor;
    float bobot;
};

struct nodeChild{
    dataHewan isidata;
    NodeChild next;
    NodeChild prev;
};

struct listChild {
    NodeChild first;
    NodeChild last;
};

struct nodeParent{
    golonganHewan isidata;
    NodeParent next;
    NodeParent prev;
    listChild L_Child;
};

struct listParent{
    NodeParent first;
    NodeParent last;
};

//deklarasi fungsi dan prosedur
bool isEmptyParent(listParent LParent);
bool isEmptyChild(listChild LChild);

void createListParent(listParent &LParent);
void createListChild(listChild &LChild);

NodeParent allocNodeParent(string idGol, string namaGol);
NodeChild allocNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight);

void deallocNodeParent(NodeParent &NParent);
void deallocNodeChild(NodeChild &NChild);

void insertFirstParent(listParent &LParent, NodeParent newNode);
void insertLastParent(listParent &LParent, NodeParent newNode);
void deleteFirstParent(listParent &LParent);
void deleteAfterParent(listParent &LParent, NodeParent NPrev);

void insertFirstChild(listChild &LChild, NodeChild newNode);
void insertLastChild(listChild &LChild, NodeChild newNode);
void deleteFirstChild(listChild &LChild);
void deleteAfterChild(listChild &LChild, NodeChild NPrev);

void printMLLStructure(listParent LParent);
void deleteListChild(listChild &LChild);

void searchHewanByEkor(listParent LParent, bool tail);

#endif
```

### file: MultiLL.cpp
```C++
#include "MultiLL.h"

bool isEmptyParent(listParent LParent) {
    return (LParent.first == NULL);
}

bool isEmptyChild(listChild LChild) {
    return (LChild.first == NULL);
}

void createListParent(listParent &LParent) {
    LParent.first = NULL;
    LParent.last = NULL;
}

void createListChild(listChild &LChild) {
    LChild.first = NULL;
    LChild.last = NULL;
}

NodeParent allocNodeParent(string idGol, string namaGol) {
    NodeParent NParent = new nodeParent;
    NParent->isidata.idGolongan = idGol;
    NParent->isidata.namaGolongan = namaGol;
    NParent->next = NULL;
    NParent->prev = NULL;

    createListChild(NParent->L_Child);

    return NParent;
}

NodeChild allocNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight) {
    NodeChild NChild = new nodeChild;
    NChild->isidata.idHewan = idHwn;
    NChild->isidata.namaHewan = namaHwn;
    NChild->isidata.habitat = habitat;
    NChild->isidata.ekor = tail;
    NChild->isidata.bobot = weight;

    NChild->next = NULL;
    NChild->prev = NULL;
    return NChild;
}

void deallocNodeParent(NodeParent &NParent) {
    delete NParent;
}

void deallocNodeChild(NodeChild &NChild) {
    delete NChild;
}

void insertFirstParent(listParent &LParent, NodeParent newNode) {
    if (isEmptyParent(LParent)) {
        LParent.first = newNode;
        LParent.last = newNode;
    } else {
        newNode->next = LParent.first;
        LParent.first->prev = newNode;
        LParent.first = newNode;
    }
}

void insertLastParent(listParent &LParent, NodeParent newNode) {
    if (isEmptyParent(LParent)) {
        insertFirstParent(LParent, newNode);
    } else {
        LParent.last->next = newNode;
        newNode->prev = LParent.last;
        LParent.last = newNode;
    }
}

void deleteFirstParent(listParent &LParent) {
    if (!isEmptyParent(LParent)) {
        NodeParent del = LParent.first;

        if (LParent.first == LParent.last) {  
            LParent.first = NULL;
            LParent.last = NULL;
        } else {
            LParent.first = del->next;
            LParent.first->prev = NULL;
        }

        deleteListChild(del->L_Child);
        deallocNodeParent(del);
    }
}

void deleteAfterParent(listParent &LParent, NodeParent NPrev) {
    if (NPrev != NULL && NPrev->next != NULL) {
        NodeParent del = NPrev->next;

        NPrev->next = del->next;
        if (del == LParent.last) {
            LParent.last = NPrev;
        } else {
            del->next->prev = NPrev;
        }

        deleteListChild(del->L_Child);
        deallocNodeParent(del);
    }
}

void insertFirstChild(listChild &LChild, NodeChild newNode) {
    if (isEmptyChild(LChild)) {
        LChild.first = newNode;
        LChild.last = newNode;
    } else {
        newNode->next = LChild.first;
        LChild.first->prev = newNode;
        LChild.first = newNode;
    }
}

void insertLastChild(listChild &LChild, NodeChild newNode) {
    if (isEmptyChild(LChild)) {
        insertFirstChild(LChild, newNode);
    } else {
        LChild.last->next = newNode;
        newNode->prev = LChild.last;
        LChild.last = newNode;
    }
}

void deleteFirstChild(listChild &LChild) {
    if (!isEmptyChild(LChild)) {
        NodeChild del = LChild.first;

        if (LChild.first == LChild.last) {
            LChild.first = NULL;
            LChild.last = NULL;
        } else {
            LChild.first = del->next;
            LChild.first->prev = NULL;
        }

        deallocNodeChild(del);
    }
}

void deleteAfterChild(listChild &LChild, NodeChild NPrev) {
    if (NPrev != NULL && NPrev->next != NULL) {
        NodeChild del = NPrev->next;

        NPrev->next = del->next;
        if (del == LChild.last) {
            LChild.last = NPrev;
        } else {
            del->next->prev = NPrev;
        }

        deallocNodeChild(del);
    }
}

void deleteListChild(listChild &LChild) {
    while (!isEmptyChild(LChild)) {
        deleteFirstChild(LChild);
    }
}

void printMLLStructure(listParent LParent) {
    NodeParent PParent = LParent.first;
    int parentPos = 1;

    while (PParent != NULL) {
        cout << "=== Parent " << parentPos << " ===" << endl;
        cout << "ID golongan : " << PParent->isidata.idGolongan << endl;
        cout << "Nama golongan : " << PParent->isidata.namaGolongan << endl;

        NodeChild PChild = PParent->L_Child.first;

        if (PChild == NULL) {
            cout << "(tidak ada child)" << endl;
        } else {
            int childPos = 1;
            while (PChild != NULL) {
                cout << "- Child " << childPos << " :" << endl;
                cout << "   ID hewan : " << PChild->isidata.idHewan << endl;
                cout << "   Nama hewan : " << PChild->isidata.namaHewan << endl;
                cout << "   Habitat : " << PChild->isidata.habitat << endl;
                cout << "   Ekor : " << (PChild->isidata.ekor ? 1 : 0) << endl;
                cout << "   Bobot : " << PChild->isidata.bobot << endl;
                PChild = PChild->next;
                childPos++;
            }
        }
        cout << "--------------------------" << endl;
        PParent = PParent->next;
        parentPos++;
    }
}

void searchHewanByEkor(listParent LParent, bool tail) {

    NodeParent PParent = LParent.first;
    int parentPos = 1; //posisi parent dimulai 1

    while (PParent != NULL) {

        NodeChild PChild = PParent->L_Child.first;
        int childPos = 1; //posisi child dimulai 1

        while (PChild != NULL) {

            if (PChild->isidata.ekor == tail) {

                cout << "Data ditemukan pada list anak dari node parent "
                     << PParent->isidata.namaGolongan
                     << " pada posisi ke-" << childPos << "!\n";

                cout << "--- Data Child ---" << endl;
                cout << "ID Child : " << PChild->isidata.idHewan << endl;
                cout << "Posisi dalam list anak : posisi ke-" << childPos << endl;
                cout << "Nama Hewan : " << PChild->isidata.namaHewan << endl;
                cout << "Habitat : " << PChild->isidata.habitat << endl;
                cout << "Ekor : " << (PChild->isidata.ekor ? 1 : 0) << endl;
                cout << "Bobot : " << PChild->isidata.bobot << endl;
                cout << "-------------------------" << endl;

                cout << "--- Data Parent ---" << endl;
                cout << "ID Parent : " << PParent->isidata.idGolongan << endl;
                cout << "Posisi dalam list induk : posisi ke-" << parentPos << endl;
                cout << "Nama golongan : " << PParent->isidata.namaGolongan << endl;
                cout << "-------------------------" << endl;
            }
            PChild = PChild->next;
            childPos++;    //ke child berikutnya
        }
        PParent = PParent->next;
        parentPos++; //ke parent berikutnya
    }
}
```

### file: main.cpp
```C++
#include "MultiLL.h"

int main() {
    listParent LParent;
    createListParent(LParent);

    insertLastParent(LParent, allocNodeParent("G001", "Aves"));
    insertLastParent(LParent, allocNodeParent("G002", "Mamalia"));
    insertLastParent(LParent, allocNodeParent("G003", "Pisces"));
    insertLastParent(LParent, allocNodeParent("G004", "Amfibi"));
    insertLastParent(LParent, allocNodeParent("G005", "Reptil"));

    NodeParent PParent;

    PParent = LParent.first; // G001
    insertLastChild(PParent->L_Child, allocNodeChild("AV001", "Cendrawasih", "Hutan", true, 0.3));
    insertLastChild(PParent->L_Child, allocNodeChild("AV002", "Bebek", "Air", true, 2));

    PParent = PParent->next; // G002
    insertLastChild(PParent->L_Child, allocNodeChild("M001", "Harimau", "Hutan", true, 200));
    insertLastChild(PParent->L_Child, allocNodeChild("M003", "Gorila", "Hutan", false, 160));
    insertLastChild(PParent->L_Child, allocNodeChild("M002", "Kucing", "Darat", true, 4));

    PParent = LParent.first->next->next->next; // G004
    insertLastChild(PParent->L_Child, allocNodeChild("AM001", "Kodok", "Sawah", false, 0.2));

    //nomor 1 print struktur MLL
    printMLLStructure(LParent);

    //nomor2 search ekor = false
    searchHewanByEkor(LParent, false);

    //nomor 3 delete G004
    PParent = LParent.first;
    while (PParent != NULL && PParent->isidata.idGolongan != "G004") {
        PParent = PParent->next;
    }

    if (PParent != NULL) {
        if (PParent == LParent.first) {
            deleteFirstParent(LParent);
        } else {
            deleteAfterParent(LParent, PParent->prev);
        }
    }
    printMLLStructure(LParent); //print setelah delete G004
    return 0;
}
```

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/savilanf/103112400031_Savila-Nur-Fadilla/blob/main/Pertemuan13_Modul13/output/output1.png)

Kode dengan bahasa pemrograman C++ yang menggunakan struktur Multi Linked List (MLL) yang terdiri dari list parent dan list child. Setiap node parent menyimpan data golongan hewan dan memiliki sublist berisi node child yang mewakili hewan hewan dalam golongan tersebut. Tipe data parent dan child dibedakan menggunakan struct yang masing masing memuat informasi spesifik. Ada fungsi da prosedur dasar seperti isEmpty, alokasi node, insertFirst/insertLast pada parent dan child, serta membuat list baru digunakan untuk membangun struktur MLL sesuai data pada soal. Setelah seluruh data parent dan child dimasukkan, program memanggil prosedur printMLLStructure() untuk menampilkan isi MLL secara runtut, mulai dari parent ke 1 sampai parent terakhir, beserta seluruh child yang berada di bawahnya.

##### Output 2
![Screenshot Output Unguided 2_1](https://github.com/savilanf/103112400031_Savila-Nur-Fadilla/blob/main/Pertemuan13_Modul13/output/output2.png)

Kode dengan bahasa pemrograman C++ yang menggunakan struktur Multi Linked List (MLL), bagian ini menambahkan prosedur searchHewanByEkor() yang melakukan penelusuran ke seluruh node parent, lalu masuk ke setiap list child untuk mencari hewan yang memiliki status ekor FALSE. Pencarian dilakukan secara linear, dimulai dari parent paling awal. Jika ditemukan, program menampilkan informasi lengkap mengenai posisi parent di list, posisi child, detail data hewan yang ditemukan, serta menampilkan data parent tempat child tersebut berada. Prosedur ini untuk melihat hewan mana saja yang memenuhi kriteria pencarian (ekornya FALSE).

##### Output 3
![Screenshot Output Unguided 3_1](https://github.com/savilanf/103112400031_Savila-Nur-Fadilla/blob/main/Pertemuan13_Modul13/output/output3.png)

Kode dengan bahasa pemrograman C++ yang menggunakan struktur Multi Linked List (MLL), di bagian ini program melakukan operasi delete terhadap node parent G004, yaitu golongan "Amfibi". Penghapusan dilakukan menggunakan prosedur deleteFirstParent() atau deleteAfterParent(), tergantung posisi node G004 dalam list. Proses delete tidak hanya menghilangkan node parent, tetapi juga menghapus seluruh node child yang berada pada sublist parent tersebut melalui prosedur deleteListChild(). Setelah operasi penghapusan selesai, program memanggil printMLLStructure() untuk menampilkan MLL yang telah berubah (setelah G004 nya dihapus).

## Kesimpulan
Laporan Praktikum Struktur Data Modul 13 ini menggunakan bahasa pemrograman C++ dan membahas penerapan struktur data Multi Linked List (MLL) dengan konsep ADT (Abstract Data Type). MLL merupakan lanjutan dari linked list yang menghubungkan satu list induk (parent) dengan list anak (child) sehingga mampu merepresentasikan hubungan hierarki antar data. Pada praktikum ini, mahasiswa dilatih mengimplementasikan operasi dasar MLL seperti pembuatan list, alokasi node parent dan child, penyisipan node pada list induk maupun list anak, pencarian data berdasarkan kriteria tertentu (misalnya status ekor, ID, dll), serta penghapusan node parent beserta seluruh child yang dimilikinya. Melalui penerapan ADT, program menjadi lebih terstruktur, modular, dan mudah dikembangkan untuk berbagai kebutuhan pengelolaan data yang memiliki relasi bertingkat.

## Referensi 
[1] Jagadish, H. V., Lakshmanan, L. V. S., Srivastava, D., & Thompson, K. (2002). Optimizing Queries over Nested Relational Data. ACM SIGMOD Record.

[2] Dietz, P. F. (1989). Maintaining Order in a Linked List. ACM Transactions on Programming Languages and Systems (TOPLAS).

[3] Buneman, P. (1997). Semistructured Data. ACM SIGMOD Record.

[4] Informatics Laboratory. (n.d.). *Modul 13 – Multi Linked List*. Program Studi Teknik Informatika, Telkom University.