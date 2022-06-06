// Leetcode
class Solution {
private:
    int winner(bool p1, vector<int>& nums, int i, int j)
    {
        if(i>j)
        {
            return 0;
        }
        if(p1)
        {
            return max( nums[i] + winner(false, nums, i+1, j), nums[j] + winner (false, nums,i,j-1));
        }
        else{
            return min(winner(true, nums, i+1, j), winner(true, nums, i, j-1));
        }
    }
public:
    bool PredictTheWinner(vector<int>& nums) {
        
        bool p1 = true;
        int ans;
        int sum = 0 ;
        for(int i = 0; i < nums.size(); i++)
        {
            sum += nums[i]; 
        }
        ans = winner(p1, nums, 0, nums.size()-1);
        sum -= ans;
        return ( ans >= sum) ? true : false;
    }
};