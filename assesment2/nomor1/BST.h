#ifndef BST_H
#define BST_H

#include <iostream>
#include <string>
using namespace std;

struct Node {
    string namaMember;
    float beratBadan;
    string tierMember;
    Node *left, *right;
};

void createTree(Node* &root);
bool isEmpty(Node* root);
Node* newNode(float berat, string nama, string tier);
void insertNode(Node* &root, float berat, string nama, string tier);
void inOrder(Node* root);
void mostLeft(Node* root);
void mostRight(Node* root);
void searchByBeratBadan(Node* root, float key, Node* parent = NULL);

#endif