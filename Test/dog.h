#ifndef DOG_H
#define DOG_H

#include <string>
using namespace std;

class Dog{
public:
    Dog();
    Dog(string name, int age, string breed);
    virtual ~Dog();

    void bark();

    string getName();
    void setName(string name);

    string getBreed();
    int getAge();

private:
    string m_name;
    int m_age;
    string m_breed;
};

#endif

/* NOTES
m_ = member of the class
virtual = can inherit and overide method, cant inherit unless declared virtual
*/