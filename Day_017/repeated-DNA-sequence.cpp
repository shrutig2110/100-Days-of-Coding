class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int start = 0, end = 0, n = s.length();
        map<string,int> mp;
        vector<string> res;
        string temp ="";
        while(end<n)
        {
            temp = s.substr(start,10);
            mp[temp]++;
            start++;end++;
        }
        for(auto &it:mp)
        {
            if(it.second>=2)
            {
                res.push_back(it.first);
            }
        }
        return res;
    }
};