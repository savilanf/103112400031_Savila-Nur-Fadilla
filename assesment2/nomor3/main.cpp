#include "Graph.h"

int main() {
    Graph g;
    initGraph(g);

    addNode(g, 'A');
    addNode(g, 'B');
    addNode(g, 'C');
    addNode(g, 'D');
    addNode(g, 'E');

    addEdge(g, 'A', 'B');
    addEdge(g, 'B', 'C');
    addEdge(g, 'C', 'D');
    addEdge(g, 'B', 'E');

    printGraph(g);
    analyzeCriticalNodes(g);

    return 0;
}