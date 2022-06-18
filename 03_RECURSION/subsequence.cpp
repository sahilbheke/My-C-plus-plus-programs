#include <bits/stdc++.h>
using namespace std;

void subsequence(string s, int i, string cur)
{
    if (i == s.length())
    {
        cout << cur << endl;
        return;
    }
    subsequence(s, i + 1, cur);
    subsequence(s, i + 1, cur + s[i]);
}

int main()
{

    string s = "abc";
    subsequence(s, 0, " ");
    return 0;
}