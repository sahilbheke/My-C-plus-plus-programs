/*
    Time Complexity : O(1) per operation
    Space Complexity : O(N),

     where N is the given size of the array.
*/
// SOLUTION BY CODING NINJAS
class TwoStack
{
    //my code 
public:
    // Declaring the pointer to the array, size and top of the two stacks.
    int *arr, size, top1, top2;

    // Initializing array size and start the top of two stacks from extremes of the array.
    TwoStack(int s)
    {
        size = s;
        arr = new int[size];
        top1 = -1, top2 = size;
    }

    // Push in stack 1.
    void push1(int num)
    {
        // In case of overflow do nothing and return.
        if (top1 + 1 == top2)
        {
            return;
        }

        // Increment top of stack 1.
        top1 += 1;

        // Assign 'num' to the updated top index of stack 1.
        arr[top1] = num;
    }

    // Push in stack 2.
    void push2(int num)
    {
        // In case of overflow do nothing and return.
        if (top2 - 1 == top1)
        {
            return;
        }

        // Decrement top of stack 2.
        top2 -= 1;

        // Assign 'num' to the updated top index of stack 2.
        arr[top2] = num;
    }

    // Pop from stack 1 and return popped element.
    int pop1()
    {
        // In case of underflow return -1.
        if (top1 == -1)
        {
            return -1;
        }

        // Drcrement top of stack 1.
        top1 -= 1;

        // Return the value from the (top + 1)'th element of stack 1.
        return arr[top1 + 1];
    }

    // Pop from stack 2 and return popped element.
    int pop2()
    {
        // In case of underflow return -1.
        if (top2 == size)
        {
            return -1;
        }

        // Increment top of stack 2.
        top2 += 1;

        // Return the value from the (top - 1)'th element of stack 2.
        return arr[top2 - 1];
    }
};

// problem link -> https://www.codingninjas.com/codestudio/problems/two-stacks_983634?leftPanelTab=0