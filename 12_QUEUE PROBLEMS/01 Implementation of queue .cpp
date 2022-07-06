/*
    Time Complexity : O(q)
    Space Complexity : O(q)

    Where q is the number of queries.
*/

// Queue using Array
class Queue
{

    int *arr;
    int qfront;
    int back;
    int size;

public:
    Queue()
    {
        // Implement the Constructor
        size = 1000001;
        arr = new int[size];
        qfront = 0;
        back = 0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    // Function to check if the queue is empty.
    bool isEmpty()
    {
        if (qfront == back)
            return true;
        return false;
    }

    void enqueue(int data)
    {
        if (size == back)
            cout << "Queue is full" << endl;

        // Push the current element in the queue.
        arr[back] = data;
        back++;
    }

    int dequeue()
    {
        // Check if the queue is empty.
        if (qfront == back)
            return -1;

        int ans = arr[qfront];
        arr[qfront] = -1;
        qfront++;
        if (qfront == back)
        {
            qfront = 0;
            back = 0;
        }
        return ans;
    }

    int front()
    {

        // Check if the queue is empty.
        if (qfront == back)
            return -1;

        // Return the element at front.
        return arr[qfront];
    }
};

// Link of the Problem -> https://bit.ly/3uL7QDG

/***********************************************************/

// Queue using Linked list.
class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

class Queue
{
public:
    Node *head;
    Node *tail;
    int size;

    Queue()
    {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    ~Queue()
    {
        Node *temp = head;
        while (temp)
        {
            Node *t = temp;
            temp = temp->next;
            delete t;
        }
    }

    // Function to check if the queue is empty.
    bool isEmpty()
    {
        return size == 0;
    }

    void enqueue(int data)
    {

        // Increase the count of elements present in the List.
        size++;

        // Create a new node.
        Node *newNode = new Node(data);

        // Check if the Queue is empty.
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
            return;
        }

        // Push the element to the last of the queue.
        tail->next = newNode;
        tail = newNode;
        return;
    }

    int dequeue()
    {

        // Check if the queue is empty.
        if (isEmpty())
        {
            return -1;
        }

        int ans = head->data;

        Node *tmp = head;
        head = head->next;

        // If the queue is empty make the tail pointer NULL.
        if (head == NULL)
        {
            tail = NULL;
        }
        delete tmp;

        size--;

        return ans;
    }

    int front()
    {

        // Check if the queue is empty.
        if (isEmpty())
        {
            return -1;
        }

        // Return the element at the front.
        return head->data;
    }
};