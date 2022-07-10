// Sahil's code

class Solution {
  public:
  Node *CreatingParentMapping(Node *root, map<Node*, Node*> &NodeToParent, int target)
{

    Node *res = NULL;

    queue<Node*> q;
    q.push(root);

    // Since top most root does not have parent node.
    NodeToParent[root] = NULL;

    while (!q.empty())
    {

        Node* front = q.front();
        q.pop();

        // if target found
        if (front->data == target)
            res = front;

        // if left sub tree exist then store parent node of left sub tree.
        if (front->left){
            NodeToParent[front->left] = front;
            q.push(front->left);
        }
        
        // if right subtree exist then store parent node of right sub tree.
        if (front->right){
            NodeToParent[front->right] = front;
            q.push(front->right);
        }
    }

    return res;
}

int burningTree(Node *root, map<Node*, Node*> &NodeToParent)
{

    // mapping for keeping track of visited nodes.
    map<Node*, bool> visited;

    queue<Node*> q;

    // Inserting root node
    q.push(root);
    // Marking true for root node.
    visited[root] = true;

    // to store time.
    int time = 0;

    while (!q.empty())
    {

        // flag to track changes in queue.
        bool flag = 0;

        // for every iteration of while loop size will change.
        int size = q.size();

        // Pushing left, right and parent node of front node 
        // to queue and also mark flag = true, if exist.
        for (int i = 0; i < size; i++)
        {

            Node *front = q.front();
            q.pop();
            
            /* if left connected node exist and not visited.
               then push right node to queue, flag = true and visited = true.
            */
            if (front->left && !visited[front->left])
            {
                flag = 1;
                q.push(front->left);
                visited[front->left] = 1;
            }
            
            /* if right connected node exist and not visited.
               then, push left node to queue, flag = true and visited = true.
            */
            if (front->right && !visited[front->right])
            {
                flag = 1;
                q.push(front->right);
                visited[front->right] = 1;
            }

            /* if parent node connected to front node exist and not visited.
               then, push parent node to queue, flag = true and visited = true.
            */
            if (NodeToParent[front] && !visited[NodeToParent[front]])
            {
                flag = 1;
                q.push(NodeToParent[front]);
                visited[NodeToParent[front]] = 1;
            }
        }
        /* If new node is added to queue then,
           it will definetly going to burn so increse time by 1sec
        */
        if (flag == 1)
            time++;
    }
    return time;
}

  
    int minTime(Node* root, int target) 
    {
        map<Node*, Node*> NodeToParent;

        // Creating nodeToParent mapping and finding target root.
        Node *targetRoot = CreatingParentMapping(root, NodeToParent, target);

        // Burning the tree in min time.
        int ans = burningTree(targetRoot, NodeToParent);

        return ans;
    }
};

// Link of these problem -> https://practice.geeksforgeeks.org/problems/burning-tree/1#