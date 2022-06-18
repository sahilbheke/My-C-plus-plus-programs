#include <bits/stdc++.h>
using namespace std;

class A{
    public:
        void func(){
            cout<<"inherited (base class)"<<endl;
        }
};
class B : public A{
    
};

int main()
{
    B b;
    b.func();
    return 0;
}