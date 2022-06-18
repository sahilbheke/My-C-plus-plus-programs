#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *prev;
    node *next;

    // constructor
    node(int d)
    {
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }
    ~node()
    {
        int val = this->data;
        if (next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << "memory free for node with data " << val << endl;
    }
};

// travesing a linked list
void print(node *head)
{
    if(head==NULL){
        cout<<"List is empty"<<endl;
        return;
    }
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int getlength(node *head)
{
    // gives lenght of linked list
    int len = 0;
    node *temp = head;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}
void insertathead(node *&head, int d)
{
    node *temp = new node(d);
    temp->next = head;
    head->prev = temp;
    head = temp;
}
void insertattail(node *&tail, int d)
{
    node *temp = new node(d);
    temp->prev = tail;
    tail->next = temp;
    tail = temp;
}
void insertatposition(node *&tail, node *&head, int position, int d)
{
    // insert at start
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
    // inserting at last position
    if (temp->next == NULL)
    {
        insertattail(tail, d);
        return;
    }
    node *nodetoinsert = new node(d);
    nodetoinsert->next = temp->next;
    temp->next->prev = nodetoinsert;
    nodetoinsert->prev = temp;
    temp->next = nodetoinsert;
}
void deletion(int position, node *&head)
{
    if (position == 1)
    {
        // deleting first node
        node *temp = head;
        temp->next->prev = NULL;
        head = temp->next;
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
        curr->prev = NULL;
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

int main()
{
    node *node1 = new node(10);
    node *head = node1;
    node *tail = node1;

    print(head);
    cout << getlength(head) << endl;

    insertathead(head, 11);
    print(head);
    insertathead(head, 12);
    print(head);
    insertathead(head, 13);
    print(head);

    insertattail(tail, 25);
    print(head);

    insertatposition(tail, head, 2, 100);
    print(head);

    deletion(6, head);
    print(head);
    cout << "head " << head->data << endl;
    cout << "tail " << tail->data << endl;

    return 0;
}