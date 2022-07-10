// Sahil's code

class Solution
{
public:
    int findpos(int in[], int element, int n)
    {
        for (int i = 0; i < n; i++)
        {
            if (in[i] == element)
                return i;
        }
        return -1;
    }
    Node *solve(int in[], int pre[], int &preorderIndex, int inorderStart, int inorderEnd, int n)
    {

        // Base case
        if (preorderIndex >= n || inorderStart > inorderEnd)
            return NULL;

        // converting preorder element to Node.
        // using preorderIndex and then preorderIndex will incriment
        int element = pre[preorderIndex++];
        Node *NewNode = new Node(element);

        // finding postion of element in inorder.
        int position = findpos(in, element, n);

        // Recursive calls for left and right
        NewNode->left = solve(in, pre, preorderIndex, inorderStart, position - 1, n);
        NewNode->right = solve(in, pre, preorderIndex, position + 1, inorderEnd, n);

        return NewNode;
    }
    Node *buildTree(int in[], int pre[], int n)
    {
        int preorderIndex = 0;

        Node *ans = solve(in, pre, preorderIndex, 0, n - 1, n);

        return ans;
    }
};

// Link of these problem -> https://practice.geeksforgeeks.org/problems/construct-tree-1/1/

/*******************************************************

// we can also find position of element in inorder using maping.

class Solution{
    public:
    void createMapping(int in[], map<int,int> &nodeToIndex, int n){
        for(int i = 0; i<n; i++){
            nodeToIndex[in[i]] = i;
        }

    }
    Node* solve(int in[],int pre[],int &preorderIndex,int inorderStart,
    int inorderEnd, int n, map<int,int>&nodeToIndex){

        // Base case
        if(preorderIndex>=n || inorderStart>inorderEnd)
            return NULL;

        // converting preorder element to Node.
        // using preorderIndex and then preorderIndex will incriment
        int element = pre[preorderIndex++];
        Node* NewNode = new Node(element);

        // finding postion of element in inorder.
        int position = nodeToIndex[element];

        // Recursive calls for left and right
        NewNode->left = solve(in,pre,preorderIndex, inorderStart, position-1, n, nodeToIndex);
        NewNode->right = solve(in,pre,preorderIndex, position+1, inorderEnd, n, nodeToIndex);

        return NewNode;
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        int preorderIndex = 0;

        map<int,int> nodeToIndex;
        //create node to index map.
        createMapping(in, nodeToIndex, n);

        Node* ans = solve(in, pre, preorderIndex, 0, n-1, n, nodeToIndex);

        return ans;
    }
};

********************************************************/