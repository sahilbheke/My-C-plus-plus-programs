// Function to reverse first k elements of a queue.
queue<int> modifyQueue(queue<int> q, int k)
{
    //creating stack
    stack<int> s;

    //pushing k element from queue to stack
    for (int i = 0; i < k; i++)
    {
        s.push(q.front());
        q.pop();
    }

    // pushing stack elements at the end of queue (which wil be in reverse order due to stack LIFO )
    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
    }

    // number of remaining elements in queue
    int t = q.size() - k;

    // moving remaining elements queue from front to back
    {
        int a = q.front();
        q.pop();
        q.push(a);
    }

    return q;
}

// Link of this Problem -> https://practice.geeksforgeeks.org/problems/reverse-first-k-elements-of-queue/1/#