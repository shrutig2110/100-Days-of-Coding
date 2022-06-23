/*
PROBLEM: Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.
*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0;
        int high =nums.size()-1;
        int mid = 0;
/*
      3 pointers - 
      low-> for tracking zero
      mid-> starts from 0 and keeps track of 1
      high-> starts from end of arr and keeps track of 2
*/
        while(mid<=high)
        {
           if(nums[mid] == 2)
           {
               swap(nums[mid],nums[high]);
               high--;
           }
           else if(nums[mid] == 0)
            {
               swap(nums[mid],nums[low]);
               low++;
               mid++;
           }
            else{
                mid++;
            }
        }
        
        // return nums;
        
    }
};