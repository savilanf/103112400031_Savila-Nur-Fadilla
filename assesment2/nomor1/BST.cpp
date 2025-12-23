#include "BST.h"

void createTree(Node* &root) {
    root = NULL;
}

bool isEmpty(Node* root) {
    return root == NULL;
}

Node* newNode(float berat, string nama, string tier) {
    Node* n = new Node();
    n->beratBadan = berat;
    n->namaMember = nama;
    n->tierMember = tier;
    n->left = n->right = NULL;
    return n;
}

void insertNode(Node* &root, float berat, string nama, string tier) {
    if (root == NULL) {
        root = newNode(berat, nama, tier);
    } else if (berat < root->beratBadan) {
        insertNode(root->left, berat, nama, tier);
    } else if (berat > root->beratBadan) {
        insertNode(root->right, berat, nama, tier);
    }
}

void inOrder(Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        cout << root->beratBadan << " - ";
        inOrder(root->right);
    }
}

void mostLeft(Node* root) {
    if (isEmpty(root)) return;
    Node* curr = root;
    while (curr->left != NULL) curr = curr->left;
    cout << "node mostleft : " << curr->beratBadan << endl;
}

void mostRight(Node* root) {
    if (isEmpty(root)) return;
    Node* curr = root;
    while (curr->right != NULL) curr = curr->right;
    cout << "node mostright : " << curr->beratBadan << endl;
}

void searchByBeratBadan(Node* curr, float key, Node* parent) {
    if (curr == NULL) {
        cout << "data tidak ditemukan!" << endl;
        return;
    }

    if (key == curr->beratBadan) {
        cout << "data ditemukan didalam BST!" << endl;
        cout << "--- data node yang dicari ---" << endl;
        cout << "nama member : " << curr->namaMember << "\nBerat Badan : " << curr->beratBadan << "\nTier Member : " << curr->tierMember << endl;
        
        cout << "-----------------------------" << endl;
        cout << "--- data parent ---" << endl;
        if (parent) {
            cout << "nama member : " << parent->namaMember << "\nBerat Badan : " << parent->beratBadan << "\nTier Member : " << parent->tierMember << endl;
        } else cout << "tidak memiliki parent" << endl;

        cout << "-----------------------------" << endl;
        if (parent) {
            Node* sibling = (parent->left == curr) ? parent->right : parent->left;
            if (sibling) cout << "sibling: " << sibling->namaMember << endl;
            else cout << "tidak memiliki sibling" << endl;
        } else cout << "tidak memiliki sibling" << endl;

        cout << "-----------------------------" << endl;
        cout << "--- data child kiri ---" << endl;
        if (curr->left) cout << "nama member : " << curr->left->namaMember << "\nBerat Badan : " << curr->left->beratBadan << "\nTier Member : " << curr->left->tierMember << endl;
        else cout << "tidak ada" << endl;

        cout << "-----------------------------" << endl;
        cout << "--- data child kanan ---" << endl;
        if (curr->right) cout << "nama member : " << curr->right->namaMember << "\nBerat Badan : " << curr->right->beratBadan << "\nTier Member : " << curr->right->tierMember << endl;
        else cout << "tidak ada" << endl;
    } 
    else if (key < curr->beratBadan) searchByBeratBadan(curr->left, key, curr);
    else searchByBeratBadan(curr->right, key, curr);
}