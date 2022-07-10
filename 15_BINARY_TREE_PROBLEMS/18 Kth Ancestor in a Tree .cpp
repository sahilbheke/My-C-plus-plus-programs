// SAHIL'S CODE
Node* solve(Node *root, int &k, int node)
    {

        // base case.
        if (root == NULL )
            return NULL;
            
        if(root->data == node){
            return root;
        }

        

        Node* left = solve(root->left, k, node);
        Node* right = solve(root->right, k, node);
        
        if(left!=NULL && right ==NULL){
            k--;
            if(k<=0){
                k=INT_MAX;
                return root;
            }
            return left;
        }
        
        if(left==NULL && right!=NULL){
            k--;
            if(k<=0){
                k=INT_MAX;
                return root;
            }
            return right;
        }
        return NULL;
        
    }
    
int kthAncestor(Node *root, int k, int node)
{
    Node* result = solve(root, k, node);
    
    if(result==NULL || result->data == node) return -1;

    else return result->data;
    
}

// lINK OF THESE PROBLEM -> https://practice.geeksforgeeks.org/problems/kth-ancestor-in-a-tree/1/


// VECTOR APPROACH

/*******************************************************

void solve(Node *root, int k, int node, int &ancestor, vector<int> rootnodes)
    {

        // base case.
        if (root == NULL )
            return;

        if(root->data == node){

            int size=rootnodes.size();

            if(size>=k){

            int indexOfAncestor = size-k;

            ancestor = rootnodes[indexOfAncestor];

            return;
            }
        }

        rootnodes.push_back(root->data);

        solve(root->left, k, node, ancestor,rootnodes);
        solve(root->right, k, node, ancestor,rootnodes);

        rootnodes.pop_back();

    }

int kthAncestor(Node *root, int k, int node)
{
    int ancestor = -1;

    vector<int> rootnodes;

    solve(root, k, node, ancestor, rootnodes);

    return ancestor;

}

*****************************************************/