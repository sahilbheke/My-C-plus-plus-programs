#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main()
{
    vector<int> a(5,1);
    vector<int> copy(a);
    cout<< "a = ";
    for(int i:a){
        cout<<i<<" ";
    }cout<<endl;
    
    vector<int> v;

    cout<<"Capacity of vector "<<v.capacity()<<endl;
    v.push_back(2);
    cout<<"Capacity of vector "<<v.capacity()<<endl;
    v.push_back(3);
    cout<<"Capacity of vector "<<v.capacity()<<endl;
    v.push_back(29);
    cout<<"Capacity of vector "<<v.capacity()<<endl;
    v.push_back(49);
    cout<<"Capacity of vector "<<v.capacity()<<endl;
    v.push_back(4);
    cout<<"Capacity of vector "<<v.capacity()<<endl;
    cout<<endl;

    cout<<"size of vector "<<v.size()<<endl;
    cout<<endl;

    cout<<"Element of 0th index "<<v.at(0)<<endl;
    cout<<"Element at fornt "<<v.front()<<endl;
    cout<<"Element at back "<<v.back()<<endl;
    cout<<endl;

    cout<<"before pop ";
    for(int i:v){
        cout<<i<<" ";
    }cout<<endl;

    v.pop_back();

    cout<<"after pop"<<endl;
    for(int i:v){
        cout<<i<<" ";
    }cout<<endl<<endl;

    cout<<"before clear"<<endl;
    cout<<"size of vector "<<v.size()<<endl;
    v.clear();
    cout<<"after clear"<<endl;
    cout<<"size of vector "<<v.size()<<endl<<endl;

    

    return 0;
}