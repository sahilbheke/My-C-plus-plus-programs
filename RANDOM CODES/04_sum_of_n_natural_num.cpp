#include <bits/stdc++.h>
using namespace std;

int func(int n){
    int k=0;
    for(int i=1; i<=n; i++)
        k+=i;
    return k;
}

int main(){

int n;
cin>>n;

cout<<func(n);

return 0;
}