/*
* file: MyList.h
* author: Josue Duran
*
* File contains the class definition and implementation
*   of the MyList class
*/

#ifndef MYLIST_H_INCLUDED
#define MYLIST_H_INCLUDED

#include <iostream>
#include <sstream>
#include "ContainerIfc.h"
#include "Node.h"

using namespace std;

template <class T>
class MyList : public ContainerIfc <T> {
public:
    MyList();
    ~MyList();
    MyList(const MyList&);
    MyList <T>& operator = (const MyList&);
    MyList <T>& pushFront(T);
    MyList <T>& pushBack(T);
    MyList <T>& popFront(T&);  //BADINDEX()
    MyList <T>& popBack(T&);  //BADINDEX()
    int getSize();
    bool isEmpty();
    T front();  //BADINDEX()
    T back();  //BADINDEX()
    T& operator [](int);  //BADINDEX()
    void erase();

    void testPrint(ostream &out); //just to test

protected:
    Node<T> *head;
};

/*
* description: class constructor
* pre-condition: none
* post-condition: head points to NULL
* return: nothing
*/
template<class T>
MyList<T>::MyList(){
    this->head = nullptr;
}

/*
* description: class destructor
* pre-condition:a MyList object exists
* post-condition:all memory allocated to the MyList is deleted
* return: nothing
*/
template<class T>
MyList<T>::~MyList(){
    Node<T> *temp = nullptr;
    while(head != nullptr){
        temp = head->next;
        delete head;
        head = temp;
    }
}

/*
* description: class copy constructor
* pre-condition: a MyList object exists
* post-condition: a copy of the class object n is made
* return: nothing
*/
template<class T>
MyList<T>::MyList(const MyList& n){
    head = nullptr;
    if(this != &n){
        Node<T> *dest = n.head;
        while(dest !=  nullptr){
            pushBack(dest->data);
            dest = dest->next;
        }
    }
}

/*
* description: overloaded assignment operator
* pre-condition: a object exists
* post-condition: the object n is unchanged and *this is an exact copy of n
* return: a reference to self
*/
template<class T>
MyList <T>& MyList<T>::operator=(const MyList& n){
    head = nullptr;
    if(this != n){
        Node<T> *dest = n.head;
        while(dest != nullptr){
            pushBack(dest->data);
            dest = dest->next;
        }
    }
    return *this;
}

/*
* description: store data element n in a new Node and adds the Node to
*              the front of a data structure (MyList)
* pre-condition: a MyList object exists
* post-condition: a new Node has been added to the front of the MyList
* return: a reference to self
*/
template<class T>
MyList<T>& MyList<T>::pushFront(T val){
    Node<T> *temp = new Node<T>(val);

    temp->next = head;
    head = temp;

    return *this;
}

/*
* description: store data element n in a new Node and adds the Node to
*              the rear (end) of a data structure (MyList)
* pre-condition: a MyList object exists
* post-condition: a new data element has been added to the rear (end) of the MyList
* return: a reference to self
*/
template<class T>
MyList<T>& MyList<T>::pushBack(T val){
    Node<T> *push = new Node<T>(val);
    if(isEmpty()){
        head = push;
    }else{
        Node<T> *temp = head;
        while(temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = push;
    }
    return *this;
}

/*
* description: removes a data element from the front of the data structure (MyList)
* pre-condition: a object exists
* post-condition: a Node has been removed from the front of the linked MyList pointed
*                 to by head, and set n equal to the data of the node removed
*                 if the MyList is empty, throw a BADINDEX exception
* return: a reference to self
*/
template<class T>
MyList<T>& MyList<T>::popFront(T &val){
    if(isEmpty()){
        throw BADINDEX();
    }
    Node<T> *temp = head;
    val = front();
    head = temp->next;
    temp->next = nullptr;
    delete temp;

    return *this;
}

/*
* description: removes a data element from the rear (end) of the data structure (MyList)
* pre-condition: a object exists
* post-condition: a Node has been removed from the rear of the linked MyList pointed to
*                 by head and set n to the data of the node removed. if the MyList is
*                 empty throw a BADINDEX exception
* return: a reference to self
*/
template<class T>
MyList<T>& MyList<T>::popBack(T &val){
    if(isEmpty()){
        throw BADINDEX();
    }
    Node<T> *cur = head;
    Node<T> *prev = head;
    val = back();
    while(cur->next != nullptr){
        prev = cur;
        cur = cur->next;
    }
    prev->next = nullptr;
    delete cur;

    return *this;
}

/*
* description: returns the number of Nodes currently in the linked MyList
* pre-condition: a object exists
* post-condition: the linked MyList is unchanged
* return: an integer value representing the number of elements in the MyList
*/
template<class T>
int MyList<T>::getSize(){
    int sizeCount = 0;
    if(head != nullptr){
        sizeCount++;
        Node<T> *temp = head;
        while(temp->next != nullptr){
            temp = temp->next;
            sizeCount++;
        }
    }
    return sizeCount;
}

/*
* description: flag to hold if head == nullptr
* pre-condition: an object exists
* post-condition: flag is true if head == nullptr
* return: true flag if head == nullptr
*/
template<class T>
bool MyList<T>::isEmpty(){
    return head == nullptr;
}

/*
* description: returns a copy of the first data item in the linked list
* pre-condition: a object exists
* post-condition: the object is unchanged. throw BADINDEX if the
*               linked MyList is empty
* return:returns a copy of the first data item in the linked list
*/
template<class T>
T MyList<T>::front(){
    if(isEmpty()){
        throw BADINDEX();
    }
    return head->data;
}

/*
* description: returns a copy of the last data item in the linked list
* pre-condition: a object exists
* post-condition: the object is unchanged. throw BADINDEX if the linked MyList is empty
* return: returns a copy of the last data item in the linked list
*/
template<class T>
T MyList<T>::back(){
    if(isEmpty()){
        throw BADINDEX();
    }
    Node<T> *temp = head;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    return temp->data;
}

/*
* description: returns a reference to data element n in the linked list
* pre-condition: a object exists
* post-condition: the object is unchanged. throw BADINDEX if n >= currentSize or n < 0
* return: returns a reference to data element n in the linked list
*/
template<class T>
T& MyList<T>::operator[](int n){
    if(isEmpty() || n >= getSize() || n < 0){
        throw BADINDEX();
    }
    Node<T> *temp = head;
    for(int i = 0; temp->next != nullptr && i < n; i++){
        temp = temp->next;
    }
    return temp->data;
}

/*
* description: removes all nodes from MyList
* pre-condition: a object exists
* post-condition: the object is an empty MyList
* return: nothing
*/
template<class T>
void MyList<T>::erase(){
    Node<T> *cur = head;
    Node<T> *nextN = head;
    while(cur != nullptr){
        nextN = cur->next;
        delete cur;
        cur = nextN;
    }
    head = nullptr;
}

template<class T>
void MyList<T>::testPrint(ostream &out){
    Node<T> *temp = head;
    if(temp == nullptr){
        out << "Empty List";
    }
    while(temp != nullptr){
        out << temp->data << "\t";
        temp = temp->next;
    }
    out << endl;
}

#endif // MYLIST_H_INCLUDED
