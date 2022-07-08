//Sahil's code

class Solution
{
    public:
    //Function to check if two trees are identical.
    bool isIdentical(Node *r1, Node *r2)
    {
        // Base Case 1
        if(r1 == NULL && r2 == NULL)
            return true;
          
        // Base Case 2 
        if(r2 == NULL && r1 != NULL)
            return false;
        
        // Base Case 3
        if(r2 != NULL && r1 == NULL)
            return false;
            
        // Recursive call for left node
        bool left = isIdentical(r1->left,r2->left);
        
        // Recursive call for right node
        bool right = isIdentical(r1->right,r2->right);
        
        // Checking for given condition
        bool value = r1->data == r2-> data;
        
        // If required condtion is true return true else false
        if(left && right && value)
            return true;
        
        else 
            return false;
    }
};

// Link of this problem -> https://practice.geeksforgeeks.org/problems/determine-if-two-trees-are-identical/1