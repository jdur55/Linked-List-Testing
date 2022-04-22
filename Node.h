/*
* file: Node.h
* author: Josue Duran
*
* File contains the Node class definition
*/

#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

template <class T>
class Node {
public:
    T data;
    Node<T> *next;

    Node(T e) {
        data = e;
        next = NULL;
    }
};

#endif // NODE_H_INCLUDED
