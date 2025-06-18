#ifndef RBTREE_H
#define RBTREE_H

#include "TreeNode.h"
#include "bst.h"
#include<iostream>
using namespace std;

template <class T>
class RBTree{

public:
    RBTree();
    virtual ~RBTree();

    void insert(T value);
    void insert(TreeNode<T>* gp, TreeNode<T>* parent, TreeNode<T>* uncle, TreeNode<T>* curr, TreeNode<T>* node);
    void rotateRight(TreeNode<T>* gp, TreeNode<T>* parent, TreeNode<T>* uncle, TreeNode<T>* curr);
    void rotateLeft(TreeNode<T>* gp, TreeNode<T>* parent, TreeNode<T>* uncle, TreeNode<T>* curr);
    bool contains(T value);
    void remove(T value);
    void removeNode(TreeNode<T>* gp, TreeNode<T>* parent, TreeNode<T>* sibling, TreeNode<T>* curr, TreeNode<T>* node);
    void deleteNode(TreeNode<T>* parent, TreeNode<T>* curr);
    bool isEmpty();

    T* getMin();
    T* getMax();

    TreeNode<T> *getSuccessor(TreeNode<T>* d);
    void printTree();
    void recPrint(TreeNode<T> *node);
    TreeNode<T> *getRoot();

protected:
    TreeNode<T> *root;
    int rBlackHeight;
    int lBlackHeight;
    bool isLeft;
};

template <class T>
RBTree<T>::RBTree(){
    root = NULL;
    rBlackHeight = 0;
    lBlackHeight = 0;

}

template <class T>
RBTree<T>::~RBTree(){

}

template <class T>
TreeNode<T>* RBTree<T>::getRoot(){
    return root;
}

template <class T>
void RBTree<T>::recPrint(TreeNode<T> *node){
    if(node == NULL)
        return;
    
    cout << node->key << " " << node->color << endl;
    recPrint(node->left);
    recPrint(node->right);
}

template <class T>
void RBTree<T>::printTree(){
    recPrint(root);
}

template <class T>
bool RBTree<T>::isEmpty(){
    return root == NULL;
}

template <class T>
T* RBTree<T>::getMin(){
    if(isEmpty())
        return NULL;
    
    TreeNode<T> *curr = root;
    while(curr->left != NULL)
        curr = curr->left;
    
    return curr->key;
}

template <class T>
T* RBTree<T>::getMax(){
    if(isEmpty())
        return NULL;
    
    TreeNode<T> *curr = root;
    while(curr->right != NULL)
        curr = curr->right;
    
    return curr->key;
}

template <class T>
void RBTree<T>::insert(T value){
    TreeNode<T>* node = new TreeNode<T>(value);

    if(isEmpty()){
        root = node;
        return;
    }
    node->color = true;
    insert(root, root, NULL, root, node);
}

template <class T>
void RBTree<T>::insert(TreeNode<T>* gp, TreeNode<T>* parent, TreeNode<T>* uncle, TreeNode<T>* curr, TreeNode<T>* node){
 
    gp = parent;
    if(*curr == parent->right)
        uncle = parent->left;
    else  
        uncle = parent->right;
    parent = curr;
    if(node->key < curr->key){
        curr = curr->left;
        if(curr == NULL) {
            parent->left = node;
            curr = node;
        }
        else{
            insert(gp, parent, uncle, curr, node);
        }
    }
    else {
        curr = curr->right;
        if(curr == NULL) {
            parent->right = node;
            curr = node;
        }
        else{
            insert(gp, parent, uncle, curr, node);
        }
    }

    cout << endl;
    cout << "Node added is: " << node->key << endl;
    cout << "GP is: " << gp->key << endl;
    cout << "parent is: " << parent->key << endl;
    cout << "uncle is: ";
    if(uncle == NULL) cout << "NULL" << endl;
    else cout << uncle->key << endl;
    cout << "curr is: " << curr->key << endl;
    if(parent->right != NULL)
        cout << "sibling is: " << parent->right->key << endl;
    cout << endl;
    //cases
    if(*parent == root && parent->color){
        cout << "case 1" << endl;
        parent->color = false;
    }
    else if(parent->color && uncle != NULL && uncle->color){
        cout << "case 2" << endl;
        gp->color = true;
        parent->color = false;
        uncle->color = false;
    }
    else if(curr->color && parent->color){
        //right parent
        if(*gp->right == parent){
            //outer grandchild
            if(*parent->right == curr){
                cout << "case 3a" << endl;
                rotateLeft(gp, parent, uncle, curr);
            }
            //inner grandchild
            else{
                cout << "case 3b" << endl;
                TreeNode<T>* tmp = new TreeNode<T>(parent);
                parent = curr;
                tmp->left = parent->right;
                parent->right = tmp;
                curr = tmp;
                rotateLeft(gp, parent, uncle, curr);
            }
        }
        //left parent
        else{
            //outer grandchild
            if(*parent->left == curr){
                cout << "case 3c" << endl;
                rotateRight(gp, parent, uncle, curr);
            }
            //inner grandchild
            else{
                cout << "case 3d" << endl;
                TreeNode<T>* tmp = new TreeNode<T>(parent);
                parent = curr;
                tmp->right = parent->left;
                parent->left = tmp;
                curr = tmp;
                rotateRight(gp, parent, uncle, curr);
                cout << "GP is: " << gp->key << endl;
                cout << "parent is: " << parent->key << endl;
                cout << "curr is: " << curr->key << endl;
                if(parent->right != NULL)
                    cout << "sibling is: " << parent->right->key << endl;
            }
        }
    }



    /*
    cout << "Node added is: " << node->key << endl;
    cout << "GP is: " << gp->key << endl;
    cout << "parent is: " << parent->key << endl;
    cout << "uncle is: ";
    if(uncle == NULL) cout << "NULL" << endl;
    else cout << uncle->key << endl;
    cout << "curr is: " << curr->key << endl;
    */
}


