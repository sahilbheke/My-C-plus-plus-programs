/*
    Time Complexity: O(N^2)
    Space Complexity: O(N)

    Where N is the number of elements in Stack.
*/

void insertatbottom(stack<int> &stack, int x)
{   //MY CODE

    // base case
    // if stack is empty then push x at the bottom of stack
    if (stack.empty())
    {
        stack.push(x);
        return;
    }

    // storing top element of stack
    int num = stack.top();
    // poping top element of stack
    stack.pop();

    // recursive call
    insertatbottom(stack, x);
    // inserting num in stack
    stack.push(num);
}

void reverseStack(stack<int> &stack)
{
    // base case
    if (stack.empty())
    {
        return;
    }

    // storing top element of stack
    int num = stack.top();
    // poping top element of stack
    stack.pop();

    // recursive call to every element of stack
    reverseStack(stack);

    // fuction call for reversing stack
    insertatbottom(stack, num);
}

// Link of Problem -> https://bit.ly/3HCBnD4