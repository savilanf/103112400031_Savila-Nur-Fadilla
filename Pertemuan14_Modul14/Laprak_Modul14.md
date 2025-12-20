# <h1 align="center">Laporan Praktikum Modul 14 - Graph</h1>
<p align="center">Savila Nur Fadilla - 103112400031</p>

## Dasar Teori
### A. Graph<br/>
Graph didefinisikan sebagai representasi grafis dari sekumpulan vertices (simpul) yang saling terhubung oleh edges (sisi). Struktur ini sangat relevan dalam ilmu komputer dan matematika untuk membuat model struktural yang menggambarkan hubungan antar objek atau entitas dalam suatu sistem. [1].

### B. Jenis Graph<br/>
Graf tidak berarah (undirected graph) adalah graf di mana sisi tidak memiliki arah, sehingga hubungan antar simpul bersifat dua arah. Sebaliknya, graf berarah (directed graph) adalah graf yang setiap sisinya memiliki arah tertentu dari satu simpul ke simpul lainnya. Perbedaan utama keduanya terletak pada ada atau tidaknya orientasi arah pada sisi, yang memengaruhi cara representasi dan pemrosesan graf dalam pemrograman dan algoritma [2].

### B. ADT Graph<br/>
Struktur graph terdiri dari [3]:
- Node → menyimpan info, status visited, predecessor, dan list edge
- Edge → menunjuk node tujuan
- Graph → menunjuk node pertama

Disediakan operasi seperti:
- CreateGraph
- InsertNode
- DeleteNode
- ConnectNode / DisconnectNode
- PrintGraph
- PrintTopologicalSort

### D. Metode Penelusuran Graph<br/>
Metode penelusuran graph [3]:
1. Breadth First Search (BFS)
- Menelusuri graph per level (melebar).
- Menggunakan Queue.
- Cocok untuk mencari jarak terpendek.
2. Depth First Search (DFS)
- Menelusuri graph sedalam mungkin lalu mundur.
- Menggunakan Stack / Rekursi.
- Cocok untuk eksplorasi struktur graph.

## Guided 

### file: graph.h
```C++
#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
using namespace std;

typedef char infoGraph;
typedef struct ElmNode* adrNode;
typedef struct ElmEdge* adrEdge;

struct ElmEdge {
    adrNode node;
    adrEdge next;
};

struct ElmNode {
    infoGraph info;
    bool visited;
    adrEdge firstEdge;
    adrNode nextNode;
};

struct elmGraph {
    adrNode first;
};

typedef struct elmGraph *Graph;

//Prototype
void createGraph(Graph &G);
adrNode allocateNode(infoGraph x);
void insertNode(Graph &G, infoGraph x);
void connectNode(Graph &G, infoGraph start, infoGraph end);
void printGraph(Graph G);

#endif
```

### file: graph_init.cpp
```C++
#include "graph.h"

void createGraph(Graph &G) {
    G->first = NULL;
}

adrNode allocateNode(infoGraph x) {
    adrNode P = new ElmNode;
    P->info = x;
    P->visited = false;
    P->firstEdge = NULL;
    P->nextNode = NULL;
    return P;
}

void insertNode(Graph &G, infoGraph x) {
    adrNode P = allocateNode(x);
    if (G->first == NULL) {
        G->first = P;
    } else {
        adrNode Q = G->first;
        while (Q->nextNode != NULL) {
            Q = Q->nextNode;
        }
        Q->nextNode = P;
    }
}
```

### file: graph_edge.cpp
```C++
#include "graph.h"

adrNode findNode(Graph G, infoGraph x) {
    adrNode p = G->first;
    while (p != NULL) {
        if (p->info == x) return p;
        p = p->nextNode;
    }
    return NULL;
}

void connectNode(Graph &G, infoGraph start, infoGraph end) {
    adrNode pStart = findNode(G, start);
    adrNode pEnd = findNode(G, end);

    if (pStart != NULL && pEnd != NULL) {
        adrEdge newEdge = new ElmEdge;
        newEdge->node = pEnd;
        newEdge->next = pStart->firstEdge;
        //Insert First di list Edge
        pStart->firstEdge = newEdge;
    }
}
```

### file: graph_print.cpp
```C++
#include "graph.h"

void printGraph(Graph G) {
    adrNode p = G->first;
    while (p != NULL) {
        cout << "Node " << p->info << " terhubung ke: ";
        adrEdge e = p->firstEdge;
        while (e != NULL) {
            cout << e->node->info << " ";
            e = e->next;
        }
        cout << endl;
        p = p->nextNode;
    }
}
```

