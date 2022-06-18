#include <bits/stdc++.h>

using namespace std;

int main()
{
    stack<string> s;
    s.push("sahil ");
    s.push("ramdas ");
    s.push("bheke ");

    cout<< "top element "<<s.top()<<endl;

    s.pop();
    cout<<"top element "<<s.top()<<endl;

    cout<<"size of stack"<<s.size()<<endl;
    cout<<"empty or not"<<s.empty()<<endl;

    

    return 0;
}