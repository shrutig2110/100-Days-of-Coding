class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        vector<int>ans;
        int n = nums.size();
        int start=0,end=nums.size()-1;
        while(start<end)
            {
                if(target>(nums[start]+nums[end]))
                {
                    start++;
                }
                else if(target<(nums[start]+nums[end]))
                {
                    end--;
                }
                else
                {
                    break;
                }                      
            }
        return {start+1,end+1};
    }
};