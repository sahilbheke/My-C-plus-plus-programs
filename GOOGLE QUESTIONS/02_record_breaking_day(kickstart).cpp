#include <bits/stdc++.h>
using namespace std;

int main(){

int n;        //pro coder
cin>>n;

int a[n+1];
a[n+1] = -1;

if(n==1){
    cout<<"1"<<endl;
}

for(int i=0; i<n; i++)
    cin>>a[i];

int mx = -1;
int ans = 0;

for(int i=0; i<n; i++){
    if(a[i]>mx && a[i]>a[i+1]){
         ans++;
    }
    mx=max(mx,a[i]);
}
cout<<ans;


// int n;            //my code
// cin>>n;

// int a[n];
// for(int i=0; i<n; i++)
//     cin>>a[i];

// int count = 0;
// for(int i=0; i<n; i++){
//     if(i==0){
//         if(a[i]>a[i+1])
//             count++;
//     }
//     else if (a[i]>a[i-1] && a[i]>a[i+1]){
//         count++;
//     }
//     else if(i==n-1){
//         if(a[n-1]>a[n-2])
//         count++;
//     }
// }
// cout<<count;
return 0;
}