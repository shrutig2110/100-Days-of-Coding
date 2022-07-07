class Solution {
private:
pair<int,int> diameterfast(Node* root)
{
    if(root == NULL)
    {
        pair<int,int> p = make_pair(0,0);
        return p;
    }
//  Calculate the diameter of left subtree 
    pair<int,int> left = diameterfast(root->left);
//  Calculate the diameter of rightt subtree 
    pair<int,int> right = diameterfast(root->right);
    
// Store the diameter of left subtree 
    int op1 = left.first;
// Store the diameter of right subtree
    int op2 = right.first;
// Store the height add the root node as +1 
    int op3 = left.second + right.second + 1;
    
    pair<int,int> ans;
//  Ans.first denotes max diameter among left subtree, right subtree and combo tree 
    ans.first = max(op1, max(op2,op3));
// Ans.second denotes max height 
    ans.second = max(left.second,right.second) + 1;
    return ans;
    
}
  public:
    int diameter(Node* root) {
        return diameterfast(root).first;
    }
};