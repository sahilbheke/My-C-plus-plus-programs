/*
    Time complexity: O(1)
        For push(): O(1) - Constant extra space is required.
        For pop(): O(1) - Constant extra space is required.
        For top(): O(1) - Constant extra space is required.
        For getMin(): O(1) - Constant extra space is required.
        For isEmpty(): O(1) - Constant extra space is required.

    Space complexity: O(1)
*/

#include <stack>

class SpecialStack {
    // Define the data members.
    stack<int>s;
    int min;
    public:
        
    void push(int data) {

        //base case 
        if(s.empty()){
            min = data;
            s.push(data);
        }

        else{

            // if data is smaller than minimum element than push 2*data - min in satck
            if(data<min){
                s.push(2*data-min);
                min = data;
            }

            //else push data
            else
                s.push(data);
        }
            
    }

    int pop() {

        //base case
        if(s.empty())
            return -1;

        // storing top element of stack
        int curr = s.top();
        //poping top element 
        s.pop();

        //if curr (top element of stack) is smaller than minimum element than 
        //return minimum element which is also poped element
        //and update minimum element 
        if(curr<min){
            int prevmin = min;
            min = 2*min-curr;;
            return prevmin;
        }
        else
            return curr; 
    }

    int top() {
        //base case
        if(s.empty())
            return -1;

        //storing top element of satck in curr
        int curr = s.top();

        // if top element of stack is smaller than minimum element than 
        //return minimum element which also your curr element 
        if(curr<min) return min;
        
        else return curr;
    }

    bool isEmpty() {

        // if empty return true else false
        return s.empty();
    }

    int getMin() {
        //base case
        if(s.empty()) return -1;

        //return minimum element 
        return min;
    }  
};

//link of the problem ->  https://bit.ly/3LpVPJM





//Alternate solution on coding ninjas

# include <stack>

class SpecialStack {
    stack<int> s1, s2;

    public:
        
    void push(int data) {
        if(isEmpty()) {
            s1.push(data);
            s2.push(data);
        }
        else {
            s1.push(data);
            s2.push(min(data, s2.top()));
        }
    }

    int pop() {
        if (isEmpty()) {
            return -1;
        }
        int x = s1.top();
        s1.pop();
        s2.pop();
        return x;
    }

    int top() {
        if (isEmpty()) {
            return -1;
        }
        return s1.top();
    }

    bool isEmpty() {
        return s1.empty();
    }

    int getMin() {
        if(isEmpty()) {
            return -1;
        }
        return s2.top();
    }
};
/**********************
1. push(data) :
This function should take one argument of type integer. It pushes the element into the stack and returns nothing.

2. pop() :
It pops the element from the top of the stack and, in turn, returns the element being popped or deleted. In case the stack is empty, it returns -1.

3. top() :
It returns the element being kept at the top of the stack. In case the stack is empty, it returns -1.

4. isEmpty() :
It returns a boolean value indicating whether the stack is empty or not.

5. getMin() :
It returns the smallest element present in the stack. In case the stack is empty, it returns -1.
**********************/