class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int left =0;
        int sum =0;
        int tsum = 0;
        bool found = false;
        for(int i:nums)
        {
            tsum+=i;
        }
        
        int max_len=0;
        int n = nums.size();
        int target = tsum-x; 
        cout<<target<<endl;
        for (int right =0;right<n;right++)
        {
            sum += nums[right];
            while(left<=right && sum>target)
            {
                sum -= nums[left];
                left++;
            }
            if(sum == target)
            {
                found = true;
                max_len = max(max_len,right-left+1);
            }
        }
        return found?n-max_len:-1;
        
    }
};