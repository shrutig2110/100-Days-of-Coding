class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int left =0, right =0;
        int sum = 0;
        int max_sum = 0;
        unordered_map<int, int> m;
            while(right<n)
            {
                // cout<<right<<endl;
                if(m[nums[right]] == 0)
                {
                    m[nums[right]]++;
                    sum += nums[right++];
                    
                                        
                }
                else{
                    m[nums[left]]--;
                    sum -=nums[left++]; 
                    
            }
            max_sum = max(sum, max_sum);
        } 
        return max_sum;
        
    }
};