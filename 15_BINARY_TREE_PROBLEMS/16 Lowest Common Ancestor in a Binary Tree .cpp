/* A binary tree node
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};
*/

// Sahil's code

class Solution
{
public:
    // Function to return the lowest common ancestor in a Binary Tree.
    Node *lca(Node *root, int n1, int n2)
    {
        // base case.
        if (root == NULL)
            return NULL;

        // required ans.
        if (root->data == n1 || root->data == n2)
            return root;

        Node *left = lca(root->left, n1, n2);
        Node *right = lca(root->right, n1, n2);

        if (left != NULL && right != NULL)
            return root;

        else if (left != NULL && right == NULL)
            return left;

        else if (left == NULL && right != NULL)
            return right;

        else
            return NULL;
    }
};

// Link of the problem -> https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-binary-tree/1