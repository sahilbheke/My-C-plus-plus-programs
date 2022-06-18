#include <bits/stdc++.h>
using namespace std;

class hero{
    char level;
    public:
    
    int health;
    void setlevel(char l){
        level=l;
    }
    void sethealth(int h){
        health=h;
    }
    char getlevel(){
        return this->level;
    }
    int gethealth(){
        return health;
    }

};

int main()
{
    hero sahil;
    sahil.sethealth(50);
    // sahil.level='A';
    sahil.setlevel('A');
    cout<<"sahil health is  "<<sahil.health<<endl;
    cout<<"sahil health is  "<<sahil.gethealth()<<endl;
    cout<<"sahil level is  "<<sahil.getlevel()<<endl;
    // cout<<"sahil level is  "<<sahil.level<<endl;
    return 0;
}