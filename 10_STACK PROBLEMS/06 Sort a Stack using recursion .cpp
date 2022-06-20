/*
    Time Complexity: O(N^2)
    Space Complexity: O(N),

    where N is the number of elements in the stack.
*/

// MY CODE
void sortingstack(stack<int> &stack, int x){
    
    //base case and if top element of stack is smaller than x then push x in stack
    if(stack.empty() ||  stack.top() < x ){
        stack.push(x);
        return;
    }
    
    // storing top element of stack
    int n = stack.top();
    // poping top element of stack
    stack.pop();
    
    // recursive call for the remaining elements in the stack
    sortingstack(stack,x);
    
    // pushing n into stack which was kept aside for sorting
    stack.push(n);
}

// Recursive method to sort a stack
void sortStack(stack<int> &stack)
{
	// base case
    if(stack.empty())
        return;
    
    //storing top element of stack
    int num = stack.top();
    // popoing top element of stack
    stack.pop();
    
    //recursion call for the remaining emelents in the stack
    sortStack(stack);
    
    //calling fuction to sort stack
    //Insert the popped element back in the sorted stack
    sortingstack(stack,num);
}

// Link of Problem -> https://bit.ly/3snpr1B