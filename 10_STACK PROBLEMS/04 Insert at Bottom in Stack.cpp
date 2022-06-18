/*
    Time Complexity : O(N)
    Space Complexity: O(N)

    Where 'N' is the size of the given stack MY_STACK.      
*/

void solve(stack<int>& mystack, int x){
    //my code
    // Base Case
    if(mystack.empty()){
        mystack.push(x);
        return;
    }
    
    // Store top element in 'num'
    int num = mystack.top();
    
    // Pop the top element
    mystack.pop();
    
    // Recursive call
    solve(mystack,x);
    
    // Add 'num' to stack
    mystack.push(num);
}

stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    //calling function which adds the element at the bottom of stack
    solve(myStack, x);
    
    return myStack;
}

// link of Porblem -> https://bit.ly/34qqmGL






// ALTERNATE CODE BY CODING NINJA

stack<int> pushAtBottom(stack<int> &myStack, int x)
{
	// Base Case
	if (myStack.empty())
	{
		myStack.push(x);
		return myStack;
	}

	// Store top element in 'num'
	int num = myStack.top();

	// Pop the top element
	myStack.pop();

	// Recursive call
	pushAtBottom(myStack, x);

	// Add 'num' to stack
	myStack.push(num);

	return myStack;
}

