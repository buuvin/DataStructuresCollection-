#ifndef LBQUEUE_H
#define LBQUEUE_H

#include "SingleLinkedList.h"

template <class T>
class LBQueue{

private:
    int size;
    SingleLinkedList<T>* listQueue;
public:
    LBQueue();
    ~LBQueue();

    //core functions
    void insert(T data);
    //void enqueue(T data); // for priority queue
    T remove();

    //aux functions
    T peek();
    bool isEmpty();
    int getSize(); // never going to be negative

};

template <class T>
LBQueue::LBQueue(){
    size = 0;
    listQueue = new SingleLinkedList<T>();
}

template <class T>
LBQueue::~LBQueue(){
    delete listQueue;
}

template <class T>
void LBQueue::insert(T data){
    listQueue->insertBack();
    size++;
}

template <class T>
T LBQueue::remove(){
    if(isEmpty())
        throw runtime_error("Queue is empty");
    size--;
    return listQueue->removeFront();
}

template <class T>
T LBQueue::peek(){
    return listQueue->at(0);
}

template <class T>
bool LBQueue::isEmpty(){
    return size == 0;
}

template <class T>
int LBQueue::getSize(){
    return size;
}
#endif