class Solution {
private:
    bool isPalindrome(string s, int n)
    {
        string temp=s;
        reverse(temp.begin(),temp.end());
        if(temp == s)
        {
            return true;
        }
        return false;
    }
public:
    int removePalindromeSub(string s) {
        int n = s.length();
        if(n == 0)
        {
            return 0;
        }
        if(isPalindrome(s,n))
        {
          return 1;  
        }
        return 2;
    }
};