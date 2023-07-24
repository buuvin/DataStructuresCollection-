#include "ABStack.h"
using namespace std;

int main(int argc, char **argv){
    ABStack<char>* stack1 = new ABStack<char>();
    //GenStack* stack2 = new GenStack();
    try{
        for(int i = 0; i < 8; i++){
            stack1->push('r' + (i + 1));
        }

        cout << "PEEK: " << stack1->peek() << endl;
        cout << "POP: " << stack1->pop() << endl;
        cout << "PEEK: " << stack1->peek() << endl;

        while(!stack1->isEmpty())
            cout << "POPPING: " << stack1->pop() << endl;

        cout << "SIZE: " << stack1->getSize() << endl;
        cout << "POP: " << stack1->pop() << endl;
    }
    catch(runtime_error &excep){
        cout << excep.what() << endl;
    }

    delete stack1;
    return 0;
}