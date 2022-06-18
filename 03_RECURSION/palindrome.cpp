#include <bits/stdc++.h>
using namespace std;

bool palindrome(string s, int l, int r)
{
    if (l >= r)
        return true;

    if (s[l] != s[r])
        return false;
    return palindrome(s, l + 1, r - 1);
}

int main()
{

    string s = "nitin";
    cout << palindrome(s, 0, 4);

    return 0;
}
