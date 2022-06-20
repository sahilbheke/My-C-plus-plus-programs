class Solution
{
private:
    vector<int> NextSmallerElement(int *arr, int n)
    {

        // Defining the stack and pushing -1 to it.
        stack<int> s;
        s.push(-1);

        // Defining the vector to store next smaller elements for the array.
        vector<int> ans(n);

        // Iterating through all the array elements from backwards.
        for (int i = n - 1; i >= 0; i--)
        {

            // Removing all the elements greater than or equal to current element from the stack.
            while (s.top() != -1 && arr[s.top()] >= arr[i])
            {
                s.pop();
            }

            // Setting the next smaller element as the element at top of stack.
            ans[i] = s.top();

            // Pushing the current element index into the stack.
            s.push(i);
        }

        // Returning the final vector after all the iterations.
        return ans;
    }

    vector<int> PrevSmallerElement(int *arr, int n)
    {

        // Defining the stack and pushing -1 to it.
        stack<int> s;
        s.push(-1);

        // Defining the vector to store next smaller elements for the array.
        vector<int> ans(n);

        // Iterating through all the array elements from backwards.
        for (int i = 0; i < n; i++)
        {

            // Removing all the elements greater than or equal to current element from the stack.
            while (s.top() != -1 && arr[s.top()] >= arr[i])
            {
                s.pop();
            }

            // Setting the next smaller element as the element at top of stack.
            ans[i] = s.top();

            // Pushing the current element index into the stack.
            s.push(i);
        }

        // Returning the final vector after all the iterations.
        return ans;
    }

    int largestRectangleArea(int *height, int n)
    {

        // int n = height.size();

        vector<int> next(n);
        next = NextSmallerElement(height, n);

        vector<int> prev(n);
        prev = PrevSmallerElement(height, n);

        int area = INT_MIN;

        for (int i = 0; i < n; i++)
        {

            int l = height[i];

            if (next[i] == -1)
            {
                next[i] = n;
            }

            int b = next[i] - prev[i] - 1;

            int newArea = l * b;
            area = max(area, newArea);
        }
        return area;
    }

public:
    int maxArea(int M[MAX][MAX], int n, int m)
    {

        // complete area for first rwo
        int area = largestRectangleArea(M[0], m);

        // for remaining rows
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {

                // row update by adding previous row's value
                if (M[i][j] != 0)
                    M[i][j] = M[i][j] + M[i - 1][j];
                else
                    M[i][j] = 0;
            }

            // entire row is updated now
            area = max(area, largestRectangleArea(M[i], m));
        }
        return area;
    }
};

// Link of the problem -> https://practice.geeksforgeeks.org/problems/max-rectangle/1/

// Alternate solution by AUTHOR

class Solution
{
public:
    int mhist(int row[], int m1)
    {

        stack<int> result;

        int top_val;

        int max_area = 0;

        int area = 0;
        int i = 0;
        for (i = 0; i < m1;)
        {

            if (result.empty() || row[result.top()] <= row[i])
                result.push(i++);

            else
            {
                top_val = row[result.top()];
                result.pop();
                area = top_val * i;

                if (!result.empty())
                    area = top_val * (i - result.top() - 1);
                max_area = max(area, max_area);
            }
        }

        while (!result.empty())
        {
            top_val = row[result.top()];
            result.pop();
            area = top_val * i;
            if (!result.empty())
                area = top_val * (i - result.top() - 1);

            max_area = max(area, max_area);
        }
        return max_area;
    }

    int kewl(int M[MAX][MAX], int n, int m)
    {
        int res = mhist(M[0], m);
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {

                if (M[i][j])
                    M[i][j] += M[i - 1][j];
            }
            res = max(res, mhist(M[i], m));
        }
        return res;
    }
    int maxArea(int M[MAX][MAX], int n, int m)
    {
        return kewl(M, n, m);
    }
};