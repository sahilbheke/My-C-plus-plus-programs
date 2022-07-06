class Solution {
  public:
    // Function to return the diameter of a Binary Tree.
    pair<int,int> diametercount(Node* root) {
        if(root==NULL){
            pair<int,int> p = make_pair(0,0);
            return p;
        }
        
        pair<int,int>left=diametercount(root->left);
        pair<int,int>right= diametercount(root->right);
        
        int obj1 = left.first;
        int obj2 = right.first;
        int obj3 = left.second + right.second + 1;
        
        pair<int,int>ans;
        ans.first = max(obj1,max(obj2,obj3));
        ans.second = max(left.first,right.second)+1;
        return ans;
        
    }
    
    int diameter(Node* root) {
        return diametercount(root).first;
    }
};

//Link of this code -> https://practice.geeksforgeeks.org/problems/diameter-of-binary-tree/1#


/********************************************

// Author's solution


class Solution {
  public:
    // Function to find the diameter of a Binary Tree.
    int go(Node* n, int* dia) {
        // if node becomes null, we return 0.
        if (!n) return 0;

        // calling the go function recursively for the left and
        // right subtrees to find their heights.
        int l = go(n->left, dia);
        int r = go(n->right, dia);

        // storing the maximum possible value of l+r+1 in diameter.
        if (l + r + 1 > *dia) *dia = l + r + 1;

        // returning height of subtree.
        return 1 + max(l, r);
    }

  public:
    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) {
        int dia = 0;
        // calling the function to find the result.
        go(root, &dia);
        // returning the result.
        return dia;
    }
};
 
********************************************/