/**
* @file Dosya adı
* @description Programınızın açıklaması ne yaptığına dair.
* @course Dersi aldığınız eğitim türü ve grup
* @assignment Kaçıncı ödev olduğu
* @date Kodu oluşturduğunuz Tarih
* @author Kodu Yazan
*/
#include <iostream>
#include <string>
#include <list>
#include <bits/stdc++.h>
#include <chrono>
#include "ArrayList.cpp"
#include "Factorial.cpp"
using namespace std;
using namespace std::chrono;


int main(){
    auto start = high_resolution_clock::now();
    
    int n;
    cout << "Enter factorial number: ";
    cin >> n;
    
    Arraylist List = listAdd(n);
    List.size();
    Arraylist Result ;
    factBig(List, n, Result);

    cout <<"Result is : ";
    Result.get(0);
    /*----------------timer----------------*/
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<seconds>(stop - start);
    cout << "Time: " << duration.count() << endl;
    return 0;
}
