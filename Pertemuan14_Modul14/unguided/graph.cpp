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
