# <h1 align="center">Laporan Praktikum Modul 2 - Pengenalan Bahasa C++ (Bagian Kedua)</h1>
<p align="center">Savila Nur Fadilla - 103112400031</p>

## Dasar Teori
### A. Array<br/>
Array adalah kumpulan data yang terstruktur dengan nama variable sama dan bertipe sama tetapi mempunyai indeksnya beda. Setiap variable dapat berisi data yang sama atau berbeda tetapi tipe data harus sama. Urutan indeks array dimulai dari hitungan 0,1,2 dst [1]. 

Deklarasi array:
Tipe_data nama_array[dimensi_array]

Dimensi array menyatakan banyaknya data menyatakan indeks variable. Misalnya int A[20], artinya variable array A dapat menampung 20 + 1 tipe integer.

#### Jenis Array
#### 1. Array satu dimensi
Rumus kueri untuk array satu dimensi [2]:

tipe_elemen_array nama_array[jumlah_elemen_array];

int HurufVokal[5];

#### 2. Array dua dimensi
Array dua dimensi menggunakan dua elemen dan perlu memasukkan dua elemen. Biasanya, jenis data Array ini berfungsi untuk menampilkan sebuah data dengan dua jenis elemen yang berbeda. Rumus kueri array dua dimensi [3]:

tipe_elemen_array nama_array[jumlah_baris_array][jumlah_kolom_array];

contoh:
int Karyawan [4][3];

Nb: 4 merupakan jumlah karyawan dan 3 adalah jumlah karywan yangmemiliki komputer.

### B. Pointer<br/>
Pointer adalah alamat yang merujuk ke lokasi di memori. Pointer sering digunakan untuk memungkinkan fungsi atau struktur data mengetahui dan memodifikasi memori tanpa perlu menyalin memori yang dirujuk. Pointer dapat digunakan baik tipe primitif (bawaan) maupun tipe yang didefinisikan pengguna. Pointer menggunakan operator “dereference” *, “address of” &, dan “arrow” ->. Operator ‘*’ dan ‘->’ digunakan untuk mengakses memori yang dituju, sedangkan operator & digunakan untuk mendapatkan alamat di memori [4].

#### Operasi pointer
Ada dua operator pointer: Address-of operator (&): mengembalikan alamat memori dari operandnya.
Deference operator (*): mengembalikan nilai variabel yang terletak di alamat yang ditentukan oleh
operatornya.

int var = 20;
int *ptr;
ptr = &var;
cout << var << endl;
//Outputs 20 (The value of var)
cout << ptr << endl;
//Outputs 0x234f119 (var's memory location)
cout << *ptr << endl;
//Outputs 20(The value of the variable stored in the pointer ptr)

Tanda  (*) digunakan dalam mendeklarasikan pointer untuk tujuan sederhana yaitu menunjukkan bahwa itu adalah pointer, digunakan untuk mendapatkan nilai yang terletak di alamat yang ditentukan. Keduanya hanyalah dua hal yang berbeda yang diwakili oleh tanda yang sama.

#### Pointer basic atau dasar
Creating a pointer variable : variabel pointer dapat dibuat menggunakan sintaks khusus *, misalnya int *pointer_to_int;.
Ketika suatu variabel bertipe pointer (int *), variabel tersebut hanya menyimpan alamat memori. Alamat memori tersebut adalah lokasi di mana data bertipe dasar (int) disimpan.

#### Pointer arithmetic
Increment / Decrement : pointer dapat ditambah atau dikurangi (prefix dan postfix). Menambah nilai pointer akan memajukan nilai Pointer ke elemen berikutnya dalam array setelah elemen yang saat ini ditunjuk. Mengurangi nilai pointer akan memindahkannya ke elemen sebelumnya dalam array.

Addition / Subtraction : nilai integer dapat ditambahkan ke pointer; mereka berfungsi sebagai penambahan,
nilai integer juga dapat dikurangkan dari pointer, berfungsi sebagai pengurangan.

Pointer Differencing : perbedaan antara dua pointer ke tipe yang sama dapat dihitung. Kedua pointer tersebut harus berada dalam objek array yang sama.

### C. Fungsi<br/>
Fungsi merupakan subprogram yang berguna untuk membentuk program sehingga lebih sederhana, mudah dipahami dan dapat digunakan berulang kali. Pada bahasa pemrograman C++, fungsi dibedakan menjadi dua, yaitu user- defined function dan built-in function. User-defined function adalah fungsi yang idefenisikan sendiri, sedangkan built-in function adalah fungsi siap pakai yang telah disediakan oleh compiler [5].

