#include <bits/stdc++.h>

using namespace std;

class base{
    public:
    void print(){
        cout<<"This is the base class's print function\n";
    }
    virtual void display(){
        cout<<"This is the base class's display function\n";
    }
};
class derived : public base{
    public:
    void print(){
        cout<<"This is the derived class's print function\n";
    }
    void display(){
        cout<<"This is the derived class's display function\n";
    }
};

int main()
{
    base *base;
    derived d;
    base=&d;
    base ->display();
    base->print();
    
    return 0;
}