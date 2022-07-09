/*
PROBLEM: Kth Ancestor of a Node in a Binary Tree
*/ 
// Approach 1 : with extra space
void find(Node *root, int k , int node,vector<int> ans, int &ancestor)
{
    if(root == NULL)
    {
        return;
    }
    ans.push_back(root->data);
    if(root->data == node && ans.size()>=k)
    {
        int n = ans.size();
        // cout<<n<<endl;
        // if(n-k>0)
        // {
        //   ancestor = ans[n-k]; 
        // }
        for(int i =n-1;i>=0;i--)
        {
            if(k==0)
            {
                ancestor=ans[i];
            }
            k--;
        }
    }
    
    find(root->left, k , node, ans, ancestor);
    find(root->right, k , node, ans, ancestor);
    
}
int kthAncestor(Node *root, int k, int node)
{
    vector<int> ans;
    int ancestor = -1;
    find(root, k , node, ans, ancestor);
    return ancestor;
}

// Approach 2 : without extra space
Node* find(Node *root, int &k , int node)
   { // new code
    if(root == NULL)
    {
         return NULL;
    }
    if(root->data == node) 
    {
        return root;
    }
    
    Node* leftAns = find(root->left, k, node);
    Node* rightAns = find(root->right, k, node);

    //returning node to it's ancestor from left subtree
    if(leftAns != NULL && rightAns == NULL) 
    {
        k--;
        if(k<=0) 
        {
            //answer lock
            k = INT_MAX;
            return root;
        }
        return leftAns;
    }
    //returning node to it's ancestor from right subtree
    if(leftAns == NULL && rightAns != NULL) {
        k--;
        if(k<=0) 
        {
            //answer lock
            k = INT_MAX;
            return root;
        }
        return rightAns;
    }
    return NULL;
    
}
int kthAncestor(Node *root, int k, int node)
{
    Node* ans=find(root, k , node);
    if(ans == NULL)
    {
        return -1;
    }
    else{
        return ans->data;
    }
}
