class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
//      DP Table - 0|1|2|3|4|.....|target
        vector<int> dp(target+1,-1);
//      Number of ways to have 0 is 1 (0,0)
        dp[0] = 1;
        cs(nums,target,dp);
        return dp[target];
    }
    int cs(vector<int>& nums, int target, vector<int>& dp)
    {
//      If the no of ways of given target is already found
        if(dp[target]>-1)
        {
            return dp[target];
        }

        int count = 0;
        for(int i =0;i<nums.size();i++)
        {
            if(nums[i]<=target)
            {
                count += cs(nums,target-nums[i],dp);
            }
        }
        dp[target] = count;
        return count;
    }
};