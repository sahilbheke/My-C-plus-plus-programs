#include <bits/stdc++.h>
using namespace std;

int main(){

int n,m;
    cin>>n>>m;
    int array[n][m];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>array[n][m];
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout<<array[n][m]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
