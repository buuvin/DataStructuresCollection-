#include "dog.h"

#include <iostream>


Dog::Dog(){
    m_name = "unamed";
    m_age = 0;
    m_breed = "unknown";
}

Dog::Dog(string name, int age, string breed){
    m_name = name;
    m_age = age;
    m_breed = breed;

}

 Dog::~Dog(){
    cout << "The dog " << m_name << " is being freed in memory" << endl;
}

void Dog::bark(){
    cout << "Bark! My name is " << m_name << endl;
}

string Dog::getName(){
    return m_name;
}
void Dog::setName(string name){
    m_name = name;
}

string Dog::getBreed(){
    return m_breed;
}
int Dog::getAge(){
    return m_age;
}