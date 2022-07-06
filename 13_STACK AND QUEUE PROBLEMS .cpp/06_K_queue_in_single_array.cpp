#include <iostream>
#include<queue>

using namespace std;

class kqueue{
    int n,k,freespot;
    int *arr;
    int *next;
    int *front;
    int *rear;
    
    public:

        kqueue(int n, int k){
            this->n = n;
            this->k = k;

            arr = new int[n];
            next = new int[n];
            front = new int[k];
            rear = new int[k];

            for(int i = 0; i< k; i++){
                front[i] = -1;
                rear[i] = -1;
            }

            for(int i =0; i<n; i++){
                next[i]= i+1;
            }
            next[n-1] = -1;

            freespot = 0;
        }

        void enqueue(int data, int qn){

            // overflow
            if(freespot==-1){
                cout<<"array is full can't help!"<<endl;
                return;
            }
            int index = freespot;

            // update fornt
            freespot = next[index];

            // check whether first element 
            if(front[qn-1]==-1){
                front[qn-1] = index;
            }

            else{
                // link new element to the previous element 
                next[rear[qn-1]] = index;
            }

            // update next
            next[index] = -1;

            // update rear
            rear[qn-1]= index;

            // push element
            arr[index]= data;

        }

        int dequeue(int qn){

            // underflow
            if(front[qn-1]==-1){
                cout<<"queue is empty"<<endl;
                return -1;
            }

            // index for deleting element
            int index = front[qn-1];

            // update front
            front[qn-1] = next[index];

            // update next
            next[index] = freespot;

            // update freespot
            freespot = index;

            return arr[index];
        }

};

int main()
{
    kqueue q(10,3);
    q.enqueue(10,1);
    q.enqueue(15,1);
    q.enqueue(20,2);
    q.enqueue(25,1);

    cout<<q.dequeue(1)<<endl;
    cout<<q.dequeue(1)<<endl;
    cout<<q.dequeue(1)<<endl;
    cout<<q.dequeue(2)<<endl;
    cout<<q.dequeue(1)<<endl;

    return 0;
}