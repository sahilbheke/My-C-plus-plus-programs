// Should return true if tree is Sum Tree, else false
// Sahil's code
class Solution
{
public:
    pair<bool, int> check(Node *root)
    {

        // Base case 1
        if (root == NULL)
        {
            pair<bool, int> p = make_pair(true, 0);
            return p;
        }

        // Base case 2
        if (root->left == NULL && root->right == NULL)
        {
            pair<bool, int> p = make_pair(true, root->data);
            return p;
        }

        // Recursive call for left node.
        pair<bool, int> left = check(root->left);

        // Recursive call for right node.
        pair<bool, int> right = check(root->right);

        // Checking given condition.
        bool cond = left.second + right.second == root->data;

        // Making pair to store final ans.
        pair<bool, int> ans;

        // If all given condition are true
        if (left.first && right.first && cond)
        {
            ans.first = true;
            ans.second = root->data + left.second + right.second;
        }
        else
            ans.first = false;

        return ans;
    }

    bool isSumTree(Node *root)
    {
        // calling check.first function which store bool data type.
        return check(root).first;
    }
};

// Link of this problem -> https://practice.geeksforgeeks.org/problems/sum-tree/1#