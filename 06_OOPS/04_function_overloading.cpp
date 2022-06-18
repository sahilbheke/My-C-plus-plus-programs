#include <bits/stdc++.h>
using namespace std;

class apnacollege{
    public:
    void fun(){
        cout<<"I am fuction with no arrgument"<<endl;
    }
    void fun(int x){
        cout<<"I am fuction with int arrgument"<<endl;
    }
    void fun(double){
        cout<<"I am fuction with double arrgument"<<endl;
    }
};

int main()
{
    apnacollege ap;
    ap.fun();
    ap.fun(2);
    ap.fun(4.4);
    
    return 0;
}