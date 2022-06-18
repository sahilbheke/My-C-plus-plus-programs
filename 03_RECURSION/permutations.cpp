#include <bits/stdc++.h>
using namespace std;

// void swap(stirng s,int l,int r){
//     int temp=s[l];
//     s[l]=s[r];
//     s[r]=temp;
//     return;
// }

void permutation(string s,int l,int r)
{
    if(l==r){
        cout<<s<<endl;
        return; 
    }
    for(int i=l; i<=r; i++){
        swap(s[l],s[i]);
        permutation(s,l+1,r);
        swap(s[l],s[i]);
    }
    return;
}

int main(){
    
    string s="abc";
    permutation(s,0,2);

return 0;
}