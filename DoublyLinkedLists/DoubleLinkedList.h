#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

#include <iostream>
#include <exception>
#include "ListNode.h"

using namespace std;

template <class T>
class DoubleLinkedList{

private:
    ListNode<T> *front;
    ListNode<T> *back;
    unsigned int size;

public:
    DoubleLinkedList();
    virtual ~DoubleLinkedList();

    void insertFront(T d);
    void insertBack(T d);
    T removeFront();
    T removeBack();
    T removeNode(T value);
    T find(T value);
    bool isEmpty();
    unsigned int getSize();
    void printList(bool isPrintLink);
};

//------------------------------------------------------------------------------------------------------------------------
template <class T>
DoubleLinkedList<T>::DoubleLinkedList(){
    front = NULL;
    back = NULL;
    size = 0;
}

template <class T>
DoubleLinkedList<T>::~DoubleLinkedList(){

}

template <class T>
void DoubleLinkedList<T>::insertFront(T d){
    ListNode<T> *node = new ListNode<T>(d);

    if(isEmpty()){
        back = node;
    }
    else{
        node->next = front;
        front->prev = node;
    }
    front = node;
    size++;
}

template <class T>
void DoubleLinkedList<T>::insertBack(T d){
    ListNode<T> *node = new ListNode<T>(d);

    if(isEmpty()){
        front = node;
    }
    else{
        node->prev = back;
        back->next = node;
    }
    back = node;
    size++;
}

template <class T>
T DoubleLinkedList<T>::removeFront(){
    //if empty then throw exception
    ListNode<T> *temp = front;

    if(front->next == NULL){
        back = NULL;
    }
    else{
        front->next->prev = NULL;
    }
    front = front->next;
    temp->next = NULL;
    T data = temp->data;
    delete temp;
    size--;
    
    return data;
}

template <class T>
T DoubleLinkedList<T>::removeBack(){
    //if empty then throw exception
    ListNode<T> *temp = back;
    if(back->prev == NULL){
        front = NULL;
    }
    else{
        back->prev->next = NULL;
    }
    back = back->prev;
    temp->prev = NULL;
    T data = temp->data;
    size--;
    
    return data;
}

template<class T>
T DoubleLinkedList<T>::find(T value){
    int pos = -1;

    ListNode<T>* curNode = front;
    while(curNode != NULL){
        ++pos;
        if(curNode->data == value)
            break;
        curNode = curNode->next;
    }
    if(curNode == NULL)
        pos = -1;

    delete curNode;
    return pos;
}

template <class T>
T DoubleLinkedList<T>::removeNode(T value){
    //ifempty throw exception

    ListNode<T>* curNode = front;
    while(curNode->data != value){
        curNode = curNode->next;

        if(curNode == NULL){
            delete curNode;
            return -1;
        }

    }

    if(curNode == front){
        front = curNode->next;
        front->prev = NULL;
    } else if(curNode == back){
        back = curNode->prev;
        back->next = NULL;
    } else if(curNode != front && curNode != back){
        cout << curNode->data << endl;
        cout << curNode->prev->data << endl;
        cout << curNode->prev->next->data << endl;
        curNode->prev->next = curNode->next;
        cout << "test 1" << endl;
        curNode->next->prev = curNode->prev;
        //cout << "test 2" << endl;
    }

    curNode->next = NULL;
    curNode->prev = NULL;
    T d = curNode->data;
    delete curNode;

    return d;
}


template <class T>
bool DoubleLinkedList<T>::isEmpty(){ return size == 0; }

template <class T>
unsigned int DoubleLinkedList<T>::getSize(){ return size; }

template <class T>
void DoubleLinkedList<T>::printList(bool printLink)
{
    if(isEmpty())
        cout << "The list is empty" << endl;
    ListNode<T> *curr = front;
    while(curr != NULL){
       if(curr == front){
         cout << "{FRONT}: ";
       }
       else if(curr == back){
         cout << "{REAR}: ";
       }
        cout << "[ " << curr->data << " ] ";
       curr = curr->next;
       if(curr != 0){
         cout << " ==> ";
       }
    }
    cout << endl;

    cout << "FRONT: " << front->data << endl;
    cout << "BACK: " << back->data << endl;
}

#endif