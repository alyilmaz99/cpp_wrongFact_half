#include <Arraylist.hpp>
#include <iostream>

Arraylist::Arraylist() {
    length = 0;
    capacity = 0;
    items = 0;
}
void Arraylist::reverse(int newCapacity) {
    if (capacity >= newCapacity) return; 
    char *tmp = new char[newCapacity]; 
    for (int i = 0; i < length; i++) { 
        tmp[i] = items[i];
    }
    if (items != 0) { 
        delete[] items;
    }
    items = tmp; 
    capacity = newCapacity; 
}
void Arraylist::add(char item) {

    insert(length, item);
}
int Arraylist::size() const 
{
    return length;
}

void Arraylist::clear() {
    length = 0;
}

Arraylist::~Arraylist() {

    if (items != NULL) {

        delete[] items;
    }
}