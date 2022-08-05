#include <iostream>
#include <string>
#include <list>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;

template <typename T> class vectorClass{
    T* arr;
    int capacity;
    int current;

public:

    vectorClass(){
        arr = new T[1];
        capacity = 1;
        current =0;
    }
    ~ vectorClass(){
        delete [] arr;
    }
    void push(T data){
        if (current == capacity) {

            T* temp = new T[2 * capacity];
            for (int i = 0; i < capacity; i++) {
                temp[i] = arr[i];
            }
            delete[] arr;
            capacity *= 2;
            arr = temp;
        }
        arr[current] = data;
        current++;
    }
    void push(T data, int index)
    {
        if (index == capacity)
            push(data);
        else
            arr[index] = data;
    }
    T get(int index)
    {
        if (index < current)
            return arr[index];
    }
    void pop() { current--; }
    int size() { return current; }
    int getcapacity() { return capacity; }
    void print()
    {
        for (int i = 0; i < current; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

};
vectorClass<int> listAdd(int n){
    vectorClass<int> v;
    for(int i =1 ; i <=n ; i++){
        v.push(i);
    }
    return v;
}
int fact(int n){
    if(n==0){
    return 0;
    }else{
    return n*fact(n-1);
    }
}
int main(){
    auto start = high_resolution_clock::now();

    int n;
    cout << "Enter factorial number: " << endl;
    cin >> n;
    vectorClass<int> List = listAdd(n);
    List.print();

    cout << fact(n) <<endl;

    /*----------------timer----------------*/
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<seconds>(stop - start);
    cout << duration.count() << endl;
    return 0;
}
