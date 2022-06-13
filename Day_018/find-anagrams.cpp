class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int p_size = p.length();
        vector<int> ans;
        vector<int> p_hash(26,0);
        vector<int> s_hash(26,0);
        int start=0;
        if(p.length()>s.length())
            return ans;
        // for(int i =0;i<p_size;i++)
        // {
        //     p_hash[p[i]-'a']++;
        //     s_hash[s[i]-'a']++;
        // }
        for(int i=0;i<p_size;i++)
        {
            p_hash[p[i]-'a']++;
            s_hash[s[i]-'a']++;
        }
        if( p_hash == s_hash)
        {
            ans.push_back(0);
        }
         for(int i=p_size;i<s.length();i++)
        {
            s_hash[s[i-p_size]-'a']--;
            s_hash[s[i]-'a']++;
            if(s_hash==p_hash)
                ans.push_back(i-p_size+1);
        }
        return ans;
    }
};