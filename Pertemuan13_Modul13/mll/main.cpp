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