### file: main.cpp
```C++
#include "graph.h"
#include <iostream>

using namespace std;

int main() {
    // 1. Create Graph
    Graph G = new elmGraph;
    createGraph(G);

    // 2. Insert Nodes
    insertNode(G, 'A');
    insertNode(G, 'B');
    insertNode(G, 'C');
    insertNode(G, 'D');

    // 3. Connect Nodes (Edges)
    connectNode(G, 'A', 'B');
    connectNode(G, 'A', 'C');
    connectNode(G, 'B', 'D');
    connectNode(G, 'C', 'D');

    // 4. Print Graph Structure
    cout << "Isi Graph:" << endl;
    printGraph(G);

    return 0;
}
```

Kode ini merupakan pemrograman bahasa C++ yang menggunakan struktur ADT Graph berarah menggunakan adjacency. Graph direpresentasikan oleh kumpulan node (ElmNode) yang masing-masing menyimpan informasi (char), status visited, pointer ke daftar edge, dan pointer ke node berikutnya; sedangkan edge (ElmEdge) menyimpan tujuan node. Fungsi createGraph menginisialisasi graph kosong, allocateNode dan insertNode membuat serta menambahkan node ke graph, connectNode menghubungkan dua node dengan menambahkan edge dari node awal ke node tujuan (berarah), dan printGraph menampilkan hubungan setiap node. Pada main, graph dibuat, node A–D dimasukkan, beberapa edge ditambahkan (A→B, A→C, B→D, C→D), lalu struktur graph dicetak ke layar.

## Unguided

### 1. Buatlah ADT Graph tidak berarah file “graph.h”:
Type infoGraph: char
Type adrNode : pointer to ElmNode
Type adrEdge : pointer to ElmNode
Type ElmNode <
info : infoGraph
visited : integer
firstEdge : adrEdge
Next : adrNode
>
Type ElmEdge <
Node : adrNode
Next : adrEdge
>
Type Graph <
first : adrNode
>
procedure CreateGraph (input/output G : Graph)
procedure InsertNode (input/output G : Graph,
input X : infotype)
procedure ConnectNode (input/output N1, N2 : adrNode)
procedure PrintInfoGraph (input G : Graph)

Buatlah implementasi ADT Graph pada file “graph.cpp” dan cobalah hasil implementasi ADT pada file “main.cpp”

### 2. Buatlah prosedur untuk menampilkanhasil penelusuran DFS.
prosedur PrintDFS (Graph G, adrNode N);

### 3. Buatlah prosedur untuk menampilkanhasil penelusuran DFS.
prosedur PrintBFS (Graph G, adrNode N);

### JAWABAN
### file: graph.h
```C++
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
using namespace std;

typedef char infoGraph;
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;

struct ElmEdge {
    adrNode node;
    adrEdge next;
};

struct ElmNode {
    infoGraph info;
    int visited;
    adrEdge firstEdge;
    adrNode next;
};

struct Graph {
    adrNode first;
};

void CreateGraph(Graph &G);
adrNode CreateNode(infoGraph x);
void InsertNode(Graph &G, infoGraph x);
adrNode FindNode(Graph G, infoGraph x);
void ConnectNode(adrNode N1, adrNode N2);
void PrintInfoGraph(Graph G);

void PrintDFS(Graph G, adrNode N);
void PrintBFS(Graph G, adrNode N);

#endif
```

### file: graph.cpp
```C++
#include "graph.h"

void CreateGraph(Graph &G) {
    G.first = NULL;
}

adrNode CreateNode(infoGraph x) {
    adrNode P = new ElmNode;
    P->info = x;
    P->visited = 0;
    P->firstEdge = NULL;
    P->next = NULL;
    return P;
}

void InsertNode(Graph &G, infoGraph x) {
    adrNode P = CreateNode(x);
    if (G.first == NULL) {
        G.first = P;
    } else {
        adrNode Q = G.first;
        while (Q->next != NULL) {
            Q = Q->next;
        }
        Q->next = P;
    }
}

adrNode FindNode(Graph G, infoGraph x) {
    adrNode P = G.first;
    while (P != NULL && P->info != x) {
        P = P->next;
    }
    return P;
}

void ConnectNode(adrNode N1, adrNode N2) {
    adrEdge E = new ElmEdge;
    E->node = N2;
    E->next = N1->firstEdge;
    N1->firstEdge = E;
}

void PrintInfoGraph(Graph G) {
    adrNode P = G.first;
    while (P != NULL) {
        cout << P->info << " : ";
        adrEdge E = P->firstEdge;
        while (E != NULL) {
            cout << E->node->info << " ";
            E = E->next;
        }
        cout << endl;
        P = P->next;
    }
}

/* DFS */
void PrintDFS(Graph G, adrNode N) {
    if (N == NULL || N->visited == 1) return;

    cout << N->info << " ";
    N->visited = 1;

    adrEdge E = N->firstEdge;
    while (E != NULL) {
        PrintDFS(G, E->node);
        E = E->next;
    }
}

/* BFS */
void PrintBFS(Graph G, adrNode N) {
    adrNode queue[20];
    int front = 0, rear = 0;

    N->visited = 1;
    queue[rear++] = N;

    while (front < rear) {
        adrNode P = queue[front++];
        cout << P->info << " ";

        adrEdge E = P->firstEdge;
        while (E != NULL) {
            if (E->node->visited == 0) {
                E->node->visited = 1;
                queue[rear++] = E->node;
            }
            E = E->next;
        }
    }
}
```

