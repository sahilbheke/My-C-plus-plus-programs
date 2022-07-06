// Function to reverse the queue.
queue<int> rev(queue<int> q)
{
    // MY CODE
    // craeting stack
    stack<int> s;

    // iterating while queue is not empty
    while (!q.empty())
    {

        // pushing element from queue to stack
        s.push(q.front());
        // removing element from queue
        q.pop();
    }

    // iterating while stack is not empty
    while (!s.empty())
    {
        // pushing top element from stack to queue
        q.push(s.top());
        // removing top element from stack
        s.pop();
    }
    return q;
}

// Link of this Problem -> https://practice.geeksforgeeks.org/problems/queue-reversal/1#