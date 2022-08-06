/**
* @file Dosya adı
* @description Programınızın açıklaması ne yaptığına dair.
* @course Dersi aldığınız eğitim türü ve grup
* @assignment Kaçıncı ödev olduğu
* @date Kodu oluşturduğunuz Tarih
* @author Kodu Yazan
*/
#ifndef ARRAYLIST_HPP
#define ARRAYLIST_HPP



class Arraylist{
public:
    Arraylist();
    void push( char item);
    void insert(int i, char item);
    int size() const;
    void clear();
    char get(int i);
    ~Arraylist();
    
private:
    char *items;
    int length;
    int capacity;
    void reverse(int);
};


#endif /* ARRAYLIST_HPP */