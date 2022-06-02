class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
        {
            return false;
        }
        int num = x;
        long long int rem = 0, ans =0 ;
        while(num!=0)
        {
            ans = ans*10 + num%10;
            num = num/10;
        }
        return (ans == x)? true : false;
        }
};