Bentuk umum fungsi:
Tipedata namafungsi(daftarparameter) 
{ 
    /*Badan Fungsi*/ return nilaireturn; /* untuk tipe data bukan void */ 
}

### D. Prosedur atau Void<br/>
Kata kunci void dapat digunakan sebagai penentu tipe untuk menunjukkan ketidakhadiran tipe atau daftar parameter fungsi untuk menunjukkan bahwa fungsi tersebut tidak menerima parameter. Ketika digunakan sebagai penentu tipe, kata kunci void paling sering digunakan sebagai tipe kembalian fungsi untuk menunjukkan bahwa fungsi tersebut tidak mengembalikan nilai. Kata kunci void juga digunakan sebagai penunjuk generik (misalnya, void*), meskipun penggunaan ini kurang umum dalam C++ dibandingkan dalam C. C++ tidak mewajibkan penggunaan kata kunci void untuk menunjukkan bahwa suatu fungsi tidak memiliki parameter, tetapi kata kunci ini sering digunakan untuk kompatibilitas dengan C [6].

contoh:
void func(void)
{
  std::cout << "hello, world\n";
}

### E. Parameter Fungsi<br/>
Dalam C++, data dapat dikirim ke fungsi saat fungsi tersebut dipanggil untuk melakukan operasi yang ini disebut parameter atau argumen [7]. 

#### Metode
#### 1. Call by value
Dalam metode pass by value, nilai variabel disalin kemudian diteruskan ke fungsi. Akibatnya, perubahan apa pun pada parameter di dalam fungsi tidak akan memengaruhi nilai asli variabel di pemanggil. Metode ini sederhana, mudah dipahami, dan diimplementasikan, tetapi tidak disarankan untuk struktur data berukuran besar karena ada penyalinan nilai.
#### 2. Call by reference
Dalam metode pass-by-reference, kita meneruskan referensi argumen ke fungsi. Hal ini memungkinkan fungsi untuk mengubah nilai argumen asli. Hal ini berguna ketika kita perlu meneruskan data berukuran besar.
#### 3. Call by pointer
Metode pass-by-pointer sangat mirip dengan metode pass-by-reference. Perbedaannya hanya terletak pada cara kita meneruskan alamat mentah argumen sebagai parameter ke fungsi, bukan sebagai referensi.

## Guided 

### 1. array and pointer

```C++
#include <iostream>
using namespace std;
//indeks ke3, elemen ke4

int main(){
    int arr[] = {10,20,30,40,50};
    int* ptr = arr; //pointer yang menunjuk ke elemen pertama array

    //mengakses elemen array menggunakan pointer
    for(int i = 0; i < 5; ++i){
        cout << "elemen array ke-"<< i+1 << " menggunakan pointer: " << *(ptr + i) << endl; 
    }

    //mengakses elemen array menggunakan indeks
    for(int i = 0; i < 5; ++i){
        cout << "elemen array ke-" << i+1 << " menggunakan indeks: " << arr[i] << endl;
    }
    return 0;
}
```
Kode dengan bahasa pemrograman C++ yang bertujuan untuk mengakses array menggunakan 2 cara, yaitu dengan pointer dan indeks. Bagian include iostream itu untuk memasukkan file header iostream. Kemudian program menjalanlan fungsi main, di situ program mengakses elemen array yang pertama dengan pointer dulu dan selanjutnya dengan indeks, lalu return 0 berarti program selesai. Outputnya berupa string "elemen array ke-sekian menggunakan pointer" dan "elemen array ke-sekian menggunakan indeks".

## Unguided 

### 1. Diketahui 2 buah matriks 3x3 seperti dibawah ini:   
matriksA : 
           7   12   22
          31    6   41
          15   19   36

matriksB : 
          11   34    7
           3   25   41
           5   18   33

Buatlah program yang dapat melakukan operasi penjumlahan, pengurangan, dan perkalian matriks 3x3 tersebut. Buat prosedur untuk masing-masing operasi yang dilakukan; jumlahMatriks() untuk operasi penjumlahan, kurangMatriks() untuk pengurangan, dan kaliMatriks() untuk perkalian. Buat program tersebut menggunakan menu switch-case seperti berikut ini :
--- Menu Program Matriks ---
1. Penjumlahan matriks
2. Pengurangan matriks
3. Perkalian matriks
4. Keluar

