// SAHIL'S CODE
// OPTIMAL SOLUTION
class Solution
{
    pair<bool, int> isBalancedFast(Node *root)
    {
        // Base case
        if (root == NULL)
        {
            pair<bool, int> p = make_pair(true, 0);
            return p;
        }

        // Recursive call for left node
        pair<bool, int> left = isBalancedFast(root->left);

        // Recursive call for right node
        pair<bool, int> right = isBalancedFast(root->right);

        // Checking given condition
        bool diff = abs(left.second - right.second) <= 1;

        pair<bool, int> ans;
        ans.second = max(left.second, right.second) + 1;

        // Checking balanced tree
        if (left.first && right.first && diff)
            ans.first = true;

        else
            ans.first = false;

        return ans;
    }

public:
    // Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
        // Base case
        if (root == NULL)
            return true;

        return isBalancedFast(root).first;
    }
};

// Link of these problem -> https://practice.geeksforgeeks.org/problems/check-for-balanced-tree/1

// brute force approach

/*************************************************************
class Solution{
    int height(Node* root){
        
        // Base tree
        if(root==NULL)
            return 0;
        
        // Calling for left node
        int left = height(root->left);
        
        // Calling for right node
        int right = height(root->right);
        
        // Storing height of current node
        int ans = max(left,right)+1;
        
        return ans;
        
    }
    
    public:
    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
        // Base case
        if(root == NULL)
            return true;
            
        // Recursive call for left node
        bool left = isBalanced(root->left);
        
        // Recursive call for right node
        bool right = isBalanced(root->right);
        
        // Checking given condition
        bool diff = abs(height(root->left) - height(root->right)) <= 1;
        
        // Checking balanced tree
        if( left && right && diff )
            return true;
        
        else 
            return false;
    }
};

/**********************************************************