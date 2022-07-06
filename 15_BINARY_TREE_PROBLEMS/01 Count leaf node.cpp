/**********************************************************

    Following is the Binary Tree Node class structure:

    template <typename T>
    class BinaryTreeNode {
      public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
                this -> data = data;
                left = NULL;
                right = NULL;
        }
    };
    
***********************************************************/
// void count(BinaryTreeNode<int> *root,int &cnt){
//     if(root==NULL)
//         return;
    
//     count(root->left,cnt);
//     if(root->left == NULL && root-> right == NULL)
//         cnt++;
    
//     count(root->right,cnt);
    
// }


// SAHIL'S CODE
void postorder(BinaryTreeNode<int> *root,int &cnt){
    if(root==NULL)
        return;

    postorder(root->left,cnt);
    postorder(root->right,cnt);
    if(root->left == NULL && root-> right == NULL)
        cnt++;
}

void inorder(BinaryTreeNode<int> *root,int &cnt){
    if(root==NULL)
        return;
    
    inorder(root->left,cnt);
    if(root->left == NULL && root-> right == NULL)
        cnt++;
    
    inorder(root->right,cnt);
    
}


int noOfLeafNodes(BinaryTreeNode<int> *root){
    //initializing count to 0
    int cnt=0;
    
    postorder(root,cnt);
    //you can also call inorder to count leaf node
    // try preorder on your own
    return cnt;
}

//LINK OF THIS PROBLEM -> https://bit.ly/3Lyh6kC

