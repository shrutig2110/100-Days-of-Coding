class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = 0, p2 = 0, t= m+n;
        //Compare elements until nums1 and nums 2 still has elements
        while(p1<m && p2<n)
        {
            if(nums1[p1]<nums2[p2])
            {
                p1++;
            }
            else if(nums1[p1]>nums2[p2])
            {
                swap(nums1[p1],nums2[p2]);
                //Sort nums2 array after each swap(For cases where nums 1 has large values than nums1) 
                sort(nums2.begin(),nums2.end());
                p1++;
                
            }
            else{
                p1++;
            }
        }
        //Enter the remaining values of nums2 in nums 1 until nums1.size() = total no. of elements in             nums1 and nums2
        while(p2<n)
        {
            nums1[p1++] = nums2[p2++];
        }
    }
};