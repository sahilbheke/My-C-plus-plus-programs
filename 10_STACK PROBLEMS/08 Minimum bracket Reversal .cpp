#include <stack>
/*
    Time Complexity : O(|STR| * 2^|STR|)
    Space Complexity : O(|STR|)

    Where |STR| is the length of STR.
*/

int findMinimumCost(string str)
{

    // my code
    // If lenght is odd then it is impossible to make str valid.
    if (str.length() % 2 != 0)
    {
        return -1;
    }

    // To store invalid parts.
    stack<char> st;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '{')
            // Keep the invalid part in the stack.
            st.push(str[i]);
        else
        {
            if (!st.empty() && st.top() == '{')
            {
                // Remove the valid part in the stack.
                st.pop();
            }
            else
                // Keep the invalid part in the stack.
                st.push(str[i]);
        }
    }

    // Calculate the opening and closing brackets
    int a = 0, b = 0;
    while (!st.empty())
    {
        if (st.top() == '}')
            a++;
        else
            b++;
        st.pop();
    }
    int ans = (a + 1) / 2 + (b + 1) / 2;
    return ans;
}

// Link of Problem -> https://bit.ly/3GAYRr5