```C++
#include <iostream>
using namespace std;

void tampilkanHasil(int arr[3][3]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void jumlahMatriks(int arrA[3][3], int arrB[3][3], int arrC[3][3]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            arrC[i][j] = arrA[i][j] + arrB[i][j];
        }
    }
}

void kurangMatriks(int arrA[3][3], int arrB[3][3], int arrC[3][3]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            arrC[i][j] = arrA[i][j] - arrB[i][j];
        }
    }
}

void kaliMatriks(int arrA[3][3], int arrB[3][3], int arrC[3][3]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            arrC[i][j] = 0; 
            for(int k = 0; k < 3; k++){
                arrC[i][j] += arrA[i][k] * arrB[k][j];
            }
        }
    }
}

int main(){
    int arrA[3][3] = {
        {7, 12, 22},
        {31, 6, 41},
        {15, 19, 36}
    };
    int arrB[3][3] = {
        {11, 34, 7},
        {3, 25, 41},
        {5, 18, 33}
    };
    int arrC[3][3];

    int menu;
    cout << "\n--- MENU OPERASI MATRIKS ---" << endl;
    cout << "1. Penjumlahan matriks" << endl;
    cout << "2. Pengurangan matriks" << endl;
    cout << "3. Perkalian matriks" << endl;
    cout << "4. Keluar" << endl;
    cout << "Pilih (1-4): ";
    cin >> menu;
    switch(menu){
        case 1:
            jumlahMatriks(arrA, arrB, arrC);
            cout << "\nHasil penjumlahan matriks A dan B:\n";
            tampilkanHasil(arrC);
            break;
        case 2:
            kurangMatriks(arrA, arrB, arrC);
            cout << "\nHasil pengurangan matriks A dan B:\n";
            tampilkanHasil(arrC);
            break;
        case 3:
            kaliMatriks(arrA, arrB, arrC);
            cout << "\nHasil perkalian matriks A dan B:\n";
            tampilkanHasil(arrC);
            break;
        case 4:
            cout << "Keluar dari program.\n";
            break;
        default:
            cout << "Pilihan tidak valid\n";
    }
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/savilanf/103112400031_Savila-Nur-Fadilla/blob/main/Pertemuan2_Modul2/output1-unguided1.png)

##### Output 2
![Screenshot Output Unguided 1_2](https://github.com/savilanf/103112400031_Savila-Nur-Fadilla/blob/main/Pertemuan2_Modul2/output2-unguided1.png)

Kode dengan bahasa pemrograman C++ yang bertujuan untuk melakukan operasi penjumlahan, pengurangan, dan perkalian matriks 3x3. Bagian include iostream itu untuk memasukkan file header iostream. Kemudian program menjalanlan fungsi main, di fungsi main ada array A, B, dan C yang sudah diinput dan dimasukkan elemennya berdasarkan soal, lalu ada switch case untuk kita memilih case mau menu yang mana. Kemudian program menghitung penjumlahan, pengurangan, atau perkalian matriks tersebut dengan rumus yang kita masukkan di masing masing prosedur. Masing-masing operasi dibuat prosedurnya sendiri sendiri, jumlahMatriks() untuk operasi penjumlahan, kurangMatriks() untuk pengurangan, dan kaliMatriks() untuk perkalian. Outputnya berupa hasil penjumlahan, pengurangan, atau perkalian matriks .

### 2. Buatlah program menghitung luas dan keliling persegi panjang dengan proses perhitungan dan perubahan nilainya menggunakan pointer, seperti berikut: 
1) Buatlah 3 variabel integer di fungsi main(): panjang (beri nilai 10), lebar (beri nilai 5), dan luas (beri nilai 0). 
2) Deklarasikan dua pointer: ptrPanjang yang menunjuk ke variabel panjang, dan ptrLebar yang menunjuk ke variabel lebar.  
3) Hitung luas persegi panjang tersebut dan simpan hasilnya ke dalam variabel luas. 
Syarat: Proses perhitungan ini wajib menggunakan ptrPanjang dan ptrLebar. 
4) Cetak nilai luas ke layar. 
5) Setelah itu, ubah nilai panjang menjadi 12 dan lebar menjadi 6, juga hanya melalui  pointer ptrPanjang dan ptrLebar. 
6) Cetak nilai panjang dan lebar yang baru untuk membuktikan bahwa nilainya telah berubah. 

```C++
#include <iostream>
using namespace std;

void ubahNilai(int *ptrPanjang, int *ptrLebar, int &refLuas, int &refKeliling){
    refLuas = (*ptrPanjang) * (*ptrLebar);
    refKeliling = 2 * ((*ptrPanjang) + (*ptrLebar));

}

