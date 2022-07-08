/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

// Sahil's code
vector<int> diagonal(Node *root)
{
    // to store required result.
    vector<int> ans;

    // base case
    if(root == NULL)
        return ans;
    
    // to store nodes
    queue<Node*> q;
    q.push(root);
    
    while(!q.empty()){
        
        // current node.
        Node* currnode = q.front();
        q.pop();

        while(currnode){
            //if current ka left is there then push to queue.
            if(currnode->left) q.push(currnode->left);
            // storing root.
            ans.push_back(currnode->data);
            // moving to right of current node
            currnode= currnode->right;
        }
        
    }
    return ans;
}
// Link of these Problem -> https://practice.geeksforgeeks.org/problems/diagonal-traversal-of-binary-tree/1/#



/***********************************************************
// Wrong code need to fix
vector<int> diagonal(Node *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;

    map<int, vector<int>> maptrack;
    queue<pair<Node *, int>> q;
    q.push(make_pair(root, 0));

    while (!q.empty())
    {
        pair<Node *, int> temp = q.front();
        Node *currnode = temp.first;
        q.pop();
        int hz = temp.second;
        maptrack[hz].push_back(currnode->data);

        if (currnode->right)
            q.push(make_pair(currnode->right, hz));

        if (currnode->left)
            q.push(make_pair(currnode->left, hz + 1));
    }
    for (auto i : maptrack)
    {
        for (auto j : i.second)
        {
            ans.push_back(j);
        }
    }
    return ans;
}
***********************************************************/

