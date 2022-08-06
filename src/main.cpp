#include <iostream>
#include <string>
#include <list>
#include <bits/stdc++.h>
#include <chrono>
#include <ArrayList.hpp>
using namespace std;
using namespace std::chrono;


int main(){
    auto start = high_resolution_clock::now();
    
    int n;
    cout << "Enter factorial number: ";
    cin >> n;
    /*
    vectorClass List = listAdd(n);
    List.print();
    vectorClass Result ;
    factBig(List, n, Result);*/

    cout <<"Result is : ";
    arr = new ArrayList();

    /*----------------timer----------------*/
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<seconds>(stop - start);
    cout << "Time: " << duration.count() << endl;
    return 0;
}
