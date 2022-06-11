class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int i =0, j= 0, n = nums.size();
        double max_sum = -1e9;
        double sum =0;
        for(int j =0;j<n;j++)
        {
            sum += nums[j];
            if(j-i+1 == k)
            {
                max_sum = max(max_sum, sum);
                sum -= nums[i];
                i++;
            }
        }
        return max_sum/k;
    }
};