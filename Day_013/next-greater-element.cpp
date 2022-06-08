class Solution {
private:
        int nextGreater(vector<int>nums2, int val)
        {
            int n= nums2.size();
            int val_index,i;
            for(i =0;i<n;i++)
            {
                if(nums2[i] == val)
                {
                    val_index = i;
                    break;
                }
            }
            i = val_index+1;
            while(i<n)
            {
                if(nums2[i]>val)
                {
                    return nums2[i];
                }
                i++;
            }
            return -1;
        }
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n= nums1.size();
        int val;
        for(int i=0;i<n;i++)
        {
            val = nums1[i];
            int ans = nextGreater(nums2,val);
            nums1[i] = ans;
        }
        return nums1;
    }
};