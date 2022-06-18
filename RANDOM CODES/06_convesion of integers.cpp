#include <bits/stdc++.h>
using namespace std;

int binarytodecimal(int n){
    int ans=0;
    int  a=1;
    while(n>0){
        int b=n%10;
        b*=a;
        ans+=b;
        a*=2;
        n/=10;
    }
    return ans;
}
int octaltodecimal(int n){
    int ans=0;
    int  a=1;
    while(n>0){
        int b=n%10;
        b*=a;
        ans+=b;
        a*=8;
        n/=10;
    }
    return ans;
}
int hexadecimaltodecimal(string n){
    int ans=0;
    int  x=1;
    int s=n.size();
    for(int i=s-1; i>=0; i--){
        if(n[i]>='0' && n[i]<='9'){
            ans += x*(n[i]-'0');
        }
        else if(n[i]>='A' && n[i]<='F'){
           ans += x*(n[i]-'A'+10); 
        }
        x*=16; 
    }
 
    return ans;
}
int decimaltobinary(int n){    //Function   
    int x=1;
    cout<<"x = "<<x<<endl;
    int ans=0;
    while(x<=n)
        x*=2;
        cout<<"x = "<<x<<endl;
    x/=2;
    cout<<"x = "<<x<<endl;

    while(x>0){
        int lastdigit = n/x;
        n -= lastdigit*x;
        cout<<"n = "<<n<<endl;
        x/=2;
        ans = ans*10 + lastdigit;
        cout<<"ans = "<<ans<<endl;
    }
    return ans;
}
int decimaltooctal(int n){    //Function
    int x=1;
    int ans=0;
    while(x<=n)
        x*=8;
        x/=8;

    while(x>0){
        int lastdigit = n/x;
        n -= lastdigit*x;
        x/=8;
        ans = ans*10 + lastdigit;
    }
    return ans;
}
string decimalothexadecimal(int n){
    

}

int reverse(int n){
    int ans=0;
    int lastdigit=0;
    while (n>0){
        lastdigit = n%10;
        ans=ans*10+lastdigit;
        n /=10;
    }
    return ans;
}

int addbinary(int a,int b){
    int ans = 0;
    int prevcarry = 0;
    while(a>0 && b>0){
        if (a%2 == 0 && b%2 == 0){
            ans = ans*10 + prevcarry;
            prevcarry = 0; 
        }
        else if ((a%2 == 0 && b%2 == 1) || (a%2 == 1 && b%2 == 0)){
            if(prevcarry == 1){
            ans = ans*10 + 0;
            prevcarry = 1;
            }
            else {
                ans = ans*10 + 1;
                prevcarry = 0;
            }
        }
        else{
            ans = ans*10 + prevcarry;
            prevcarry = 1;
        }
        a /= 10 ;
        b /= 10 ;
    }
    while (a>0){
        if (prevcarry == 1){
            if(a%2 == 1){
                ans = ans*10 + 1;
                prevcarry = 1;
            }
            else{
                ans = ans*10 + 1;
                prevcarry = 0;
            }
        }
        else{
            ans = ans*10 + a%2;
            // prevcarry = 0;
        }
        a /= 10;
    }
    while (b>0){
        if (prevcarry == 1){
            if(b%2 == 1){
                ans = ans*10 + 1;
                prevcarry = 1;
            }
            else{
                ans = ans*10 + 1;
                prevcarry = 0;
            }
        }
        else{
            ans = ans*10 + b%2;
            // prevcarry = 0;
        }
        b /= 10;
    }
    if(prevcarry==1)
    ans = ans*10 + 1;
    ans = reverse(ans);
    return ans;
}
    
int main(){

int a,b;
cin>>a>>b;

cout<<addbinary(a,b)<<endl;         //Function call 


return 0;
}