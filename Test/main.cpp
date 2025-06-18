#include "dog.h"
#include <iostream>
using namespace std;

int main(int argc, char** argv){
    Dog d;
    d.bark();

    Dog* e = new Dog("Gatsby", 7, "Beagle");
    e->bark();
    delete e;

    cout << "woof" << endl;
    //string name = (argv[1]);
    string name = "boob";
    cout << "woof1" << endl;
    Dog g (name, 2, "Spaniel"); // ./test fred

    int count = 20;
    int* count2 = new int(20); 

    cout << "The count is " << count << endl; // prints 20
    cout << "The count is " << count2 << endl; // prints memory address

   /*  for(int i = 0; i < argc; ++i)
    {
        cout << argv[i] << endl;
    } */
}

/* NOTES
Dog* = memory allocation, tells that we need 64gb of memory for dog
e->bark = derefrences and runs bark
% = memory address, if printed would print numerical memory address

new = creates chunk of memory, constructor
delete = tells computer your done with memory, destructor 
memory leaks = when new memory is allocated and constructed and not properly deconstructed
*/



