// Sahil's code
class Solution
{
public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        // Vector for storing required result.
        vector<int> ans;

        // Base case.
        if (root == NULL)
            return ans;

        // map to store horizontal no and root
        map<int, int> topmap;

        // queue to store node and hz.
        queue<pair<Node *, int>> q;

        // initially.
        q.push(make_pair(root, 0));

        // iterating trough every node.
        while (!q.empty())
        {

            // to store node and hz
            pair<Node *, int> temp = q.front();
            q.pop();

            // crrent node
            Node *currNode = temp.first;
            // current hz
            int hz = temp.second;

            // if map does not exist for current hz then store data
            if (topmap.find(hz) == topmap.end())
                topmap[hz] = currNode->data;

            // moving to left subchild.
            if (currNode->left)
                q.push(make_pair(currNode->left, hz - 1));

            // moving to right subchild
            if (currNode->right)
                q.push(make_pair(currNode->right, hz + 1));
        }

        // storing ans.
        for (auto i : topmap)
        {
            ans.push_back(i.second);
        }
        return ans;
    }
};

// Link of these problem -> https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1/
