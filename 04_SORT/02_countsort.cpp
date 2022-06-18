#include <bits/stdc++.h>
using namespace std;

void countsort(int arr[],int n){    //1,3,2,3,4,1,6,4,3
    int k=arr[0];
    for(int i=0; i<n; i++){
        k=max(k,arr[i]);        // k=6
    }
    int count[k+1]={0};   //count[9]={0}
    for(int i=0; i<n; i++){
        count[arr[i]]++;        //count[arr[0]] = count[1]++ = 1 ---->{2,1,3,2,0,1} 
    }
    for(int i=1; i<=k; i++){
        count[i]+=count[i-1];
    }
    int output[n];
    for(int i=n-1; i>=0; i--){
        output[--count[arr[i]]]=arr[i];
    }
    for(int i=0; i<n; i++){
        arr[i]=output[i];
    }
}

int main()
{
    int arr[]={1,3,2,3,4,1,6,4,3};
    countsort(arr,9);
    for(int i=0; i<9; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}