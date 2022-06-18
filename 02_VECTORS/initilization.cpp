#include <bits/stdc++.h>
#include<vector>
using namespace std;
int main(){

    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<endl;                    //without iterator 
    }  //1 2 3

    vector<int> :: iterator it;
    for(it=v.begin(); it!= v.end(); it++){     //cout using iterator
        cout<<*it<<endl;
    }  //1 2 3  
    

    for(auto element : v){
        cout<<element<<endl;
    }  // 1 2 3

    v.pop_back();

    vector<int> v2(3,50);
    // 50 50 50

    swap(v,v2);
    for(auto element : v){
        cout<<element<<endl;
    } //50 50 50
    for(auto element : v2){
        cout<<element<<endl;
    } //1 2  

    vector<int> v1;
    v1.push_back(6);
    v1.push_back(4);
    v1.push_back(5);

    sort(v1.begin(),v1.end());
    for(auto element : v1)
        cout<<element<<" ";
    cout<<endl;


return 0;
}