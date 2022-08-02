/*
PROBLEM: Unique Paths
*/ 
class Solution {
public:
//     TLE SOLUTION //
//     void find_path(int m ,int n, int& count, int i, int j)
//     {
// //       Check if it is getting out of boundary of 2d array
//         if(i>m || j>n )
//         {
//             return;
//         }
// //      You reached the end point
//         if(i == m-1 && j== n-1)
//         {
//             count++;
//         }
// //      Moving downward
//         find_path(m, n, count, i+1, j);
// //      Moving right
//         find_path(m, n, count, i, j+1);
//     }
    int uniquePaths(int m, int n) {
//      Memoization - Dynamic Programming
        vector<vector<int>> dp(m,vector<int>(n,1));
        for(int i =1;i<m;i++)
        {
            for(int j = 1;j<n;j++)
            {
                dp[i][j] = dp[i][j-1] + dp[i-1][j];
            }
        }
        return dp[m-1][n-1];
    }
};