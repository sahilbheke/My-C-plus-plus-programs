// Sahil's code

int findpos(int in[], int element, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (in[i] == element)
            return i;
    }
    return -1;
}
Node *solve(int in[], int post[], int &postorderIndex, int inorderStart, int inorderEnd, int n)
{

    // Base case
    if (postorderIndex < 0 || inorderStart > inorderEnd)
        return NULL;

    // converting preorder element to Node.
    // using preorderIndex and then preorderIndex will incriment
    int element = post[postorderIndex--];
    Node *NewNode = new Node(element);

    // finding postion of element in inorder.
    int position = findpos(in, element, n);

    // Recursive calls for left and right
    /*
    in postorder we have to put right call first
    as we move from last index we incounter right elements first
    */
    NewNode->right = solve(in, post, postorderIndex, position + 1, inorderEnd, n);
    NewNode->left = solve(in, post, postorderIndex, inorderStart, position - 1, n);

    return NewNode;
}

// Function to return a tree created from postorder and inoreder traversals.
Node *buildTree(int in[], int post[], int n)
{
    int postorderIndex = n - 1;

    Node *ans = solve(in, post, postorderIndex, 0, n - 1, n);

    return ans;
}

// Link of the problem -> https://practice.geeksforgeeks.org/problems/tree-from-postorder-and-inorder/1/


/*******************************************************

// we can also find position of element in inorder using maping.

void CreateMapping(int in[],map<int,int> &NodeToIndex,int n)
    {
        for (int i = 0; i < n; i++)
        {
            NodeToIndex[in[i]]=i;
        }
        
    }
    Node *solve(int in[], int post[], int &postorderIndex, int inorderStart,
    int inorderEnd, map<int,int>NodeToIndex, int n)
    {

        // Base case
        if (postorderIndex < 0 || inorderStart > inorderEnd)
            return NULL;

        // converting preorder element to Node.
        // using preorderIndex and then preorderIndex will incriment
        int element = post[postorderIndex--];
        Node *NewNode = new Node(element);

        // finding postion of element in inorder.
        int position = NodeToIndex[elemet];

        // Recursive calls for left and right
        
        //in postorder we have to put right call first 
        //as we move from last index we incounter right elements first 
        NewNode->right = solve(in, post, postorderIndex, position + 1, inorderEnd, NodeToIndex, n);
        NewNode->left = solve(in, post, postorderIndex, inorderStart, position -1, NodeToIndex, n);
        
        return NewNode;
    }

//Function to return a tree created from postorder and inoreder traversals.
Node *buildTree(int in[], int post[], int n) {
    int postorderIndex = n-1;
    map<int,int> NodeToIndex;
    CreateMapping(in,NodeToIndex,n);
    Node *ans = solve(in, post, postorderIndex, 0, n - 1, n);

    return ans;
}

******************************************************/