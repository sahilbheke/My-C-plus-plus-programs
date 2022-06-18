#include <bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node(int data){
        //consturctor
        this->data = data;
        this->next = NULL;
    }

};

void insertattail(node* &tail, int d){
    //new node created
    node* temp = new node(d);
    tail->next= temp;
    tail = tail-> next;
}

void insertathead(node* &head, int d){
    //new node created
    node* temp = new node(d);
    temp -> next = head;
    head = temp;
}

void print(node* &head){
    if(head==NULL){
        cout<<"List is empty"<<endl;
        return;
    }
    node* temp = head;
    while(temp!= NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

void insertatposition(node* &tail,node* &head, int position,int d){
    if (position==1){
        insertathead(head,d);
        return;
    }
    
    node* temp = head;
    int cnt =1;
    while(cnt<position-1){
        temp =  temp->next;
        cnt++;
    }
    if(temp->next==NULL){
        insertattail(tail,d);
        return;
    }
    node* nodetoinsert =new node(d);
    nodetoinsert->next = temp->next;
    temp->next= nodetoinsert;
}


int main()
{
    node* node1 = new node(10);
    cout<<node1->data<<endl;
    cout<<node1->next<<endl;

    
    node* head = node1;
    node* tail = node1;
    print(head);
    insertattail(tail,12);
    print(head);
    insertattail(tail,15);
    print(head);

    insertatposition(tail,head,4,22);
    print(head);
    cout<<"head: "<<head->data<<endl;
    cout<<"tail: "<<tail->data<<endl;
    return 0;
}