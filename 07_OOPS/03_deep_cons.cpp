#include <bits/stdc++.h>

using namespace std;

class hero{
    
    public:
    char level;
    int health;
    char *name;

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
  
};

int main()
{   
    hero hero01;
    hero01.sethealth(12);
    hero01.setlevel('a');
    char name[7]="babbar";
    hero01.setname(name);
    hero01.print();
    
    hero hero02(hero01);
    //hero hero02=hero01;
    hero02.print();

    hero01.name[0]='G';
    hero01.print();
    hero02.print();

    return 0;
}