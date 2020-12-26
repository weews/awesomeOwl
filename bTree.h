#pragma once
#include <iostream>

using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
};

class bTree
{
private:
    node *root;
public:
    bTree();
    ~bTree();
    node *getRoot();
    void destroyTree(node *);
    void insertNode(int);
    void printNodesInOrder(node *);
    void printNodesPreOrder(node *);
    void deleteNode(int); // Hibbard's algorithm of 1962
};