#include "RBTree.h"

int main(int argc, char **argv){
    RBTree<int>* bst1 = new RBTree<int>();

    bst1->insert(50); 
    bst1->insert(30);
    bst1->insert(70);
    bst1->insert(20);
    bst1->insert(40);
    bst1->insert(37);
    bst1->insert(44);
    bst1->insert(10);
    bst1->insert(17);
    bst1->insert(60);
    bst1->insert(90);
    bst1->insert(38);

    // bst1->insert(17);
    // bst1->insert(9);
    // bst1->insert(45);
    // bst1->insert(32);
    // bst1->insert(76);
    // bst1->insert(50);
    // bst1->insert(48);
    //bst1->insert(17);




    //bst1->deleteNode(30);

    bst1->printTree();


}