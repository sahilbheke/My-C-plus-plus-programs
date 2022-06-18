#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the Node class:

       class Node 
        { 
        public:
            int data;
            Node *next;
            Node(int data) 
            {
               this->data = data;
              this->next = NULL;
            }
        };

*****************************************************************/
int getlenght(Node * head){
	int len=0;
	while(head!=NULL){
		len++;
		head=head->next;
	}
	return len;
}
Node *findMiddle(Node *head) {
    int len= getlenght(head);
	int mid = (len/2)+1;
	int cnt=1;
	Node* temp = head;
	while(cnt<mid){
		cnt++;
		temp=temp->next;
	}
	return temp;
}