### file: main.cpp
```C++
#include "graph.h"

int main() {
    Graph G;
    CreateGraph(G);

    InsertNode(G, 'A');
    InsertNode(G, 'B');
    InsertNode(G, 'C');
    InsertNode(G, 'D');
    InsertNode(G, 'E');
    InsertNode(G, 'F');
    InsertNode(G, 'G');
    InsertNode(G, 'H');

    adrNode A = FindNode(G, 'A');
    adrNode B = FindNode(G, 'B');
    adrNode C = FindNode(G, 'C');
    adrNode D = FindNode(G, 'D');
    adrNode E = FindNode(G, 'E');
    adrNode F = FindNode(G, 'F');
    adrNode Gg = FindNode(G, 'G');
    adrNode H = FindNode(G, 'H');

    ConnectNode(A, B);
    ConnectNode(A, C);

    ConnectNode(B, D);
    ConnectNode(B, E);

    ConnectNode(C, F);
    ConnectNode(C, Gg);

    ConnectNode(D, H);
    ConnectNode(E, H);
    ConnectNode(F, H);
    ConnectNode(Gg, H);

    cout << "Adjacency List Graph" << endl;
    PrintInfoGraph(G);

    cout << "\nDFS (mulai dari A): ";
    PrintDFS(G, A);

    adrNode P = G.first;
    while (P != NULL) {
        P->visited = 0;
        P = P->next;
    }

    cout << "\nBFS (mulai dari A): ";
    PrintBFS(G, A);

    return 0;
}
```

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/savilanf/103112400031_Savila-Nur-Fadilla/blob/main/Pertemuan14_Modul14/output/output1.png)

Kode dengan bahasa pemrograman C++ yang menggunakan ADT graph. ADT Graph diimplementasikan menggunakan adjacency list, di mana:
- Graph menyimpan alamat node pertama
- ElmNode menyimpan info simpul, penanda visited, dan pointer ke edge
- ElmEdge menyimpan hubungan antar node

Graph diimplementasikan pada file graph.cpp dan digunakan pada main.cpp untuk membentuk graph sesuai ilustrasi A–H.

##### Output 2
![Screenshot Output Unguided 2_1](https://github.com/savilanf/103112400031_Savila-Nur-Fadilla/blob/main/Pertemuan14_Modul14/output/output2.png)

Kode dengan bahasa pemrograman C++ untuk menelusuri secara DFS.
DFS (Depth First Search) menelusuri graph dengan cara:
- Mengunjungi satu node
- Menelusuri node tetangga secara mendalam (rekursif)
- Menandai node agar tidak dikunjungi ulang

##### Output 3
![Screenshot Output Unguided 3_1](https://github.com/savilanf/103112400031_Savila-Nur-Fadilla/blob/main/Pertemuan14_Modul14/output/output3.png)

Kode dengan bahasa pemrograman C++ untuk menelusuri secara BFS.
BFS (Breadth First Search) menelusuri graph dengan cara:
- Mengunjungi node per level
- Menggunakan queue
- Cocok untuk mencari jalur terpendek

## Kesimpulan
Laporan Praktikum Struktur Data Modul 14 tentang Graph ini adalah bahwa penggunaan bahasa pemrograman C++ dengan pendekatan ADT (Abstract Data Type) mampu membantu mahasiswa dalam memahami dan mengimplementasikan struktur data graph secara terstruktur dan modular. Graph direpresentasikan menggunakan adjacency list yang terdiri dari node dan edge untuk menggambarkan hubungan antar data, baik berarah maupun tidak berarah. Pada praktikum ini, mahasiswa mempelajari operasi dasar graph seperti pembuatan graph, penambahan node, penghubungan antar node melalui edge, serta penampilan struktur graph. Melalui penerapan ADT, pengelolaan graph menjadi lebih terorganisir, mudah dipahami, dan dapat dikembangkan lebih lanjut untuk penelusuran graph seperti DFS dan BFS sesuai kebutuhan.

## Referensi 
[1] Jand, H., & Kaur, J. (2017). Graph Theory. International Journal of Computer (IJC).

[2] Kudase, J., & Bane, P. (2016). A Brief Study of Graph Data Structure. International Journal of Advanced Research in Computer and Communication Engineering, 5(6).

[3] Informatics Laboratory. (n.d.). *Modul 14 – Graph*. Program Studi Teknik Informatika, Telkom University.