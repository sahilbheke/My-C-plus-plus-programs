#include <bits/stdc++.h>
using namespace std;

void reverese(node* &head,node* curr,node* prev){
    //base case 
    if(curr==NULL){
        head= prev;
        return;
    }
    reverese(head,curr->next,curr);
    curr->next = prev;
}//recursion

node* reverseLinkedlist(node* head){
    if(head==NULL||head->next==NULL){
        return head;
    }
    node* prev = NULL;
    node* curr = head;
    node* forward = NULL;

    while(curr!= NULL){
        forward = curr->next;
        curr->next = prev;
        prev= curr;
        curr=forward;

    return prev;
}

int main()
{
    
    return 0;
}