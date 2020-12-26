#include "bTree.h"
#include <iostream>

using namespace std;

int main()
{
    bTree t;
    bool running = true;
    int option, i;
    
    while (running == true) // Run the program indefinitely
    {
        cout << "Select an option (1 to insert node, 2 to delete node, 3 to print nodes, 4 or otherwise to exit): ";
        cin >> option;
        switch (option)
        {
            case 1:
                cout << "Enter an integer: ";
                cin >> i;
                t.insertNode(i); // Call insert method
                break;
            case 2:
                cout << "Enter an integer: ";
                cin >> i;
                t.deleteNode(i); // Call delete method
                break;
            case 3:
                // Call print method
                // t.printNodesPreOrder(t.getRoot());
                t.printNodesInOrder(t.getRoot());
                cout << endl;
                break;
            default:
                running = false; // Set flag to exit
                break;
        }
    }
    
    return 0;
}
