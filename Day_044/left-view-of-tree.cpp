/*
PROBLEM: Print left view of a binary tree
*/ 

void solve(Node *root,  vector<int> &ans, int level)
{
    if(root==NULL)
    {
        return;
    }
    // if this is the first node of the level then store it in the answer
     if(ans.size() == level)
     {
         ans.push_back(root->data);
     }
     solve(root->left, ans, level+1);
     solve(root->right, ans, level+1);
     
}
vector<int> leftView(Node *root)
{
   vector<int> ans;
   solve(root, ans, 0);
   return ans;
}
