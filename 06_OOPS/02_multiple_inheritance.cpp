#include <bits/stdc++.h>
using namespace std;

class A{
    public:
    void Afunc(){
        cout<<"Fuction A\n";
    }
};
class B{
    public:
    void Bfunc(){
        cout<<"Fuction B\n";
    }
};
class C : public A, public B{
    public:
    
};

int main()
{
    C c;
    c.Afunc();
    c.Bfunc();
    return 0;
}