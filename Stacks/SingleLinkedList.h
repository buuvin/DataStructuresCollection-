#ifndef SINGLELINKEDLIST_H
#define SINGLELINKEDLIST_H

#include "ListNode.h"

template <class T>
class SingleLinkedList{

private:
    ListNode<T>* front;//head of list
    ListNode<T>* back; // tail of list
    unsigned int size;
public:
    SingleLinkedList();
    ~SingleLinkedList();

    void insertFront(T d);
    void insertBack(T d);
    int find(T value);
    T at(int ind);
    T removeFront();
    T removeBack();
    T deleteAtPos(int pos);
    int deleteData(T d);
    bool isEmpty();
    unsigned int getSize();
    void printList();

};
#endif

template <class T>
SingleLinkedList<T>::SingleLinkedList(){
    front = NULL;
    back = NULL;
    size = 0;
}
template <class T>
SingleLinkedList<T>::~SingleLinkedList(){

}

template <class T>
int SingleLinkedList<T>::find(T value){
    int pos = -1;
    ListNode<T>* curr = front;

    while(curr->data != value){
        ++pos;
        if(curr->data == value){
            break;
        }
        curr = curr->next;
    }

    if(curr == 0){
        pos = -1;
    }

    return pos;
}

template <class T>
T SingleLinkedList<T>::at(int ind){
    ListNode<T>* curr = front;
    int i = 0;
    while(i < ind){
        curr = curr->next;
        i++;
    }
    return curr->data;
}

template <class T>
void SingleLinkedList<T>::insertFront(T d){
    ListNode<T>* node = new ListNode<T>(d);

    if(isEmpty()){
        back = node;
    }
    else{
        node->next = front;
    }
    front = node;
    size++;
}

template <class T>
void SingleLinkedList<T>::insertBack(T d){
    ListNode<T>* node = new ListNode<T>(d);

    if(isEmpty()){
        front = node;
    }
    else{
        back->next = node;
    }
    back = node;
    size++;
}

template <class T>
T SingleLinkedList<T>::removeFront(){
    if(isEmpty()) {
        cerr << "list is empty" << endl;
        return -1;
    }
    int temp = front->data;
    ListNode<T>* ft = front;

    front = front->next;
    ft->next = NULL;
    delete ft;

    size--;
    return temp;
}

template <class T>
T SingleLinkedList<T>::removeBack(){
    if(isEmpty()) {
        cerr << "list is empty" << endl;
        return -1;
    }
    int temp = back->data;
    ListNode<T>* curr = new ListNode<T>();
    ListNode<T>* prev = new ListNode<T>();
    curr = front;
    prev = curr;

    while(curr->next != back)
    {
        prev = curr;
        curr = curr->next;
    }
    back = prev->next;
    curr->next = NULL;
    //delete bt;

    size--;
    return temp;
}

template <class T>
T SingleLinkedList<T>::deleteAtPos(int pos){
    if(isEmpty()){
        return -1;
    }
    int idx = 0;
    ListNode<T> *curr = new ListNode<T>();
    ListNode<T> *prev = new ListNode<T>();

    while(idx != pos){
        prev = curr;
        curr = curr->next;
        idx++;
    }
    prev->next = curr->next;
    curr->next = NULL;
    T d = curr->data;
    delete curr;
    size--;

    return d;
}

template <class T>
int SingleLinkedList<T>::deleteData(T d){
    if(isEmpty()){
        return -1;
    }
    if(front->data == d){
        return removeFront();
    }else if(back->data == d){
        return removeBack();
    }

    int idx = 0;
    ListNode<T> *curr = new ListNode<T>();
    ListNode<T> *prev = new ListNode<T>();
    curr = front;

    while(curr->data != d && curr != NULL)
    {
        prev = curr;
        curr = curr->next;
        idx++;
    }
    if(curr == NULL){
        return -1;
    }
    prev->next = curr->next;
    curr->next = NULL;
    delete curr;
    //delete bt;

    size--;

    return idx;
}

template <class T>
bool SingleLinkedList<T>:: isEmpty(){
    return size == 0;
}

template <class T>
void SingleLinkedList<T>::printList(){
    if(isEmpty()){
        cout << "The list is empty" << endl;
        return;
    }
    ListNode<T> *curr = front;
    while(curr != NULL){
        cout << "[ " << curr->data << " ] ";
       curr = curr->next;
       if(curr != 0){
         cout << " ==> ";
       }
    }
    cout << endl;

}