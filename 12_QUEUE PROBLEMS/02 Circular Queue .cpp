/*
    Time complexity: O(1) for all operations.
    Space Complexity: O(N)

    Where 'N' is the size of the queue.
*/
class CircularQueue
{

    // Array To be used for the implementation.
    int *arr;

    // Initialise front and rear of the queue.
    int front, rear;

    // Size of a Queue
    int size;

public:
    // Initialize your data structure.
    CircularQueue(int n)
    {
        size = n;

        // Create the arrays.
        arr = new int[size];

        // For a circular queue the front and rear both start as empty.
        front = rear = -1;
    }

    // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.
    bool enqueue(int value)
    {

        if ((front == 0) && (rear == size - 1) || (rear == (front - 1)))
        {
            /*
               If the queue is full, no more elements can be added so return false.
               Queue will be full if front is at 1st element and rear is at last element.
               OR if rear is equal to front - 1.
            */
            return false;
        }

        // Queue is empty, hence insert the first element.
        else if (front == -1)
        {
            front = rear = 0;
        }

        // If rear reaches end of queue but the first element is empty.
        else if (front != 0 && rear == size - 1)
        {
            rear = 0;
        }

        // Otherwise simply enqueue the element.
        else
        {
            rear++;
        }

        // push
        arr[rear] = value;
        return true;
    }

    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
    int dequeue()
    {

        // to check queue is  empty
        if (front == -1)
        {
            return -1;
        }
        int ans = arr[front];
        // arr[front] = -1;        //you can comment out this part you'll still get correct answer

        // single element is present
        if (front == rear)
            front = rear = -1;

        // to maintain cyclic nature
        else if (front == size - 1)
            front = 0;

        else
            front++;

        return ans;
    }
};

// Link of he problem -> https://www.codingninjas.com/codestudio/problems/circular-queue_1170058?leftPanelTab=2
