#ifndef ABQUEUE_H
#define ABQUEUE_H


#include<iostream>
#include<exception>

template <class T>
class ABQueue{

public:
    ABQueue();
    ABQueue(int maxSize);
    ~ABQueue();

    //core functions
    void insert(T data);
    void enqueue(T data); // for priority queue
    T remove();

    //aux functions
    T peek();
    bool isFull();
    bool isEmpty();
    unsigned int getSize(); // never going to be negative
    void printArray(); // helper function to visualize queue

    
private:
    int mSize;
    int front;
    int rear;
    unsigned int numElements;// number of elements cant be negative
    T *myQueue;
};

template <class T>
ABQueue<T>::ABQueue(){
    mSize = 128;
    front = 0;
    rear = 0;
    numElements = 0;
    myQueue = new char[mSize];
}

template <class T>
ABQueue<T>::ABQueue(int maxSize){
    mSize = maxSize;
    front = 0;
    rear = 0;
    numElements = 0;
    myQueue = new char[mSize];
}

template <class T>
ABQueue<T>::~ABQueue(){
    delete myQueue;
}

template <class T>
void ABQueue<T>::insert(T data){
    if(isFull()){
        throw runtime_error("queue is full");
    }
    myQueue[rear++] = data;
    rear %= mSize; // makes queue circular
    numElements++;
}

template <class T>
void ABQueue<T>::enqueue(T data){
    if(isFull()){
        throw runtime_error("priority queue is full");
    }
    int i = numElements - 1;
    while(i >= 0 && data < myQueue[i]){
        myQueue[i+1] = myQueue[i];
        i--;
    }
    myQueue[i+1] = data;
    numElements++;
}

template <class T>
T ABQueue<T>::remove(){
    if(isEmpty()){
        throw runtime_error("queue is empty");
    }
    numElements--;
    return myQueue[front++];
    front %= mSize;
}


template <class T>
T ABQueue<T>::peek(){
    return myQueue[front];
}

template <class T>
bool ABQueue<T>::isFull(){
    return numElements == mSize;
}

template <class T>
bool ABQueue<T>::isEmpty(){
    return numElements == 0;
}

template <class T>
unsigned int ABQueue<T>::getSize(){
    return numElements;
}

template <class T>
void ABQueue<T>::printArray(){
  cout << "Q SIZE: " << getSize() << endl;
  cout << "FRONT: " << front <<endl;
  cout << "REAR: " << rear << endl;
  for(int i = 0; i < mSize; ++i){
     cout << "Q["<< i << "]: " << myQueue[i];
     if(i != mSize-1){
       cout << " | ";
     }
  }
  cout << endl;
}

#endif