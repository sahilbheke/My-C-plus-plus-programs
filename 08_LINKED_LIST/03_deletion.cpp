#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int data)
    {
        // consturctor
        this->data = data;
        this->next = NULL;
    }
    // destructor
    ~node()
    {
        int value = this->data;
        // memory free
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "memory is free for node with data " << value << endl;
    }
};

void insertattail(node *&tail, int d)
{
    // new node created
    node *temp = new node(d);
    tail->next = temp;
    tail = tail->next;
}

void insertathead(node *&head, int d)
{
    // new node created
    node *temp = new node(d);
    temp->next = head;
    head = temp;
}

void print(node *&head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insertatposition(node *&tail, node *&head, int position, int d)
{
    if (position == 1)
    {
        insertathead(head, d);
        return;
    }

    node *temp = head;
    int cnt = 1;
    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }
    if (temp->next == NULL)
    {
        insertattail(tail, d);
        return;
    }
    node *nodetoinsert = new node(d);
    nodetoinsert->next = temp->next;
    temp->next = nodetoinsert;
}
void deletion(int position, node *&head)
{
    if (position == 1)
    {
        // deleting first node
        node *temp = head;
        head = head->next;
        temp->next = NULL;
        // memory free start node
        delete temp;
    }
    else
    {
        // deleting any middle node or last node
        node *curr = head;
        node *prev = NULL;
        int cnt = 1;
        while (cnt < position)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

int main()
{
    // created a new node
    node *node1 = new node(10);
    cout << node1->data << endl;
    cout << node1->next << endl;

    /// head pointed to node1
    node *head = node1;
    node *tail = node1;
    print(head);
    insertattail(tail, 12);
    print(head);
    insertattail(tail, 15);
    print(head);

    insertatposition(tail, head, 4, 22);
    print(head);
    cout << "head: " << head->data << endl;
    cout << "tail: " << tail->data << endl;

    deletion(3, head);
    print(head);
    return 0;
}