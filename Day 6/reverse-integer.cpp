class Solution {
public:
    int reverse(int x) {
        long long int ans=0;
        while(x!=0)
        {
            int num = x%10;
            ans = ans*10 + num; 
            if(ans >INT_MAX || ans<INT_MIN)
            {
                return 0;
            }
            x = x/10;
        }
        return ans;        
    }
};