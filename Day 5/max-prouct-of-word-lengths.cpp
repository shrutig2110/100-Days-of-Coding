// Leetcode
class Solution {
private:
    bool check(string s1, string s2)
    {
        
        vector<bool> v(26, 0);
        for (int i = 0; i < s1.length(); i++)
        {   
            v[s1[i] - 'a'] = true;
        }
        for (int i = 0; i < s2.length(); i++)
        {   
            if (v[s2[i] - 'a'])
            {
                return false;
            }
               
        }
        return true;       
    }
    void prod(vector<string>& words, int n, int index, int& ans)
    {
        if(index == n-1)
        {
            return;
        }
        string s = words[index];
        for(int i = index+1; i< n; i++)
        {
            if(check(s, words[i]))
            {
                // string c = words[i];
                // cout<<s<< " and "<< words[i]<<" ";
                int strlen = s.length()* words[i].length();
                // cout<<strlen<<endl;
                if(strlen > ans)
                {
                    ans = strlen;
                } 
            }
            
        }
        prod(words,n,index+1, ans);
        
    }
public:
    int maxProduct(vector<string>& words) {
        int ans = 0;
        prod(words,words.size(),0, ans);
        return ans;
        
    }
};