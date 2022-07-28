class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0;
        int shortest_subarr = INT_MAX;
        int left =0;
        int right = 0;
        int n = nums.size();
        while(right<n)
        {
            sum += nums[right];
            while(sum>=target)
            {
                while(sum>=target)
                {
                    sum -= nums[left];
                    left++;
                }
                shortest_subarr = min(shortest_subarr, right-left+2);
            }
            right++;
        }
        return shortest_subarr==INT_MAX?0:shortest_subarr;
    }
};