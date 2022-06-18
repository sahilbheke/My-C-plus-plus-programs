
//  FLOID CYCLE DETECTION ALGORITHM

#include <bits/stdc++.h>
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
node* floidcycle(node* tail){
    if(tail==NULL){
        return NULL;
    }
    node* slow= tail;
    node* fast = tail;
    while(fast!=NULL  && slow!=NULL ){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
        }
        slow=slow->next;
        if(fast==slow){
            return slow;
        }
    }
    return NULL;
}
node* getstartingnode(node * tail){
    if(tail==NULL){
        return NULL;
    }
    node* intersection = floidcycle(tail);
    node* slow = tail;
    while(slow!=intersection){
        slow=slow->next;
        intersection= intersection->next;
    }
    return intersection;
}
node *removeLoop(node *head)
{
    if(head==NULL){
        return NULL;
    }
    node* intersection = floidcycle(head);
    node* slow = head;
    while(slow!=intersection->next){
        slow=slow->next;
        intersection= intersection->next;
    }
	if(intersection->next == slow){
		intersection->next=NULL;
		return intersection;

	}
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

    node* loop = getstartingnode(tail);
    cout<<"Loop starts at "<<loop->data<<endl;
    node* temp = (removeLoop(tail));
    cout<<"Loop removed "<<temp->data<<endl;
    return 0;
}