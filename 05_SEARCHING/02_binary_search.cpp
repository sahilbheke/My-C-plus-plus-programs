#include <bits/stdc++.h>
using namespace std;

int binarysearch(int n, int arr[], int key){
    int s=0;
    int e=n;
    while(e>s){
        int mid=(s+e)/2;
        if(arr[mid]==key)
        return mid;

        else if(arr[mid]>key){
            e=e-1;
        }
        else
        s=s+1;
    }
    return -1;
}

int main(){

int n;
cin>>n;
int arr[n];

for(int i=0; i<n; i++){
    cin>>arr[i];
}
int key;
cin>>key;
cout<<binarysearch(n,arr,key)<<endl;

return 0;
}