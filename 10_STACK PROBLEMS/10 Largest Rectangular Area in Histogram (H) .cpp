
class Solution
{

    // my code

private:
    vector<int> NextSmallerElement(vector<int> arr, int n)
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

    vector<int> PrevSmallerElement(vector<int> arr, int n)
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

public:
    int largestRectangleArea(vector<int> &height)
    {

        int n = height.size();

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
};

// Link OF Problem ->

// Alternate solution on leet code by other coder with best runtime

class Solution
{
public:
    int largestRectangleArea(vector<int> &height)
    {
        ios::sync_with_stdio(0);
        cout.tie(0);
        cin.tie(0);
        int ret = 0;
        height.push_back(0);
        vector<int> index;

        for (int i = 0; i < height.size(); i++)
        {
            while (index.size() > 0 && height[index.back()] >= height[i])
            {
                int h = height[index.back()];
                index.pop_back();

                int sidx = index.size() > 0 ? index.back() : -1;
                if (h * (i - sidx - 1) > ret)
                    ret = h * (i - sidx - 1);
            }
            index.push_back(i);
        }

        return ret;
    }
};
