# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Pertama)</h1>
<p align="center">Savila Nur Fadilla - 103112400031</p>

## Dasar Teori
### A. History C++<br/>
Sejarah pemrograman C++ lebih menekankan pada gagasan, ide, serta tokoh yang membentuk bahasa tersebut. Evolusi C++ berawal dari “C with Classes” hingga mencapai tahap standarisasi ANSI/ISO, bersamaan dengan meningkatnya penggunaan, minat, aktivitas komersial, alat, kompiler, lingkungan, dan perpustakaan [1]. 

### B. Aritmatika<br/>
Berikut adalah operator-operator aritmatika dasar C++ [2].
#### 1. Penjumlahan (+)
#### 2. Pengurangan (-)
#### 3. Perkalian (*)
#### 4. Pembagian (/)
#### 5. Modulus atau sisa bagi (%)

### C. Percabangan<br/>
Digunakan untuk memecahkan masalah, mengambil keputusan di antara sejumlah pilihan yang ada. Percabangan C++ terdiri dari [3].
#### 1. if
Bentuk umum if
if (kondisi) {
    pernyataan;
}

#### 2. if-else
Bentuk umum if-else
if (kondisi) {
    pernyataan1;
} else {
    pernyataan2;
}

#### 3. switch-case
Bentuk umum switch-case
switch (syarat) {
    case konstanta1:
        pernyataan1;
        break;
    case konstanta2:
        pernyataan2;
        break;
default:
    perintah;
}

### D. Perulangan<br/>
Looping adalah salah satu instruksi logika dasar yang digunakan untuk mengulang blok pernyataan. Semua bahasa pemrograman menggunakan struktur looping untuk menyederhanakan program. Struktur looping didukung oleh semua bahasa pemrograman modern, meskipun implementasi dan sintaksisnya mungkin berbeda [4].

#### 1. while loop
Konstruksi while terdiri dari blok kode dan kondisi boolean.

while (boolean condition) {
    // statements
}

#### 2. do while loop
Konstruksi do while terdiri dari blok kode dan kondisi.

