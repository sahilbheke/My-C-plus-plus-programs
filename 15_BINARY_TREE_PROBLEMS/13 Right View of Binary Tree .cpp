// Should return  right view of tree

// Sahil's code
class Solution
{
public:
    void solve(Node *root, vector<int> &ans, int level)
    {

        // Base case.
        if (root == NULL)
            return;

        // new level
        if (level == ans.size())
            ans.push_back(root->data);

        solve(root->right, ans, level + 1);
        solve(root->left, ans, level + 1);
    }
    // Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
        vector<int> ans;
        solve(root, ans, 0);
        return ans;
    }
};

// Link of these Problem -> https://practice.geeksforgeeks.org/problems/right-view-of-binary-tree/1/
