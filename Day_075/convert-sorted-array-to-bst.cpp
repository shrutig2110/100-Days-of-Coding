/*
PROBLEM: Given an integer array nums where the elements are sorted in ascending order, 
convert it to a height-balanced binary search tree.
A height-balanced binary tree is a binary tree in which the depth of 
the two subtrees of every node never differs by more than one.
*/ 
class Solution {
public:
    TreeNode* create_tree(vector<int>& nums, int start, int end,int n)
    {
        if(start>end)
        {
            return NULL;
        }
        int mid = start + (end-start)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        
        root->left = create_tree(nums,start,mid-1, n);
        root->right = create_tree(nums,mid+1, end, n);
        return root;
        
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int low = 0 ,high = nums.size() - 1;
        int n = nums.size();
        TreeNode* ans = create_tree(nums, low, high, n);
        return ans;
    }
};