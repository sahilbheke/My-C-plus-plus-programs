#include <bits/stdc++.h>
#include <queue>

using namespace std;

class node
{
public:
    int data;
    node* right;
    node* left;

    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node* buildtree(node *root)
{

    cout << "Enter data: " << endl;

    int data;
    cin >> data;

    root = new node(data);

    if (data == -1)
        return NULL;

    cout << "Enter data for inserting in left " << data << endl;
    root->left = buildtree(root->left);
    cout << "Enter data for inserting in right " << data << endl;
    root->right = buildtree(root->right);

    return root;
}

void levelOrderTraversal(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        if(temp==NULL){
            cout<< endl;
            if(!q.empty())
                q.push(NULL);
        }

        else{
            cout<<temp -> data<<" ";
            if(temp->left)
                q.push(temp->left);

            if(temp->right)
                q.push(temp->right);
        }
    }
}

void inorder(node* root){
    if(root==NULL)
        return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void preorder(node* root){
    if(root==NULL)
        return;

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(node* root){
    if(root==NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}


int main()
{
    node *root = NULL;

    // creating tree
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 
    root = buildtree(root);

    //level order
    cout<<"Level order Traversal"<<endl;
    levelOrderTraversal(root);

    cout<<"inorder-> ";
    inorder(root);
    cout<<endl<<"preorder-> ";
    preorder(root);
    cout<<endl<<"postorder-> ";
    postorder(root);

    return 0;
}