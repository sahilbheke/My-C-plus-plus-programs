/*
    Time complexity: O(1) for all operations.
    Space Complexity: O(N)

    Where N is the size of the deque.
*/

class Deque
{

    int front, rear;
    int *arr;
    int size;

public:
    // Initialize your data structure.
    Deque(int n)
    {
        size = n;
        arr = new int[n];
        front = rear = -1;
    }

    // Pushes 'X' in the front of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushFront(int x)
    {
        // checking if queue is full
        if (isFull())
            return false;

        // checking if queue is empty
        else if (isEmpty())
            front = rear = 0;

        // for maintaining circular deque
        else if (front == 0)
            front = size - 1;

        else
            front--;

        // inserting value in queue
        arr[front] = x;

        return true;
    }

    // Pushes 'X' in the back of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushRear(int x)
    {
        // checking if queue is full
        if (isFull())
            return false;

        // checking if queue is empty
        else if (isEmpty())
            front = rear = 0;

        // for maintaining circular deque
        else if (rear == size - 1 && front != 0)
            rear = 0;

        else
            rear++;

        // inserting value in queue
        arr[rear] = x;

        return true;
    }

    // Pops an element from the front of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popFront()
    {
        if (isEmpty())
            return -1;

        // storing element to be poped
        int ans = arr[front];

        if (front == rear)
            rear = front = -1;

        // for maintaining circular deque
        else if (front == size - 1)
            front = 0;

        else
            front++;

        return ans;
    }

    // Pops an element from the back of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popRear()
    {
        if (isEmpty())
            return -1;

        // storing element to be poped
        int ans = arr[rear];

        if (rear == front)
            rear = front = -1;

        // for maintaining circular deque
        else if (rear == 0)
            rear = size - 1;

        else
            rear--;

        return ans;
    }

    // Returns the first element of the deque. If the deque is empty, it returns -1.
    int getFront()
    {
        if (isEmpty())
            return -1;

        return arr[front];
    }

    // Returns the last element of the deque. If the deque is empty, it returns -1.
    int getRear()
    {
        if (isEmpty())
            return -1;

        return arr[rear];
    }

    // Returns true if the deque is empty. Otherwise returns false.
    bool isEmpty()
    {
        if (front == -1)
            return true;

        return false;
    }

    // Returns true if the deque is full. Otherwise returns false.
    bool isFull()
    {
        if ((front == 0 && rear == size - 1) || (rear == front - 1))
            return true;

        return false;
    }
};

// Link of this problem -> https://bit.ly/3JoEvmF