// Sahil's code
class Solution
{
public:
    void traversalLeft(Node *root, vector<int> &ans)
    {

        // Base case.
        if (root == NULL || (root->left == NULL && root->right == NULL))
            return;

        // Storing Left node data.
        ans.push_back(root->data);

        if (root->left)
            traversalLeft(root->left, ans);

        else
            traversalLeft(root->right, ans);
    }

    void traversalLeaf(Node *root, vector<int> &ans)
    {

        if (root == NULL)
            return;

        if (root->left == NULL && root->right == NULL)
        {
            ans.push_back(root->data);
            return;
        }

        traversalLeaf(root->left, ans);
        traversalLeaf(root->right, ans);
    }

    void traversalRight(Node *root, vector<int> &ans)
    {

        // Base case.
        if (root == NULL || (root->left == NULL && root->right == NULL))
            return;

        if (root->right)
            traversalRight(root->right, ans);

        else
            traversalRight(root->left, ans);

        ans.push_back(root->data);
    }
    vector<int> boundary(Node *root)
    {
        vector<int> ans;
        if (root == NULL)
            return ans;

        ans.push_back(root->data);

        // Traversal for left boundary node.
        traversalLeft(root->left, ans);

        // Traversal for left leaf node.
        traversalLeaf(root->left, ans);
        // Traversal for right leaf node.
        traversalLeaf(root->right, ans);

        // Traversal for right boundary node.
        traversalRight(root->right, ans);

        return ans;
    }
};

// Link of this problem -> https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1/#