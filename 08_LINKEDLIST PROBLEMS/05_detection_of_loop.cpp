

#include <bits/stdc++.h>
#include<map>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int d)
    {
        this->data = d;
        this->next = NULL;
    }
    ~node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << "mermory is free for node with data " << value << endl;
    }
};
void insertnode(node *&tail, int element, int d)
{
    if (tail == NULL)
    {
        // empty list
        node *newnode = new node(d);
        tail = newnode;
        newnode->next = newnode;
    }
    else
    {
        // non empty list
        // assuming that the element is present in the list
        node *curr = tail;
        while (curr->data != element)
        {
            curr = curr->next; // finding element
        }
        node *temp = new node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}
void print(node* &tail){
    node* temp =  tail;
    
    //empty list
    if(tail==NULL){
        cout<<"List is empty"<<endl;
        return;
    }
    
    do
    {   //alternate
        cout<<tail->data<<" ";
        tail = tail->next;
    } while (tail!=temp);
    cout<<endl;
    
}
void detectcycle(node* tail){
    if(tail==NULL){
        cout<<"Linked list is empty"<<endl;
        return;
    }
    map<node*,bool>visited;
    node* temp = tail;
    while(temp!=NULL){
        if(visited[temp]==true){
            cout<<"Loop exist in linked list at element "<<temp->data<<endl;
            return;
        }
        visited[temp]=true;
        temp=temp->next;
    }
    cout<<"LOOP does not exists in Linked List"<<endl;
    return;
}

int main()
{
    node *tail = NULL;
    insertnode(tail, 5, 3);
    print(tail);
    insertnode(tail, 3, 5);
    print(tail);
    insertnode(tail, 5, 7);
    print(tail);
    insertnode(tail, 7, 9);
    print(tail);
    insertnode(tail, 5, 6);
    print(tail);
    insertnode(tail, 9, 10);
    print(tail);
    insertnode(tail, 3, 4);
    print(tail);
    insertnode(tail, 7, 8);
    print(tail);
    
    detectcycle(tail);
    
    return 0;
}