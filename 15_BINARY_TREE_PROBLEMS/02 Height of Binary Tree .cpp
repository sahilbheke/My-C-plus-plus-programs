//SAHIL's CODE
class Solution{
    public:
    //Function to find the height of a binary tree.
    int height(struct Node* node){
        if(node==NULL)
        return 0;
        
        int left= height(node->left);
        int right = height(node->right);
        
        int ans = max(left,right)+1;
        return ans;
        
    }
};

// Link of this problem -> https://practice.geeksforgeeks.org/problems/height-of-binary-tree/1#


/*************************************

// Author's Solution

int height(struct Node* node)
{
    //if node is null, we return 0.
    if (node==NULL)
        return 0;

    //else we call the recursive function, height for left and right 
    //subtree and choose their maximum. we also add 1 to the result
    //which indicates height of root of the tree.
    else
    {
        int h_left= height(node->left);
        int h_right= height(node->right);
        return 1 + (h_left>h_right?h_left:h_right);
    }
}   
************************************/