#include <bits/stdc++.h>

using namespace std;

class hero{
    
    public:
    hero(){
        cout<<"default constructor"<<endl;
    }
    hero(int health, char level){
        this->health=health;
        this->level=level;
        cout<<"Health is: "<<health<<endl;
        cout<<"Level is: "<<level<<endl;

    }
    hero(hero& temp){
        cout<<"copy constructor"<<endl;
        this->health=temp.health;
        this->level=temp.level;
        cout<<health<<endl;
        cout<<level<<endl;
    }
    char level;
    int health;
    void setlevel(char l){
        level=l;
    }
    void sethealth(int h){
        health=h;
    }
    char getlevel(){
        return level;
    }
    int gethealth(){
        return health;
    }
    void print(){
        cout<<"Level is: "<<level<<endl;
        cout<<"health is: "<<health<<endl;
    }
    ~hero(){
        cout<<"Derstructor is called"<<endl;
    }
  
};

int main()
{   //object created statically
    hero sahil(29,'a');
    sahil.print();

    //dynamically
    hero *s=new hero(84,'b');
    s->print();

    hero k(sahil);
    // k.print();
    

    return 0;
}