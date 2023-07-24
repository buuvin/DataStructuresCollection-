#ifndef BST_H
#define BST_H

#include "TreeNode.h"
#include<iostream>
using namespace std;

template <class T>
class BST{

public:
    BST();
    virtual ~BST();

    void insert(T value);
    bool contains(T value);
    bool deleteNode(T k);
    bool isEmpty();

    T* getMin();
    T* getMax();

    TreeNode<T> *getSuccessor(TreeNode<T>* d);
    void printTree();
    void recPrint(TreeNode<T> *node);
    TreeNode<T> *getRoot();

protected:
    TreeNode<T> *root;
};

template <class T>
BST<T>::BST(){
    root = NULL;

}

template <class T>
BST<T>::~BST(){

}

template <class T>
TreeNode <T>* BST<T>::getRoot(){
    return root;
}

template <class T>
void BST<T>::recPrint(TreeNode<T> *node){
    if(node == NULL)
        return;
    
    cout << node->key << endl;
    recPrint(node->left);
    recPrint(node->right);
}

template <class T>
void BST<T>::printTree(){
    recPrint(root);
}

template <class T>
bool BST<T>::isEmpty(){
    return root == NULL;
}

template <class T>
T* BST<T>::getMin(){
    if(isEmpty())
        return NULL;
    
    TreeNode<T> *curr = root;
    while(curr->left != NULL)
        curr = curr->left;
    
    return curr->key;
}

template <class T>
T* BST<T>::getMax(){
    if(isEmpty())
        return NULL;
    
    TreeNode<T> *curr = root;
    while(curr->right != NULL)
        curr = curr->right;
    
    return curr->key;
}

template <class T>
void BST<T>::insert(T value){
    TreeNode<T>* node = new TreeNode<T>(value);

    if(isEmpty()){
        root = node;
        return;
    }

    TreeNode<T>* curr = root;
    TreeNode<T>* parent = NULL;

    while(true){
        parent = curr;
        if(value < curr->key){
            curr = curr->left;
            if(curr == NULL) {
                parent->left = node;
                break;
            }
        }
        else {
            curr = curr->right;
            if(curr == NULL) {
                parent->right = node;
                break;
            }
        }
    }
}

template <class T>
bool BST<T>::contains(T value){
    if(isEmpty()){
        return false;
    }
    TreeNode<T>* curr = root;
    bool isFound = false;
    while(curr->key != value){
        if(value < curr->key)
            curr = curr->left;
        else   
            curr = curr->right;
        
        if(curr == NULL)
            return false;
    }
    return true;
}

template <class T>
bool BST<T>::deleteNode(T k){
    if(isEmpty()){
        return false;
    }

    TreeNode<T>* curr = root;
    TreeNode<T>* parent = root;
    bool isLeft = true;

    while(curr->key != k){ // to find node to delete
        parent = curr;

        if(k < curr->key){
            curr = curr->left;
        }
        else{
            isLeft = false;
            curr = curr->right;
        }

        if(curr == NULL)
            return false;
    }
    //node to be deleted is a leaf node, no children
    if(curr->left == NULL && curr->right == NULL){
        if(curr == root)
            root = NULL;
        else if(isLeft)
            parent->left = NULL;
        else   
            parent->right = NULL;
    }

    //node to be deleted has one child, left child
    else if(curr->right == NULL){
        if(curr == root)
            root = curr->left;
        else if(isLeft)
            parent->left = curr->left;
        else
            parent->right = curr->left;
    }
    //node to be deleted has one child, left child
    else if(curr->left == NULL){
        if(curr == root)
            root = curr->right;
        else if(isLeft)
            parent->left = curr->right;
        else
            parent->right = curr->right;
    }
    //node to be deleted has two children
    else{
        TreeNode<T> *successor = getSuccessor(curr);

        if(curr == root)
            root = successor;
        else if(isLeft)
            parent->left = successor;
        else   
            parent->right = successor;

        successor->left = curr->left;
        curr->left = NULL;
        curr->right = NULL;
    }

    delete curr;
    return true;
}

template <class T>
TreeNode<T>* BST<T>::getSuccessor(TreeNode<T>* d){
    // d reps node that is going to be deleted
    TreeNode<T>* sp = d;
    TreeNode<T> *successor = d;
    TreeNode<T>* curr = d->righgit t;

    while(curr != NULL){
        sp = successor;
        successor = curr;
        curr = curr->left;
    }

    if(successor != d->right){
        sp->left = successor->right;
        successor->right = d->right;
    }
    return successor;
}
#endif