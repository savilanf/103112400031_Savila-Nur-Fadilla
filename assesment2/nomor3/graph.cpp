#include "Graph.h"

void initGraph(Graph& g) {
    g.head = nullptr;
}

void addNode(Graph& g, char name) {
    Node* n = new Node;
    n->name = name;
    n->active = true;
    n->visited = false;
    n->edgeHead = nullptr;
    n->next = g.head;
    g.head = n;
}

Node* findNode(Graph& g, char name) {
    Node* temp = g.head;
    while (temp) {
        if (temp->name == name)
            return temp;
        temp = temp->next;
    }
    return nullptr;
}

void addEdge(Graph& g, char from, char to) {
    Node* a = findNode(g, from);
    Node* b = findNode(g, to);
    if (!a || !b) return;

    Edge* e1 = new Edge;
    e1->to = b;
    e1->next = a->edgeHead;
    a->edgeHead = e1;

    Edge* e2 = new Edge;
    e2->to = a;
    e2->next = b->edgeHead;
    b->edgeHead = e2;
}

void printGraph(Graph& g) {
    cout << "mmbangun jaringan distribusi vaksin\n";
    Node* n = g.head;
    while (n) {
        cout << "node " << n->name << " terhubung ke: ";
        Edge* e = n->edgeHead;
        while (e) {
            cout << e->to->name << " ";
            e = e->next;
        }
        cout << endl;
        n = n->next;
    }
    cout << endl;
}

void resetVisited(Graph& g) {
    Node* n = g.head;
    while (n) {
        n->visited = false;
        n = n->next;
    }
}

void dfs(Node* start) {
    if (!start || !start->active || start->visited) return;

    start->visited = true;
    Edge* e = start->edgeHead;
    while (e) {
        if (e->to->active && !e->to->visited)
            dfs(e->to);
        e = e->next;
    }
}

bool isConnectedIgnoring(Graph& g, Node* ignored) {
    resetVisited(g);

    Node* start = g.head;
    while (start && (!start->active || start == ignored))
        start = start->next;

    if (!start) return true;

    dfs(start);

    Node* n = g.head;
    while (n) {
        if (n != ignored && n->active && !n->visited)
            return false;
        n = n->next;
    }
    return true;
}

void analyzeCriticalNodes(Graph& g) {
    cout << "analisis kota kritis (single point of failure)\n";

    Node* n = g.head;
    while (n) {
        n->active = false;

        if (!isConnectedIgnoring(g, n)) {
            cout << "[PERINGATAN] kota " << n->name << " adalah kota kritis!\n";
            cout << "-> Jika " << n->name << " lockdown, distribusi terputus.\n";
        } else {
            cout << "Kota " << n->name << " aman (redundansi oke).\n";
        }

        n->active = true;
        n = n->next;
    }
}