do {
    // statements;}
while (boolean condition);

#### 3. for loop
Dalam pendekatan tradisional, biasanya sebuah variabel diambil dan diinisialisasi ke nilai yang diinginkan, yang dapat digunakan baik untuk memeriksa kondisi eksekusi maupun memperbarui variabel tersebut[5].

for (initialization; condition; update) {
    // statements
}

### E. Struct<br/>
Bahasa C++ menyediakan banyak struktur data yang dapat diimplementasikan oleh programmer untuk memenuhi kebutuhan spesifik aplikasi mereka. Struktur data tersebut masing-masing memiliki karakteristik unik yang membuatnya lebih cocok untuk jenis masalah tertentu [6].

Tipe data struct:
#### 1. Array
Array adalah struktur data yang paling sederhana dan paling sering digunakan. Array memungkinkan penyimpanan elemen-elemen dengan tipe data yang sama dalam urutan berurutan di memori.
#### 2. Linked List
Linked list adalah struktur data yang memungkinkan penyimpanan dinamis elemen-elemen, di mana setiap elemen yang disebut node mengandung referensi (link) ke elemen berikutnya.
#### 3. Stack and Queue 
#### 4. Hash Table
#### 5. Trees

Structural components:
#### 1. Members
Variabel yang didefinisikan di dalam struktur.
#### 2. Instance
Variabel yang dideklarasikan dengan tipe struktur.

## Guided 

### 1. hello world

```C++
#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
```
Kode dengan bahasa pemrograman C++ yang bertujuan untuk menampilkan teks atau string berupa "Hello,World!". Bagian include iostream itu untuk memasukkan file header iostream. Kemudian program menjalanlan func main, lalu mencetak string "Hello, World!", lalu return 0 berarti program selesai. Outputnya berupa string "Hello, World!".

### 2. aritmatika

```C++
#include <iostream>
using namespace std;

int main(){
    int angka1, angka2; //deklarasi variabel
    cout << "Masukkan angka 1: "; 
    cin >> angka1; //masukin input 1
    cout << "Masukkan angka 2: ";
    cin >> angka2; //masukin input 2

    cout << "Hasil Penjumlahan: " << angka1 + angka2 << endl;
    cout << "Hasil Pengurangan: " << angka1 - angka2 << endl;
    cout << "Hasil Perkalian: " << angka1 * angka2 << endl;
    cout << "Hasil Pembagian: " << angka1 / angka2 << endl;
    cout << "Sisa Bagi: " << angka1 % angka2 << endl;
    return 0;
}
```
Kode dengan bahasa pemrograman C++ yang bertujuan untuk menghitung hasil penjumlahan, pengurangan, perkalian, pembagian, dan modulus atau sisa bagi. Bagian include iostream itu untuk memasukkan file header iostream. Kemudian program menjalanlan func main, di func main ada deklarasi variabel bertipe integer. Kita diminta input 2 angka, angka1 sama angka2. Kemudian program menghitung dengan rumus yang kita masukkan, lalu return 0 berarti program selesai. Outputnya berupa hasil penjumlahan, pengurangan, perkalian, pembagian, dan modulus atau sisa bagi.

### 3. if-else

```C++
#include <iostream>
using namespace std;

int main(){
    int angka1, angka2; //deklarasi variabel
    cout << "Masukkan angka 1: "; 
    cin >> angka1; //masukin input 1
    cout << "Masukkan angka 2: ";
    cin >> angka2; //masukin input 2

    if(angka1 <angka2){
        cout <<  angka1 << " kurang dari " << angka2 << endl;
    } else{
        cout << angka1 << " lebih dari " << angka2 << endl;
    }

    if(angka1 == angka2){
        cout << angka1 << " sama dengan " << angka2 << endl;
    } else if(angka1 != angka2){
        cout << "angka berbeda" << endl;
    }

    int pilihan;
    cout << "MENU" << endl;
    cout << "1. Penjumlahan" << endl;
    cout << "2. Pengurangan" << endl;
    cout << "Masukkan pilihan : " << endl;
    cin >> pilihan;

    int penjumlahan = angka1 + angka2;

    switch (pilihan){
        case 1:
            cout << "Hasil Penjumlahan: " << penjumlahan << endl;
            break;
        case 2:
            cout << "Hasil Pengurangan: " << angka1 - angka2 << endl;
            break;
        default:
            cout << "Pilihan salah" << endl;
            break;
    }
    return 0;
}
```
Kode dengan bahasa pemrograman C++ yang bertujuan untuk menentukan apakah angka1 lebih dari/kurang dari angka2, lalu kedua angka sama dengan/angka berbeda. Bagian include iostream itu untuk memasukkan file header iostream. Kemudian program menjalanlan func main, di func main ada deklarasi variabel bertipe integer. Kita diminta input 2 angka, angka1 sama angka2. Kemudian ada if-else, program menentukan angka yang kita input. Kemudian bagian MENU ada switch-case, kita memilih mau case yang mana, (penjumlahan atau pengurangan), program menghitung dengan rumus yang kita masukkan, lalu return 0 berarti program selesai.

### 4. input output

```C++
#include <iostream>
using namespace std; //biar simple biar ga nulis std::cout <<

int main(){
    int angka; //deklarasi variabel
    cout << "Masukkan angka: ";
    cin >> angka;
    cout << "Angka yang dimasukkan: " << angka << endl;
    return 0;
}
```
Kode dengan bahasa pemrograman C++ yang bertujuan untuk menampilkan angka yang kita input. Bagian include iostream itu untuk memasukkan file header iostream. Kemudian program menjalanlan func main, di func main ada deklarasi variabel bertipe integer. Kita diminta input 1 angka. Kemudian program menampilkan angka yang kita input, lalu return 0 berarti program selesai. Outputnya berupa angka yang kita input.

### 5. perulangan

```C++
#include <iostream>
using namespace std;

int main(){
    int angka1; //deklarasi variabel
    cout << "Masukkan angka 1: ";
    cin >> angka1; //masukin input 1
    
    for(int i = 0; i < angka1; i++){ //increment
        cout << i << " - " ;
    }

    cout << endl;

    int j = 10;
    while (j > angka1){ //decrement
        cout << j << " - ";
        j--;
    }

    cout << endl;
    
    int k = 10;
    do{
        cout << k << " - ";
        k++;
    } while (k < angka1);       

return 0;
}
```
Kode dengan bahasa pemrograman C++ yang bertujuan untuk menampilkan perulangan dengan for, while, dan do while. Bagian include iostream itu untuk memasukkan file header iostream. Kemudian program menjalanlan func main, di func main ada deklarasi variabel bertipe integer. Kita diminta input 1 angka. Kemudian program melakukan perulangan, for (increment), while (decrement), do while (jalan dulu baru dicek, di program kita tulis nilai k int=10), lalu return 0 berarti program selesai. Outputnya berupa perulangan for (increment), while (decrement), dan do while dari angka yang kita input.

### 6. struct

```C++
#include <iostream>
using namespace std;

int main(){
    const int MAX = 5;
    struct rapot{
        char nama[5];
        float nilai;
    };
    rapot siswa[MAX];

    for(int i = 0; i < MAX; i++){
        cout << "Masukkan nama siswa: ";
        cin >> siswa[i].nama;
        cout << "Masukkan nilai siswa: ";
        cin >> siswa[i].nilai;
        cout << endl;
    }

    int j = 0;
    while(j < MAX){
        cout << "Nama siswa: " << siswa[j].nama << " ,Nilai siswa: " << siswa[j].nilai << endl;
        j++;
    }
    return 0;
}
```
Kode dengan bahasa pemrograman C++ yang bertujuan untuk menampilkan nama siswa dan nilai siswa yang kita input. Bagian include iostream itu untuk memasukkan file header iostream. Kemudian program menjalanlan func main, di func main kita menyimpan data sruct. Lalu kita diminta input nama dan nilai, inputnya 5 (di struct const MAX nya 5). Kemudian program menampilkan nama dan nilainya yang kita input, lalu return 0 berarti program selesai. Outputnya berupa nama dan nilai dari kelima siswa.

## Unguided 

### 1. Buatlah program yang menerima input-an dua buah bilangan betipe float, kemudian memberikan output-an hasil penjumlahan, pengurangan, perkalian, dan pembagian dari dua bilangan tersebut.

```C++
#include <iostream>
using namespace std;

int main(){
    float bil1, bil2;
    cout << "Masukkan bilangan 1: ";
    cin >> bil1;
    cout << "Masukkan bilangan 2: ";
    cin >> bil2;

    cout << "Hasil penjumlahan: " << bil1 + bil2 << endl;
    cout << "Hasil pengurangan: " << bil1 - bil2 << endl;
    cout << "Hasil perkalian: " << bil1 * bil2 << endl;
    cout << "Hasil pembagian: " << bil1 / bil2 << endl;
    return 0;
}
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/savilanf/103112400031_Savila-Nur-Fadilla/blob/main/Pertemuan1_Modul1/output1-unguided1.png)

##### Output 2
![Screenshot Output Unguided 1_2](https://github.com/savilanf/103112400031_Savila-Nur-Fadilla/blob/main/Pertemuan1_Modul1/output2-unguided1.png)

Kode dengan bahasa pemrograman C++ yang bertujuan untuk menghitung hasil penjumlahan, pengurangan, perkalian, pembagian. Bagian include iostream itu untuk memasukkan file header iostream. Kemudian program menjalanlan func main, di func main ada deklarasi variabel bertipe float. Kita diminta input 2 bilangan, bil1 sama bil2. Kemudian program menghitung dengan rumus yang kita masukkan, lalu return 0 berarti program selesai. Outputnya berupa hasil penjumlahan, pengurangan, perkalian, pembagian.

### 2. Buatlah sebuah program yang menerima masukan angka dan mengeluarkan output nilai angka tersebut dalam bentuk tulisan. Angka yang akan di- input-kan user adalah bilangan bulat positif mulai dari 0 s.d 100

```C++
#include <iostream>
using namespace std;

int main(){
    int angka;
    cout << "Masukkan angka: ";
    cin >> angka;
    if (angka < 0 || angka > 100) {
        cout << "error, angka tidak valid" << endl;
        return 0;
    } else if (angka == 100) {
        cout << "seratus" << endl;
    } else if (angka == 0) {
        cout << "nol" << endl;
    } else if (angka == 1) {
        cout << "satu" << endl;
    } else if (angka == 2) {
        cout << "dua" << endl;
    } else if (angka == 3) {
        cout << "tiga" << endl;
    } else if (angka == 4) {
        cout << "empat" << endl;
    } else if (angka == 5) {
        cout << "lima" << endl;
    } else if (angka == 6) {
        cout << "enam" << endl;
    } else if (angka == 7) {
        cout << "tujuh" << endl;
    } else if (angka == 8) {
        cout << "delapan" << endl;
    } else if (angka == 9) {
        cout << "sembilan" << endl;
    } else if (angka == 10) {
        cout << "sepuluh" << endl;
    } else if (angka == 11) {
        cout << "sebelas" << endl;
    } else if (angka == 12) {
        cout << "dua belas" << endl;
    } else if (angka == 13) {
        cout << "tiga belas" << endl;
    } else if (angka == 14) {
        cout << "empat belas" << endl;
    } else if (angka == 15) {
        cout << "lima belas" << endl;
    } else if (angka == 16) {
        cout << "enam belas" << endl;
    } else if (angka == 17) {
        cout << "tujuh belas" << endl;
    } else if (angka == 18) {
        cout << "delapan belas" << endl;
    } else if (angka == 19) {
        cout << "sembilan belas" << endl;
    } else if (angka == 20) {
        cout << "dua puluh" << endl;
    } else if (angka == 30) {
        cout << "tiga puluh" << endl;
    } else if (angka == 40) {
        cout << "empat puluh" << endl;
    } else if (angka == 50) {
        cout << "lima puluh" << endl;
    } else if (angka == 60) {
        cout << "enam puluh" << endl;
    } else if (angka == 70) {
        cout << "tujuh puluh" << endl;
    } else if (angka == 80) {
        cout << "delapan puluh" << endl;
    } else if (angka == 90) {
        cout << "sembilan puluh" << endl;
    } 

    else {
        int puluhan = angka / 10;
        int satuan = angka % 10;

        if (puluhan == 2) cout << "dua puluh";
        else if (puluhan == 3) cout << "tiga puluh";
        else if (puluhan == 4) cout << "empat puluh";
        else if (puluhan == 5) cout << "lima puluh";
        else if (puluhan == 6) cout << "enam puluh";
        else if (puluhan == 7) cout << "tujuh puluh";
        else if (puluhan == 8) cout << "delapan puluh";
        else if (puluhan == 9) cout << "sembilan puluh";

        if (satuan == 1) cout << " satu";
        else if (satuan == 2) cout << " dua";
        else if (satuan == 3) cout << " tiga";
        else if (satuan == 4) cout << " empat";
        else if (satuan == 5) cout << " lima";
        else if (satuan == 6) cout << " enam";
        else if (satuan == 7) cout << " tujuh";
        else if (satuan == 8) cout << " delapan";
        else if (satuan == 9) cout << " sembilan";

        cout << endl;
    } 
    return 0;
}
```
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/savilanf/103112400031_Savila-Nur-Fadilla/blob/main/Pertemuan1_Modul1/output1-unguided2.png)

##### Output 2
![Screenshot Output Unguided 2_1](https://github.com/savilanf/103112400031_Savila-Nur-Fadilla/blob/main/Pertemuan1_Modul1/output2-unguided2.png)

Kode dengan bahasa pemrograman C++ yang bertujuan untuk menerima masukan angka dan mengeluarkan output nilai angka tersebut dalam bentuk tulisan, angka yang akan diinput adalah bilangan bulat positif mulai dari 0 sampai 100. Bagian include iostream itu untuk memasukkan file header iostream. Kemudian program menjalanlan func main, di func main ada deklarasi variabel bertipe integer. Kita diminta input angka (0-100). Kemudian ada if-else, kalau angka valid program mengeluarkan output nilai angka yang kita input tersebut dalam bentuk tulisan, lalu return 0 berarti program selesai. Kalau angka tidak valid akan ada pesan error dan program berhenti.

### 3. Buatlah program yang dapat memberikan input dan output sbb.
    input: 3
    output:
        3 2 1 * 1 2 3
          2 1 * 1 2
            1 * 1
              *

```C++
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "input: ";
    cin >> n;
    cout << "output: " << endl;

    for(int i = n; i >= 1; i--){ 
        for(int spasi = n; spasi > i; spasi--){
            cout << "  ";
        }
        for(int j = i; j >= 1; j--){
            cout << j << " ";
        }
        cout << "* ";
        for(int k = 1; k <= i; k++){
            cout << k << " ";
        }
        cout << endl;
    }

    for(int spasi = 0; spasi < n; spasi++){
        cout << "  ";
    }
    cout << "*" << endl;
    return 0;
}
```
### Output Unguided 3 :
  
##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/savilanf/103112400031_Savila-Nur-Fadilla/blob/main/Pertemuan1_Modul1/output1-unguided3.png)

##### Output 2
![Screenshot Output Unguided 2_1](https://github.com/savilanf/103112400031_Savila-Nur-Fadilla/blob/main/Pertemuan1_Modul1/output2-unguided3.png)

Kode dengan bahasa pemrograman C++ yang bertujuan untuk memberikan input dan output seperti di soal (seperti segitiga terbalik). Bagian include iostream itu untuk memasukkan file header iostream. Kemudian program menjalanlan func main, di func main ada deklarasi variabel bertipe integer. Kita diminta input n yang merupakan angka. Kemudian ada perulangan for untuk mencetak angka, spasi, dan bintang. Perulangan for nya ada yang increment dan decrement, lalu return 0 berarti program selesai. 

## Kesimpulan
Laporan Praktikum Struktur Data Modul 1 ini menggunakan kode bahasa pemrograman C++. Di dalam contoh soal (guided) maupun latihan soal (unguided) ada yang menggunakan operasi aritmatika, percabangan (if-else, switch-case), perulangan (for loop, while loop, do while loop), dan struct. Untuk kode dan program yang digunakan masih dasar dan masih mudah untuk dipahami.

## Referensi

[1] Stroustrup, B. (1996). *A History of C++: 1979–1991*. Dalam T. J. Bergin & R. G. Gibson (Eds.), *History of Programming Languages II* (hlm. 699–769). New York: ACM Press. https://doi.org/10.1145/234286.1057836  
<br> 

[2] Sianipar, R. H. (2012). *Pemrograman C++: Dasar Pemrograman Berorientasi Objek*. Yogyakarta: Penerbit ANDI. ISBN 979-293-1848 / 978-979-293-1846.  
<br>  

[3] Syafii. (2018). *Pemrograman Komputer*. Padang: Universitas Andalas. http://repo.unand.ac.id/32011/1/Buku_Pemograman_Komputer_Syafii.pdf  
<br>  

[4] Shouthiri, P., & Thushika, N. (2019). *A Comparative Analysis of Looping Structures: Comparison of ‘While’ Loop and ‘Do-While’ Loop in the C++ Language*. Asian Journal of Research in Computer Science, 2(3), 1-5. https://doi.org/10.9734/ajrcos/2018/v2i328752  
<br>  

[5] Jain, R., & Gupta, S. (2014). *Optimizing the For loop: Comparison of For loop and micro For loop*. arXiv. https://arxiv.org/abs/1410.3772  
<br>  

[6] Nugroho, A. Y., & Sutanto, N. H. (2024). *Exploring the Code Foundation: A Literature Review of Data Structures in C++*. International Journal of Mechanical, Industrial and Control Systems Engineering, 1(3), 24-37. https://doi.org/10.61132/ijmicse.v1i3.47  
<br>

