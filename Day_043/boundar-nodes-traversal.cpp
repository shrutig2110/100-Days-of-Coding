/*
PROBLEM: Print boundary nodes of a Binary Tree
*/ 
class Solution {
private:
// Left subtree bondary nodes excluding leaf nodes
    void traverseLeft(Node* root, vector<int> &ans)
    {
        if(root == NULL || root->left == NULL && root->right == NULL )
        {
            return;
        }
        ans.push_back(root->data);
        if(root->left)
        {
             traverseLeft(root->left, ans);
        }
        else{
             traverseLeft(root->right, ans);
        }
       
    }
    // Leaf nodes traversal
    void traverseLeaf(Node* root, vector<int> &ans)
    {
        if(root == NULL )
        {
            return;
        }
        if(root->left == NULL && root->right == NULL)
        {
            ans.push_back(root->data);
            return;
        }
        traverseLeaf(root->left, ans);
        traverseLeaf(root->right, ans);
    }
    // Reverse Right subtree travesal - used tail recursion for reversing
    void traverseRight(Node* root, vector<int> &ans)
    {
        if(root == NULL || root->left == NULL && root->right == NULL)
        {
            return;
        }
        if(root->right)
        {
            traverseRight(root->right, ans);
        }
        else{
            traverseRight(root->left, ans);
        }

        ans.push_back(root->data);
        
    }
    
public:
    vector <int> boundary(Node *root)
    {
        vector<int> ans;
        ans.push_back(root->data);
        traverseLeft(root->left, ans);
        traverseLeaf(root->left,ans);
        traverseLeaf(root->right, ans);
        traverseRight(root->right,ans);
        return ans;
    }
};