#include <bits/stdc++.h>
#include <list>

using namespace std;

int main()
{
    list<int> l;
    l.push_back(2);
    l.push_front(1);
    for(int i: l){
        cout<<i<<" ";
    }cout<<endl;

    l.erase(l.begin());
    cout<<"after erase"<<endl;
    for(int i:l){
        cout<<i<<"  ";
    }cout<<endl;

    cout<<"size of list " <<l.size()<<endl; 


    return 0;
}