#include <bits/stdc++.h>
using namespace std;

int main(){

int arr[]={56,6,94,3,449,34,66,6};

for(int i=0; i<7 ; i++){  
    for(int j=i+1; j<8; j++){
        if(arr[i]>arr[j]){
            int t;
            t=arr[j];
            arr[j]=arr[i];
            arr[i]=t;
        }
    }
}
for(int i=0; i<8; i++){
    cout<<arr[i]<<endl;
}

return 0;
}