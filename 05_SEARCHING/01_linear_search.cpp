#include <bits/stdc++.h>
using namespace std;

int linearsearch(int arr[], int key, int n){

    for(int i=0; i<n; i++){
    if(key==arr[i]){
    return i;
    }
    }
    return -1;
}

int main(){

int n;
cin>>n;

int arr[n];
for(int i=0; i<n; i++)
    cin>>arr[i];

int key;
cin>>key;

cout<<linearsearch(arr,key,n)<<endl;

return 0;
}