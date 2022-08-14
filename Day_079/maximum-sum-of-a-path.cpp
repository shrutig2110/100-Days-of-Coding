/*
PROBLEM: Maximum Sum of a Path
*/ 
class Solution {
public:
    int findMaxPathSum(TreeNode* root, int &max_sum)
    {
      if (root == NULL) return 0;
//    To avoid null or negative values so comparing with 0
      int leftMaxPath = max(0, findMaxPathSum(root -> left, max_sum));
      int rightMaxPath = max(0, findMaxPathSum(root -> right, max_sum));
      int val = root -> val;
//    For storing max sum of any subtree
      max_sum = max(max_sum, (leftMaxPath + rightMaxPath) + val);
//    return the maximum of sub-tree
      return max(leftMaxPath, rightMaxPath) + val;

    }
    int maxPathSum(TreeNode* root) {
        int max_sum = INT_MIN;
        findMaxPathSum(root, max_sum);
        return max_sum;
    }
};