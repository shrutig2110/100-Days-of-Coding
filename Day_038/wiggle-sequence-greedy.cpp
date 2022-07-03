class Solution {
public:
//  GREEDY APPROACH    
    int wiggleMaxLength(vector<int>& nums) {
        
        if(nums.size() ==1)
        {
            return 1;
        }
//If prev diff is zero means first 1st two elements are equal hence count = 1 to consider only one unique element
        int prev_diff = nums[1]-nums[0];
        int count =(prev_diff!=0)?2:1;
        int curr_diff =0;
        for(int i =2;i<nums.size();i++)
        {
            curr_diff = nums[i]-nums[i-1];
// Check condition for alternate positive and negative difference
            if(curr_diff<0 && prev_diff>=0 || curr_diff>0 && prev_diff<=0)
            {
                count++;
                prev_diff = curr_diff;
            }  
        }
        return count;
        
    }
};