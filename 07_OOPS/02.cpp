#include <bits/stdc++.h>

using namespace std;

class hero{
    
    public:
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
        cout<<level<<endl;
    }
  
};

int main()
{   //dynamic allocation
    hero *b=new hero;
    b->sethealth(10);
    b->setlevel('n');
    cout<<"health is "<<b->gethealth()<<endl;
    cout<<"level is "<<b->level<<endl;

    cout<<"health is "<<(*b).gethealth()<<endl;
    cout<<"level is "<<(*b).level<<endl;


    return 0;
}