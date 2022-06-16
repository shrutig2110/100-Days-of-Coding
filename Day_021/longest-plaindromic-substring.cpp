class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0 , c = 0;
        int n = s.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int gap =0;gap<n;gap++)
        {
            for(int i =0, j=gap ;j<n;j++,i++)
            {
//                 For all the single elements(diagonal in the table)
                if(gap == 0)
                {
                    dp[i][j] = 1;
                }
//                 For all 2 sized palindrome check
                else if(gap == 1)
                {
                    if(s[i] == s[j])
                    {
                        dp[i][j] = 1;
                    }
                }
                else{
                    if(s[i] == s[j] && dp[i+1][j-1] == 1)
                    {
                        dp[i][j] =1;
                    }
                }
                if(dp[i][j])
                {
                    start =i;
                    c=gap+1;
                }
            }
        }
        return s.substr(start,c);
    }
};