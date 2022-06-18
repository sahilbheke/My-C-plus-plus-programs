#include <bits/stdc++.h>

using namespace std;

class hero{
    
    public:
    char level;
    int health;
    char *name;
    static int timetocomplete;

    hero(){
        cout<<"default constructor"<<endl;
        name= new char[100];
    }
    hero(int health, char level){
        this->health=health;
        this->level=level;
        cout<<"Health is: "<<health<<endl;
        cout<<"Level is: "<<level<<endl;

    }
    hero(hero& temp){
        char *ch=new char[strlen(temp.name)+1];
        strcpy(ch,temp.name);
        this->name=ch;
        cout<<"copy constructor"<<endl;
        this->health=temp.health;
        this->level=temp.level;
    }
    
    void setlevel(char l){
        level=l;
    }
    void sethealth(int h){
        health=h;
    }
    void setname(char name[]){
        strcpy(this->name,name);
    }
    char getlevel(){
        return level;
    }
    int gethealth(){
        return health;
    }
    void print(){
        cout<<"{name is: "<<name<<", ";
        cout<<"Level is: "<<level<<", ";
        cout<<"health is: "<<health<<" }"<<endl;
        
    }
    static int random(){
        return timetocomplete;
    }
};
int hero::timetocomplete=5;
int main()
{   
    cout<<hero::timetocomplete<<endl;
    hero a;
    cout<<a.timetocomplete<<endl;

    hero b;
    b.timetocomplete=10;
    cout<<a.timetocomplete<<endl;
    cout<<b.timetocomplete<<endl;

    cout<<hero::random()<<endl;

    return 0;
}