/*
* file: main.cpp
* author: Josue Duran
* assignment: Linked List Project ///remove
*
* date created: 4/8/2021
*
* This file holds the driver to test the MyList class implementation
*/

#include <iostream>
#include "MyList.h"

using namespace std;

int main() {
    //MyList<int> a list
    MyList<int> a;
    //stores removed value in popFront() and popBack()
    int removedVal;

    cout << "Testing testPrint()..." << endl;
    a.testPrint(cout);
    cout << "Should be...\nEmpty List\n" << endl;

    cout << "Testing pushBack()..." << endl;
    //adds numbers 3-5 to the back of the list
    for(int i = 3; i < 6; i++){
        a.pushBack(i);
    }
    a.testPrint(cout);
    cout << "Should be...\n3\t4\t5\n" << endl;

    cout << "Testing pushFront()..." << endl;
    //adds numbers 0-2 to the front of the list
    for(int i = 2; i >= 0; i--){
        a.pushFront(i);
    }
    a.testPrint(cout);
    cout << "Should be...\n0\t1\t2\t3\t4\t5\n" << endl;

    cout << "Testing front()..." << endl;
    cout << "Front Value: " << a.front() << endl;
    cout << "Should be...\nFront Value: 0\n" << endl;

    cout << "Testing back()..." << endl;
    cout << "Back Value: " << a.back() << endl;
    cout << "Should be...\nBack Value: 5\n" << endl;

    cout << "Testing getSize()..." << endl;
    cout << a.getSize() << endl;
    cout << "Should be...\n6\n" << endl;

    cout << "Testing operator=..." << endl;
    //create new list b and assign it to a
    MyList<int>b = a;
    b.testPrint(cout);
    cout << "Should be...\n";
    a.testPrint(cout);
    cout << endl;

    cout << "Testing popFront()..." << endl;
    //remove the first value in the list
    b.popFront(removedVal);
    cout << "Removed Value: " << removedVal << endl;
    b.testPrint(cout);
    cout << "Should be...\nRemoved Value: 0\n1\t2\t3\t4\t5\n" << endl;

    cout << "Testing popBack()..." << endl;
    //remove the last value in the list
    b.popBack(removedVal);
    cout << "Removed Value: " << removedVal << endl;
    b.testPrint(cout);
    cout << "Should be...\nRemoved Value: 5\n1\t2\t3\t4\n" << endl;

    cout << "Testing erase()..." << endl;
    //erase both lists
    a.erase();
    b.erase();
    cout << "List A: ";
    a.testPrint(cout);
    cout << "List B: ";
    b.testPrint(cout);
    cout << "Should be...\nList A: Empty List\nList B: Empty List\n" << endl;

    cout << "Testing operator[]..." << endl;
    //try to access list b, which has been erased, so exception is caught
    try{
        b[3] = 2;
        cout << "Should not see this message" << endl;
    } catch(BADINDEX){
        cout << "Should see this message\n" << endl;
    }

    return 0;
}
