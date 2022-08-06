
#ifndef ARRAYLIST_HPP
#define ARRAYLIST_HPP



class Arraylist{
public:
    Arraylist();
    void add( char item);
    void insert(int i, char item);
    int size() const;
    void clear();
    ~Arraylist();
    
private:
    char *items;
    int length;
    int capacity;
    void reverse(int);
};


#endif /* ARRAYLIST_HPP *