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




int main()
{
    node* head =NULL;
    int arr[]={1,2,3,4,5,6};
    for(int i =0; i<6; i++){
        insertattail(head,arr[i]);
    }
    print(head);
    // evenafterodd(head);
    // print(head);
    return 0;
}