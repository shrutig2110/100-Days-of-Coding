class Solution {
private:
    int first_occurence(vector<int>& nums, int target)
    {
        int ans = -1;
        int start = 0, end = nums.size()-1;
        int mid = start+(end-start)/2;
//         First occurence index
        while(start<=end)
        {
            if(nums[mid]==target)
            {
                ans = mid;
                end = mid -1;
            }
            else if(nums[mid]<target)
            {
                start = mid+1;
            }
            else{
                end = mid -1;
            }
            mid = start+(end-start)/2;
        }
        return ans;
    }
    
    int last_occurence(vector<int>& nums, int target)
    {
        int ans = -1;
        int start = 0, end = nums.size()-1;
        int mid = start+(end-start)/2;
//         First occurence index
        while(start<=end)
        {
            if(nums[mid]==target)
            {
                ans = mid;
                start = mid +1;
            }
            else if(nums[mid]<target)
            {
                start = mid+1;
            }
            else{
                end = mid -1;
            }
            mid = start+(end-start)/2;
        }
        return ans;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
        vector<int>res;
        
        res.push_back(first_occurence(nums,target));
        res.push_back(last_occurence(nums,target));
        return res;  
        
    }
};