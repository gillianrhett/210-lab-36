// COMSC-210 | Lab 36 | Gillian Rhett
#include <iostream>
#include <fstream>
#include <string>
#include "StrBinaryTree.h"
using namespace std;
/*Milestones to document with your commits, in addition to 10-minute commits (commit must read 'Milestone n' where n is the milestone number):

DONE 1. Project is set up and running using the provided files.
2. Code modification from int to strings is complete, and your code exercises this for testing.
3. Your code successfully creates a BST from the records and outputs it using the method of your choosing. 
4. Your code's menu is functional.
*/

const string FILENAME = "codes.txt";

int getInt(int);

int main() {
    // create the initial tree from the text file
    ifstream inFile; // file object to get the items from
    // try to open the file
    try {
        inFile.open(FILENAME, ios::in);
        if(inFile.fail()) 
            throw invalid_argument("file not found");
    }
    catch(invalid_argument& e) {
        cout << "Error: " << e.what();
        return -1;
    }
    
    StrBinaryTree tree;
    // add the records from the file
    string tempInput;
    while(!inFile.eof()) {
        inFile >> tempInput;
        tree.insertNode(tempInput);
    }
    inFile.close();

    // Display the menu
    int choice = 1;
    while (choice != 0) {
        cout << "== Binary Tree ==" << endl;
        cout << "1. Add a record" << endl;
        cout << "2. Delete a record" << endl;
        cout << "3. Search for a record" << endl;
        cout << "4. Modify a record" << endl;
        cout << "5. Display all records" << endl;
        cout << "0. Quit" << endl;
        cout << "Enter your choice: ";
        choice = getInt(5);
        if (choice == 1) {
        // add a new record

        }
        if (choice == 2) {
        // delete an existing record
            cout << "Enter the code you want to delete: ";
            cin >> tempInput;
            cout << "RESULT: ";
            if(tree.searchNode(tempInput)) {
                tree.remove(tempInput);
                cout << tempInput << " was deleted." << endl;
            }
            else
                cout << tempInput << " was not found." << endl;
        }
        if (choice == 3) {
        // search for a record and display whether it was found
            cout << "Enter the code you want to search for: ";
            cin >> tempInput;
            cout << "RESULT: ";
            if(tree.searchNode(tempInput))
                cout << tempInput << " is in the tree." << endl;
            else
                cout << tempInput << " was not found." << endl;
        }
        if (choice == 4) {
        // search for a record and change its string value

        }
        if (choice == 5) {
        // display all the records
            tree.displayInOrder();
        }
        if (choice == 0) {
        // quit
            cout << "Goodbye" << endl;
        }
    }
  
    return 0;
}

int getInt(int max) {
// for validating input - by me
    int num_in = -1;
    string temp_input;
    while(num_in < 0 || num_in > max) {
        cout << "enter a number (0 to " << max << "): ";
        cin >> temp_input;
        try {
            num_in = stoi(temp_input);
        }
        catch(const exception& e) {
            cout << "invalid input ";
            num_in = -1;
        }        
    }
    return num_in;
}