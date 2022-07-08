// Sahil's Solution
class Solution
{
public:
    // Function to find the vertical order traversal of Binary Tree.
    vector<int>
    verticalOrder(Node *root)
    {
        // map<hz no,pair<level,vector<storing all nodes of current level>>>.
        map<int, map<int, vector<int>>> nodes;

        // queue<pair<node*,<pair<hz no,level >>>
        queue<pair<Node *, pair<int, int>>> q;

        // storing required ans.
        vector<int> ans;

        // base case.
        if (root == NULL)
            return ans;

        // initially at root node.
        q.push(make_pair(root, make_pair(0, 0)));

        // iterating through every node.
        while (!q.empty())
        {

            // creating pair of node and pair of horizontal and lvl.
            pair<Node *, pair<int, int>> temp = q.front();
            q.pop();

            // getting current node.
            Node *currnode = temp.first;

            // getting horizontal position.
            int hz = temp.second.first;

            // getting level of node.
            int lvl = temp.second.second;

            // creating maping corrospond to that node.
            nodes[hz][lvl].push_back(currnode->data);

            if (currnode->left)
                q.push(make_pair(currnode->left, make_pair(hz - 1, lvl + 1)));

            if (currnode->right)
                q.push(make_pair(currnode->right, make_pair(hz + 1, lvl + 1)));
        }
        for (auto i : nodes)
        {
            for (auto j : i.second)
            {
                for (auto k : j.second)
                {
                    ans.push_back(k);
                }
            }
        }
        return ans;
    }
};

// Link of this problem -> https://practice.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/1

/***************************************************************

// Author's Solution 

class Solution
{
    public:
    //Function to find the vertical order traversal of Binary Tree.
    vector <int> verticalOrder(Node *root)
    {
        vector <int> res;
        //creating a map to store nodes at a particular horizontal distance.
        map<int,vector<int>>mp;
        
        //creating empty queue for level order traversal.
        queue<pair<Node*,int>>q;
        q.push({root,0});
        
        while(!q.empty())
        {
            pair<Node*,int> temp=q.front();
            Node* temp_root=temp.first;
            int distance=temp.second;
            mp[distance].push_back(temp_root->data);
            q.pop();
            
            //if left child of temp_root exists, pushing it in
            //the queue with the horizontal distance.
            if(temp_root->left)
            {
                q.push({temp_root->left,distance-1});
            }
            //if right child of temp_root exists, pushing it in
            //the queue with the horizontal distance.
            if(temp_root->right)
            {
                q.push({temp_root->right,distance+1});
            }
        }
        
        //traversing the map and storing the nodes in list 
        //at every horizontal distance.
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            vector<int> ans=it->second;
            
            for(auto x:ans)
                res.push_back (x);
        }
        //returning the output list.
        return res;
        
    }

};

********************************************************/