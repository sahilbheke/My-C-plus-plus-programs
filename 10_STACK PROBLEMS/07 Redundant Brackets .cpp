#include <stack>
/*
    Time Complexity: O(|S|)
    Space Complexity: O(|S|)

    Where '|S|' is the length of the given string.
*/

bool findRedundantBrackets(string &s)
{ // my code
    // For keeping track of opening and closing brackets.
    stack<char> st;

    // Iterate through the string.
    for (int i = 0; i < s.length(); i++)
    {

        // Push the current character to the stack if it is an operator or an opening bracket.
        if (s[i] == '(' || s[i] == '*' || s[i] == '-' || s[i] == '+' || s[i] == '/')
            st.push(s[i]);

        else
        {

            // If the current character is a closing bracket.
            if (s[i] == ')')
            {

                // For checking if the current bracket is redundant or not.
                bool isredundant = true;

                // Keep popping from the stack till we reach an opening bracket.
                while (st.top() != '(')
                {
                    char top = st.top();

                    // If we find a operator then the current bracket is not redundant.
                    if (top == '*' || top == '-' || top == '+' || top == '/')
                    {
                        isredundant = false;
                    }
                    st.pop();
                }

                // Return true if we did not find any operator before finding the opening bracket.
                if (isredundant)
                    return isredundant;
                st.pop();
            }
        }
    }

    // If no bracket is redundant then return false.
    return false;
}

// Link of Problem -> https://bit.ly/3srTkOv