#include <stack>
/*
    Time Complexity: O(N)
    Space Complexity: O(N)

    Where N denotes the number of elements in the array.
*/

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    // MY CODE

    // Defining the stack and pushing -1 to it.
    stack<int> s;
    s.push(-1);

    // Defining the vector to store next smaller elements for the array.
    vector<int> ans(n);

    // Iterating through all the array elements from backwards.
    for (int i = n - 1; i >= 0; i--)
    {

        // Removing all the elements greater than or equal to current element from the stack.
        while (s.top() >= arr[i])
        {
            s.pop();
        }

        // Setting the next smaller element as the element at top of stack.
        ans[i] = s.top();

        // Pushing the current element into the stack.
        s.push(arr[i]);
    }

    // Returning the final vector after all the iterations.
    return ans;
}

// Link of Problem -> https://bit.ly/34GjYL4

// Brute Force Approach (bad TC)

/*
    Time Complexity: O(N ^ 2)
    Space Complexity: O(1)

    Where N denotes the number of elements in the array.
*/

// vector<int> nextSmallerElement(vector<int> & arr, int n)
// {
//     // Defining the vector to store next smaller elements for the array.
//     vector<int> ans(n);

//     // Iterating through all the array elements and finding next smaller element for each element.
//     for (int i = 0; i < n; i++)
//     {
//         // Initializing the next smaller element as -1.
//         ans[i] = -1;

//         // Moving to the right of the element.
//         for (int j = i + 1; j < n; j++)
//         {
//             // Checking for the next smaller element.
//             if (arr[i] > arr[j])
//             {
//                 ans[i] = arr[j];
//                 break;
//             }
//         }

//     }

//     // Returning the final vector after all the iterations.
//     return ans;
// }