int main(){
    int panjang = 10;
    int lebar = 5;
    int luas = 0;
    int keliling = 0;
    cout << "\n--- Nilai Awal ---" << endl;
    cout << "Panjang: " << panjang << endl;
    cout << "Lebar: " << lebar << endl;
    ubahNilai(&panjang, &lebar, luas, keliling);
    cout << "\n--- Hasil Perhitungan ---" << endl;
    cout << "Luas persegi panjang: " << luas << endl;
    cout << "Keliling persegi panjang: " << keliling << endl;
    cout << "\n--- Nilai Setelah Diubah Melalui Pointer ---" << endl;
    cout << "Panjang baru: ";
    cin >> panjang;
    cout << "Lebar baru: ";
    cin >> lebar;
    ubahNilai(&panjang, &lebar, luas, keliling);
    cout << "Luas baru: " << luas << endl;
    cout << "Keliling baru: " << keliling << endl;
    return 0;
}
```
### Output Unguided 2 :

##### Output
![Screenshot Output Unguided 2_1](https://github.com/savilanf/103112400031_Savila-Nur-Fadilla/blob/main/Pertemuan2_Modul2/output-unguided2.png)

Kode dengan bahasa pemrograman C++ yang bertujuan untuk menghitung luas dan keliling persegi panjang dengan proses perhitungan dan perubahan nilainya menggunakan pointer. Bagian include iostream itu untuk memasukkan file header iostream. Kemudian program menjalanlan fungsi main, di fungsi main ada deklarasi variabel bertipe integer, panjang = 10 dan lebar = 5. Kemudian program memberikan string "Nilai awal", lalu ada string "Hasil perhitungan", kemudian string "nilai setelah diubah", di sini kita diminta input panjang dan lebar baru, ada juga prosedur ubahNilai untuk menghitung luas dan keliling, lalu return 0 berarti program selesai. Output berupa nilai setelah diubah menggunakan pointer. 

## Kesimpulan
Laporan Praktikum Struktur Data Modul 2 ini menggunakan kode bahasa pemrograman C++. Dasar-dasar C++ seperti fungsi, parameter fungsi, dan array itu penting untuk membuat program yang rapi dan mudah dipahami. Dengan fungsi, kode jadi lebih terstruktur. Array, baik satu dimensi maupun dua dimensi, mempermudah kita menyimpan dan mengolah data dalam jumlah banyak. Cara mengirim data ke fungsi lewat parameter (by value, by reference, atau by pointer) juga memengaruhi hasil program dan cara data diproses. Jadi, praktikum ini membuat kita lebih paham gimana cara kerja dasar C++ dan kenapa konsep ini jadi pondasi penting sebelum lanjut ke materi yang lebih sulit.

## Referensi

[1] Stroustrup, B. (1996). *A History of C++: 1979–1991*. Dalam T. J. Bergin & R. G. Gibson (Eds.), *History of Programming Languages II* (hlm. 699–769). New York: ACM Press. https://doi.org/10.1145/234286.1057836  

[2] Sianipar, R. H. (2012). *Pemrograman C++: Dasar Pemrograman Berorientasi Objek*. Yogyakarta: Penerbit ANDI. ISBN 979-293-1848 / 978-979-293-1846.  

[3] Syafii. (2018). *Pemrograman Komputer*. Padang: Universitas Andalas. http://repo.unand.ac.id/32011/1/Buku_Pemograman_Komputer_Syafii.pdf  

[4] Modul PB 7 – Array 1 Dimensi. (n.d.). *Modul PB 7 – Array 1 Dimensi*. Diakses dari https://lmsspada.kemdiktisaintek.go.id/pluginfile.php/679155/mod_resource/content/5/Modul%20PB%207%20-%20Array%201%20Dimensi.pdf  

[5] Modul PB 8 – Array 2 Dimensi. (n.d.). *Modul PB 8 – Array 2 Dimensi*. Diakses dari https://lmsspada.kemdiktisaintek.go.id/pluginfile.php/679163/mod_resource/content/6/Modul%20PB%208%20-%20Array%202%20Dimensi.pdf  

[6] Lischner, R. (2003, Mei). *C++ In a Nutshell*. O’Reilly Media. Diakses dari https://www.oreilly.com/library/view/c-in-a/059600298X/  

[7] GeeksforGeeks. (2025, 20 September). *Parameter Passing Techniques in C++*. Diakses dari https://search.app/hrXytCQWhnuWAyaa7  