template <class T>
void RBTree<T>::remove(T value){
    TreeNode<T>* node = new TreeNode<T>(value);

    if(isEmpty()){
        cout << "Tree is already empty" << endl;
        return;
    }
    if(node == root && root->right == NULL && root->left == NULL){
        root = NULL;
        return;
    }
    node->color = true;
    removeNode(root, root, NULL, root, node);
}

template <class T>
void RBTree<T>::removeNode(TreeNode<T>* gp, TreeNode<T>* parent, TreeNode<T>* sibling, TreeNode<T>* curr, TreeNode<T>* node){

    bool isLeft = true;
    gp = parent;
    parent = curr;
    if(node->key != k){ // to find node to delete
    
        if(k < curr->key){
            sibling = curr->right;
            curr = curr->left;
            removeNode(gp, parent, sibling, curr, node);
        }
        else{
            isLeft = false;
            sibling = curr->left;
            curr = curr->right;
            removeNode(gp, parent, sibling, curr, node);
        }

        if(curr == NULL)
            return false;
    }
    deleteNode(parent, curr);

    //case 1
    
}

template <class T>
void RBTree<T>::deleteNode(TreeNode<T>* parent, TreeNode<T>* curr){
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
}

template <class T>
TreeNode<T>* RBTree<T>::getSuccessor(TreeNode<T>* d){
    // d reps node that is going to be deleted
    TreeNode<T>* sp = d;
    TreeNode<T> *successor = d;
    TreeNode<T>* curr = d->right;

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


template <class T>
void RBTree<T>::rotateLeft(TreeNode<T>* gp, TreeNode<T>* parent, TreeNode<T>* uncle, TreeNode<T>* curr){
    TreeNode<T>* tmp = new TreeNode<T>(gp);
    *gp = *parent; 
    tmp->right = gp->left;
    gp->left = tmp;
    gp->right = curr;
    *curr = *gp->right;

    gp->color = false;
    curr->color = true;
    gp->left->color = true;
} 

template <class T>
void RBTree<T>::rotateRight(TreeNode<T>* gp, TreeNode<T>* parent, TreeNode<T>* uncle, TreeNode<T>* curr){
    TreeNode<T>* tmp = new TreeNode<T>(gp);
    *gp = *parent;
    tmp->left = gp->right;
    gp->right = tmp;
    gp->left = curr;
    *curr = *gp->left;

    gp->color = false;
    curr->color = true;
    gp->right->color = true;
}
#endif




// Links used:
// https://www.google.com/search?q=red+black+tree+cases&oq=red+black+tree+cases&aqs=chrome..69i57j0i512l9.6761j0j1&sourceid=chrome&ie=UTF-8
// https://www.cs.usfca.edu/~galles/visualization/RedBlack.html
// https://www.happycoders.eu/algorithms/red-black-tree-java/
// https://www.geeksforgeeks.org/applications-advantages-and-disadvantages-of-red-black-tree/
