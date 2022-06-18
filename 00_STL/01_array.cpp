#include <bits/stdc++.h>
#include <array>

using namespace std;

int main()
{
    array<int,4> a = {1,2,3,4};
    int size = a.size();
    for(int i=0; i<size; i++){
        cout<<a[i]<<endl;
    }
    cout<<"element at second element "<<a.at(2)<<endl;
    cout<<"emty or not "<<a.empty()<<endl;
    cout<<"fornt element "<<a.front()<<endl;
    cout<<"back element "<<a.back()<<endl;

    return 0;
}