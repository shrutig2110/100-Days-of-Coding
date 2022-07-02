class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans = 0;
        for(int i=s.size()-1;i>=0;--i){
// If last element is ' ' and ans is zero => means the last word is yet to be encountered
            if(s[i] == ' ' && ans > 0) return ans;
// If word encountered increment counter by 1
            if(s[i] != ' ') ans++;
        }
        return ans;
    }
};