// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int>> &M, int n)
    {
        // Creating Stack
        stack<int> s;

        // Pushing All Elements In Stack
        for (int i = 0; i < n; i++)
            s.push(i);

        // Getting two elements of stack and comparing them
        while (s.size() > 1)
        {

            int a = s.top();
            s.pop();

            int b = s.top();
            s.pop();

            if (M[a][b])
                s.push(b);

            else
                s.push(a);
        }
        int ans = s.top();
        // now there is only one emelemt in stack
        // so verify it

        // row check
        int rowcount = 0;
        for (int i = 0; i < n; i++)
        {
            if (M[ans][i] == 0)
                rowcount++;
        }

        // all zeroes
        if (rowcount != n)
            return -1;

        // column check
        int colcount = 0;
        for (int i = 0; i < n; i++)
        {
            if (M[i][ans] == 1)
                colcount++;
        }

        if (colcount != n - 1)
            return -1;

        return ans;
    }
};

// Link of the Problem ->  https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1/

// Alternate code by author

class Solution
{
public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int>> &M, int n)
    {
        // initializing two pointers for two corners.
        int a = 0;
        int b = n - 1;

        // we keep moving till the a<b.
        while (a < b)
        {
            if (M[a][b])
                a++;
            else
                b--;
        }

        // checking if a is actually celebrity or not.
        for (int i = 0; i < n; i++)
        {

            // if any person doesn't know a or a knows any person, we return -1.
            if ((i != a) && (M[a][i] || !M[i][a]))
                return -1;
            //
        }

        // if we reach here a is celebrity so we retun a.
        return a;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> M(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> M[i][j];
            }
        }
        Solution ob;
        cout << ob.celebrity(M, n) << endl;
    }
}
// } Driver Code Ends
