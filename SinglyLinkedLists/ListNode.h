#ifndef LISTNODE_H
#define LISTNODE_H

#include <iostream>
#include <exception>

using namespace std;

template<class T>
class ListNode {
 
public:
    ListNode();
    ListNode(T d);
    virtual ~ListNode();
    ListNode<T> *next;
    T data;
};
template <class T>
ListNode<T>::ListNode(){}

template <class T>
ListNode<T>::ListNode(T d){
    data = d;
    next = NULL;
}

template <class T>
ListNode<T>::~ListNode(){ next = NULL;}
#endif