// Sahil's code
class Solution
{
public:
    // Function to store the zig zag order traversal of tree in a list.
    vector<int> zigZagTraversal(Node *root)
    {

        // TO store main result.
        vector<int> result;

        // Base case.
        if (root == NULL)
            return result;

        queue<Node *> q;
        q.push(root);

        bool leftToRight = true;

        while (!q.empty())
        {

            int size = q.size();

            // Temporary vector to store ans.
            vector<int> ans(size);

            // level process.
            for (int i = 0; i < size; i++)
            {

                Node *frontNode = q.front();
                q.pop();

                // Normal insert or reverse insert.
                int index = leftToRight ? i : size - i - 1;
                ans[index] = frontNode->data;

                // inserting left node in queue.
                if (frontNode->left)
                    q.push(frontNode->left);

                // inserting right node in queue.
                if (frontNode->right)
                    q.push(frontNode->right);
            }

            // Changing direction.
            leftToRight = !leftToRight;

            // Pushing ans to result.
            for (auto i : ans)
            {

                result.push_back(i);
            }
        }
        return result;
    }
};

// Link of this Problem -> https://practice.geeksforgeeks.org/problems/zigzag-tree-traversal/1/