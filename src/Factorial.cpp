#include <iostream>
#include <string>
#include <list>
#include <bits/stdc++.h>
#include <chrono>
#include "ArrayList.hpp"
using namespace std;
using namespace std::chrono;

Arraylist listAdd(int n){
    Arraylist v;
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
Arraylist factBig(Arraylist v, int n, Arraylist result){
    cout <<"n : " << n << endl;
    
    if(n==0){
        return result;
        cout << "direkt result degeri dondu" <<endl;
    }else{
        int sayac =0;
        int sayac2 =0;
        cout << "else icerisine girdi" << " result degeri: " << result.get(0) << endl;
        int numberCatch = v.get(0);
        cout <<"numberCatch: " <<numberCatch << endl;
        v.clear();
        int secondNumber = v.get(n-1);
        cout <<"secondNumber: " <<secondNumber << endl;
        Arraylist counter ;
        Arraylist empty;
        Arraylist third ;
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
               }else{
                int catchs = (secondNumber / numberBasamak);
               cout <<"catchs: " << catchs <<endl;
               secondNumber = secondNumber -(catchs*numberBasamak);
                cout <<"secondNumber" << secondNumber <<endl;
                counter.push(catchs);
               }
        }
        for(int k = 0; k < counter.size(); k++){
            cout << "for2 icerisine girdi" <<endl;
            if(result.get(0) == 0){
                sayac++;
                result.push(counter.get(k)*numberCatch);
            }else if (sayac == 1){
                if(sayac2 == 1){
                empty.push(result.get(0));
                result.clear();
                result.push((empty.get(0))+(third.get(0)*counter.get(k)));
                empty.clear();
                third.clear();
                }else{
                sayac++;
                empty.push(result.get(0));
                result.clear();
                result.push((empty.get(0))+(numberCatch*counter.get(k)));
                empty.clear();
                }
            }else{
                sayac2++;
                sayac++;
                empty.push(result.get(0));
                result.clear();
                third.push(empty.get(0));
                result.push((third.get(0)*counter.get(k)));
                empty.clear(); 
                cout <<"sayac: " <<sayac <<endl;
            }
        }
        
        if(n > 1){
            cout << "end of n : " <<n <<endl;
            return factBig(v,n-1,result);
        }
        else{
            result.clear();
            result.push(third.get(0));
            return result;
        }
    }
}