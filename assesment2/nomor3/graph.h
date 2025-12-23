#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
using namespace std;

struct Node;
struct Edge;

struct Edge {
    Node* to;
    Edge* next;
};

struct Node {
    char name;
    bool active;
    bool visited;
    Edge* edgeHead;
    Node* next;
};

struct Graph {
    Node* head;
};

void initGraph(Graph& g);
void addNode(Graph& g, char name);
Node* findNode(Graph& g, char name);
void addEdge(Graph& g, char from, char to);
void printGraph(Graph& g);

void resetVisited(Graph& g);
void dfs(Node* start);
bool isConnectedIgnoring(Graph& g, Node* ignored);
void analyzeCriticalNodes(Graph& g);

#endif