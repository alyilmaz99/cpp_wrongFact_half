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
    return 1;
    }else{
    return n*fact(n-1);
    }
}
int decimalP(int number){
   int a=0;
   while(number >0){
    number = number /10;
    a++;
   }
   return a;

}
vectorClass<int> factBig(vectorClass<int> v, int n, vectorClass<int> result){
    cout <<"n : " << n << endl;
    
    if(n==0){
        return result;
        cout << "direkt result degeri dondu" <<endl;
    }else{
        int sayac =0;
        cout << "else icerisine girdi" << " result degeri: " << result.get(0) << endl;
        int numberCatch = v.get(n);
        cout <<"numberCatch: " <<numberCatch << endl;
        v.pop();
        int secondNumber = v.get(n-1);
        cout <<"secondNumber: " <<secondNumber << endl;
        vectorClass<int> counter ;
        vectorClass<int> empty;
        int place = decimalP(secondNumber);
        for(int i = place; i >0 ; i--){

            cout << "for1 icerisine girdi" << "place: " << place <<endl;
            int numberBasamak = 1;
                numberBasamak *= pow(10,i-1);
                cout <<"numberBasamak: " << numberBasamak <<endl;
               if(numberBasamak == 1){
                int catchs = (secondNumber / numberBasamak);
               cout <<"catchs: " << catchs <<endl;
               counter.push(catchs);
               counter.print();
               }else{
                int catchs = (secondNumber / numberBasamak);
               cout <<"catchs: " << catchs <<endl;
               secondNumber = secondNumber -(catchs*numberBasamak);
                cout <<"secondNumber" << secondNumber <<endl;
                counter.push(catchs);
                counter.print();
               }
        }
        for(int k = 0; k < counter.getcapacity(); k++){
            cout << "for2 icerisine girdi" <<endl;
            if(result.get(0) == 0){
                sayac++;
                result.push(counter.get(k)*numberCatch);
                cout<< "result: ";
                result.print();
            }else if (sayac == 1){
                sayac++;
                empty.push(result.get(0));
                cout<< "empty: ";
                empty.print();
                result.pop();
                cout<< "result: ";
                result.print();
                result.push((empty.get(0))+(numberCatch*counter.get(k)));
                cout<< "result: ";
                result.print();
                empty.pop();
                cout<< "empty: ";
                empty.print();
            }else{
                sayac++;
                empty.push(result.get(0));
                cout<< "empty: ";
                empty.print();
                result.pop();
                cout<< "result: ";
                result.print();
                vectorClass<int> third ;
                third.push((empty.get(0)*counter.get(k)));
                empty.pop();
                result.push(third.get(0));  
                third.pop();
                cout << "result :---";
                result.print();
            }
        }
        return factBig(v,n-2,result);
    }
    return result;
}

int main(){
    auto start = high_resolution_clock::now();

    int n;
    cout << "Enter factorial number: ";
    cin >> n;
    vectorClass<int> List = listAdd(n);
    List.print();
    vectorClass<int> Result ;
    factBig(List, n, Result);
    cout <<"Result is : ";
    Result.print();

    /*----------------timer----------------*/
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<seconds>(stop - start);
    cout << "Time: " << duration.count() << endl;
    return 0;
}
