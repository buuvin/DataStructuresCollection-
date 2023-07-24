#ifndef TREENODE_H
#define TREENODE_H

#include<iostream>
using namespace std;

template<class T>
class TreeNode{

public:
    TreeNode();
    TreeNode(T data);
    TreeNode(TreeNode<T>* node);
    virtual ~TreeNode();

    bool operator ==(TreeNode<T>* node);

    T key;
    TreeNode<T> *left;
    TreeNode<T> *right;
    bool color;

};

template<class T>
TreeNode<T>::TreeNode(){
    left = NULL;
    right = NULL;
    key = NULL;
    color = false;
}

template <class T>
TreeNode<T>::TreeNode(T k){
    left = NULL;
    right = NULL;
    key = k;
    color = false;
}

template <class T>
TreeNode<T>::TreeNode(TreeNode<T>* node){
    this->left = node->left;
    this->right = node->right;
    this->key = node->key;
    this->color = node->color;
}

template <class T>
TreeNode<T>::~TreeNode(){
    left = NULL;
    right = NULL;
}

template <class T>
bool TreeNode<T>::operator ==(TreeNode<T>* node) { 
    if(this == NULL && node == NULL)
        return true;
    else if(this == NULL || node == NULL)
        return false;

    return this->key == node->key; 
}

#endif