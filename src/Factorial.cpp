
vectorClass listAdd(int n){
    vectorClass v;
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
vectorClass factBig(vectorClass v, int n, vectorClass result){
    cout <<"n : " << n << endl;
    
    if(n==0){
        return result;
        cout << "direkt result degeri dondu" <<endl;
    }else{
        int sayac =0;
        int sayac2 =0;
        cout << "else icerisine girdi" << " result degeri: " << result.get(0) << endl;
        int numberCatch = v.get(n);
        cout <<"numberCatch: " <<numberCatch << endl;
        v.pop();
        int secondNumber = v.get(n-1);
        cout <<"secondNumber: " <<secondNumber << endl;
        vectorClass counter ;
        vectorClass empty;
        vectorClass third ;
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
                if(sayac2 == 1){
                empty.push(result.get(0));
                 cout<< "empty: ";
                empty.print();
                result.pop();
                result.print();
                cout << "third this: ";
                third.print();
                cout <<"counter : ";
                counter.print();
                result.push((empty.get(0))+(third.get(0)*counter.get(k)));
                cout <<"result: " ;
                result.print();
                empty.pop();
                third.pop();
                
                }else{
                sayac++;
                empty.push(result.get(0));
                cout<< "empty: ";
                empty.print();
                result.pop();
                cout<< "result: ";
                result.push((empty.get(0))+(numberCatch*counter.get(k)));
                result.print();
                empty.pop();
                cout<< "empty: ";
                empty.print();
                }
            }else{
                sayac2++;
                sayac++;
                empty.push(result.get(0));
                cout<< "empty: ";
                empty.print();
                result.pop();
                cout<< "result: ";
                result.print();
                third.push(empty.get(0));
                cout <<"third : ";
                third.print();
                result.push((third.get(0)*counter.get(k)));
                empty.pop(); 
                cout << "result : ";
                result.print();
                cout <<"sayac: " <<sayac <<endl;
            }
        }
        
        if(n > 1){
            cout << "end of n : " <<n <<endl;
            return factBig(v,n-1,result);
        }
        else{
            result.pop();
            result.push(third.get(0));
            return result;
        }
    }
}