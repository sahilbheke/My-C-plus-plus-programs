/*******************************
Node *merge(Node *down, Node *right)
{
    if (down == NULL)
        return right;
    if (right == NULL)
        return down;
    Node *ans = new Node(-1);
    Node *temp = ans;
    while (down != NULL && right != NULL)
    {
        if (down->data < right->data)
        {
            temp->next = down;
            temp = down;
            down = down->next;
        }
        else
        {
            temp->next = right;
            temp = right;
            right = right->next;
        }
    }

    while (down != NULL)
    {
        temp->next = down;
        temp = down;
        down = down->next;
    }
    while (right != NULL)
    {
        temp->next = right;
        temp = right;
        right = right->next;
    }
    ans = ans->next;
    return ans;
}
Node *flattenLinkedList(Node *head)
{
    if (head == NULL )
    {
        return head;
    }
    Node *down = head;
    down->next = NULL;
    // recursion
    Node *right = flattenLinkedList(head->next);
    // merge
    Node *ans = merge(down, right);
    return ans;
}
**********************/

//alternate

#include<algorithm>

Node* flattenLinkedList(Node* root) 
{
	vector<int> answer ;

	// Traverse the linkedlist and add all the nodes to the array
	while (root != NULL) 
	{
		answer.push_back(root->data);
		Node *temp = root;

		// Add all child nodes
		while (temp->child != NULL) 
		{
			answer.push_back(temp->child->data);
			temp = temp->child;
		}
		root = root->next;
	}

	sort(answer.begin(), answer.end());

	Node *head = NULL;
	Node *tail = NULL;

	// Create new linked list
	for (int i = 0; i < answer.size(); ++i) 
	{
		Node *newNode = new Node(answer[i]);
		if (head == NULL) 
		{
			head = newNode;
		} 
		else 
		{
			tail->child = newNode;
		}
		tail = newNode;
	}
	return head;
}
