#ifndef ABSTACK_H
#define ABSTACK_H

#include <exception>
#include<iostream>
using namespace std;

template<class T> 
class ABStack{
    
private:
    T* myArray;
    int size;
    int top;

public:

    ABStack(){
        size = 64;
        top = -1;
        myArray = new T[size];
    }
    
    ABStack(int maxSize){
        size = maxSize;
        top = -1;
        myArray = new T[size];
    }

    ~ABStack(){
        delete myArray;
    }

    //core functions
    void push(T data){
        if(isFull())//check if stack is full
            throw runtime_error("stack is full");
        myArray[++top] = data;
    }
    T pop(){
        if(isEmpty())//check if stack is empty
            throw runtime_error("stack is empty");
        return myArray[top--];// dont remove value in A-B stack
    }
    T peek(){ return myArray[top]; } // top()

    //aux functions
    bool isFull(){ return top == size - 1; }
    bool isEmpty(){ return top == -1; }
    int getSize(){ return size; }
};

#endif