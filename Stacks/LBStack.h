#ifndef LBSTACK_H
#define LBSTACK_H

#include <exception>
#include<iostream>
#include "SingleLinkedList.h"
using namespace std;

template<class T> 
class LBStack{

private:
    SinglyLinkedList<T>* listStack;
    int size; 
public:
    LBStack();//default constructor
    ~LBStack();//default destructor

    //core functions
    void push(T data);
    T pop();
    T peek(); // top()

    //aux functions
    int getSize();
    bool isEmpty();
};

template <class T>
LBStack<T>::LBStack(){
    listStack = new SinglyLinkedList<T>();
    size = 0;
}

template <class T>
LBStack<T>::~LBStack(){
    delete listStack;
    size = 0;
}

template <class T>
void LBStack<T>::push(T data){
    size++;
    listStack->insertFront(data);
}

template <class T>
T LBStack<T>::pop(){
    if(isEmpty()){
        throw runtime_error("Stack is empty");
    }
    size--;
    return listStack->removeFront();
}

template <class T>
T LBStack<T>::peek(){
    if(isEmpty()){
        throw runtime_error("Stack is empty");
    }
    return listStack->at(0);
}

template <class T>
int LBStack<T>::getSize(){
    return size;
}

template <class T>
bool LBStack<T>::isEmpty(){
    return size == 0;
}
#endif