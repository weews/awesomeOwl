#include "bTree.h"

bTree::bTree() // Constructor
{
    root = NULL;
}

bTree::~bTree() // Destructor
{
    destroyTree(root);
    cout << "Tree destroyed\n";
}

node *bTree::getRoot() // Access the root node
{
    return root;
}

void bTree::destroyTree(node *n) // Recursive method called by destructor
{
    if (n != NULL)
    {
        destroyTree(n->left); // Left sub-tree
        destroyTree(n->right); // Right sub-tree
        delete n;
    }
}

void bTree::insertNode(int d) // Iterative method to insert a node
{
    if (root == NULL) // Tree is empty
    {
        root = new node;
        root->data = d;
        root->left = root->right = NULL;
        return;
    }
    else // Tree is not empty
    {
        node *curr, *prev;
        curr = root;
        while (curr != NULL) // Traverse the tree for the location to insert
        {
            if (d < curr->data) // Go left branch
            {
                prev = curr;
                curr = curr->left;
            }
            else // Go right branch
            {
                prev = curr;
                curr = curr->right;
            }
        }
        node *temp = new node; // Create a new node
        temp->data = d;
        temp->left = temp->right = NULL;
        if (d < prev->data) // Insert at the right location
            prev->left = temp;
        else
            prev->right = temp;
    }
}

void bTree::printNodesInOrder(node *n) // Recursive method to print nodes in-order
{
    if (n == NULL)
        return;
    printNodesInOrder(n->left); 
    cout << n->data << " "; 
    printNodesInOrder(n->right); 
}

void bTree::printNodesPreOrder(node *n) // Recursive method to print nodes pre-order
{
    if (n == NULL)
        return;
    cout << n->data << " ";
    printNodesPreOrder(n->left);
    printNodesPreOrder(n->right);
}

void bTree::deleteNode(int d) // Iterative method to delete a node
{
    if (root == NULL) // Tree is empty
    {
        cout << "Cannot delete from an empty tree\n";
        return;
    }
    else // Tree is not empty
    {
        node *curr, *prev; // Two pointers to navigate
        curr = root;
        prev = curr;
        while (curr != NULL) // Traverse the tree for the location to delete
        {
            if (d < curr->data) // Go left branch
            {
                prev = curr;
                curr = curr->left;
            }
            else if (d > curr->data) // Go right branch
            {
                prev = curr;
                curr = curr->right;
            }
            else // Located
            {
                // Node to delete has no children
                if (curr->left == NULL && curr->right == NULL)
                {
                    if (curr == prev) // Special case: Root node (no traversal)
                    {
                        delete curr;
                        root = NULL; // Tree is now empty
                        return;
                    }
                    if (curr == prev->left) // Traversal was made
                        prev->left = NULL;
                    else
                        prev->right = NULL;
                    delete curr;
                    return;
                }
                // Node to delete has one left child
                else if (curr->left != NULL && curr->right == NULL)
                {
                    if (curr == prev) // Special case: Root node (no traversal)
                    {
                        root = curr->left; // Update the root
                        delete curr;
                        return;
                    }
                    if (curr == prev->left) // Traversal was made
                        prev->left = curr->left;
                    else
                        prev->right = curr->left;
                    delete curr;
                    return;
                }
                // Node to delete has one right child
                else if (curr->left == NULL && curr->right != NULL)
                {
                    if (curr == prev) // Special case: Root node (no traversal)
                    {
                        root = curr->right; // Update the root
                        delete curr;
                        return;
                    }
                    if (curr == prev->left) // Traversal was made
                        prev->left = curr->right;
                    else
                        prev->right = curr->right;
                    delete curr;
                    return;
                }
                // Node to delete has two children
                else
                {
                    // Find the minimum node in the right sub-tree
                    node *temp;
                    prev = curr; // Two pointers to navigate
                    temp = curr->right;
                    while (temp->left != NULL) // Traverse
                    {
                        prev = temp;
                        temp = temp->left;
                    }      
                    // Copy the value of the minimum node found
                    curr->data = temp->data;
                    // Set the predecessor or successor node properly
                    // and delete the minimum node
                    if (temp == prev->left)
                        prev->left = temp->right;
                    else
                        prev->right = temp->right;
                    delete temp;
                    return;
                }
            }
        }
    }
    cout << "Node not found\n" << endl;
}