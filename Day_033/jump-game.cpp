/*
PROBLEM: You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.
*/ 
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i = 0;
        int n = nums.size();
        for (int reach = 0; i < n && i <= reach; ++i)
        reach = max(i + nums[i], reach);
        return i == n;
    }
};