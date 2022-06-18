#include <bits/stdc++.h>
using namespace std;

void reverese(node* &head,node* curr,node* prev){
    //1st method
    //base case 
    if(curr==NULL){
        head= prev;
        return;
    }
    reverese(head,curr->next,curr);
    curr->next = prev;
}
node* reverese1(node* head){
    //alternate methode
    if(head==NULL||head->next == NULL){
        return head;
    }
    node* chotahead = reverese1(head -> next);
    head -> next -> next = head;
    head->next =NULL;
    return chotahead;
}

node* reverseLinkedlist(node* head){
    if(head==NULL||head->next==NULL){
        return head;
    }
    node* prev = NULL;
    node* curr = head;
    reverse(head,curr,prev);
    return prev;
}

int main()
{
    
    return 0;
}