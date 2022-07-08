/*
structure of the node of the binary tree is as
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/

// Sahil's code.
class Solution
{
public:
    void solve(Node *root, int len, int &maxlen, int sum, int &maxsum)
    {

        // base case.
        if (root == NULL)
        {
            if (len > maxlen)
            {
                maxlen = len;
                maxsum = sum;
            }
            else if (len == maxlen)
            {
                maxsum = max(sum, maxsum);
            }
            return;
        }

        // Adding roots
        sum += root->data;

        // Recursive call for left subroot.
        solve(root->left, len + 1, maxlen, sum, maxsum);

        // Recursive call for right subroot.
        solve(root->right, len + 1, maxlen, sum, maxsum);
    }

    int sumOfLongRootToLeafPath(Node *root)
    {
        // Initialization of lenght and sum.
        int len = 0;
        int maxlen = 0;

        int sum = 0;
        int maxsum = INT_MIN;

        solve(root, len, maxlen, sum, maxsum);
        return maxsum;
    }
};

// Link of these problem -> https://practice.geeksforgeeks.org/problems/sum-of-the-longest-bloodline-of-a-tree/1#