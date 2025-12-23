#include "BST.h"

int main() {
    Node* root;
    createTree(root);

    // Sesuai urutan gambar soal agar tree terbentuk sempurna
    insertNode(root, 60, "Rizkina Azizah", "basic");
    insertNode(root, 50, "Hakan Ismail", "bronze");
    insertNode(root, 65, "Olivia Saevali", "silver");
    insertNode(root, 47, "Felix Pedrosa", "gold");
    insertNode(root, 56, "Gamel Al Ghifari", "platinum");
    insertNode(root, 70, "Hanif Al Faiz", "basic");
    insertNode(root, 52, "Mutiara Fauziah", "bronze");
    insertNode(root, 68, "Davi Ilyas", "silver");
    insertNode(root, 81, "Abdad Mubarok", "gold");

    cout << "== traversal inOrder ==" << endl;
    inOrder(root); 
    cout << "\n\n";

    mostLeft(root);
    mostRight(root);
    cout << "\n";

    searchByBeratBadan(root, 70);
    return 0;
}