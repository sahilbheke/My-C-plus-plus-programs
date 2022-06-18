private:
        void insertattail(Node* &head,Node* &tail,int val){
            Node* temp = new Node(val);
            if(head==NULL){
                head = temp;
                tail = temp;
            }
            
            else{   
            
                tail->next = temp;
                tail = temp;
                
            }
            
        }
    public:
    Node *copyList(Node *head)
    {
        //step1 : create a clone 
        Node *clonehead = NULL;
        Node *clonetail = NULL;
        Node *temp = head;
        while(temp != NULL){
            insertattail(clonehead,clonetail,temp -> data);
            temp = temp -> next;
        }
        //step2 : cloneNodes add in between original list
        Node* originalnode = head;
        Node* clonenode = clonehead;
        
        while(originalnode!=NULL && clonenode!=NULL){
            Node* next = originalnode -> next;
            originalnode->next = clonenode;
            originalnode = next;
            
            next = clonenode->next;
            clonenode ->next = originalnode;
            clonenode = next;
        }
        //step3 : random pointers copy 
        temp =head;
       
        
        while(temp!= NULL){
            if(temp->next != NULL){
                
            temp -> next -> arb = temp -> arb ?
            temp -> arb -> next : temp->arb;
            //     if(temp -> arb != NULL){

            //         temp->next->arb = temp ->arb -> next;
            //     }
            //     else {
            //         temp -> next = temp-> arb;
            //     }
            // }
            temp = temp->next->next;
            
        }
        
        
        //step4 : revert changes done in step 2
        originalnode = head;
        clonenode= clonehead;
        while(originalnode != NULL && clonenode!= NULL){
            // Node * next = originalnode -> next;
            originalnode->next = clonenode->next;
            originalnode = originalnode->next;
            if(originalnode!=NULL){
                clonenode->next =originalnode->next;
               
            }
             clonenode= clonenode->next;
        }
        //step5 : return ans
        return clonehead;
    }