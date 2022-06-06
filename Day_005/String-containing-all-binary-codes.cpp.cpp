// Leetcode
class Solution {
 public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string> perm;
        int count =pow(2,k);
        if(k>s.size())
        {
            return false;
        }
        for(int i =0;i<s.size();i++)
        {
            if(s.substr(i,k).size() == k)
            {
               perm.insert(s.substr(i,k)); 
            }
            
            
        }
        
//         unordered_set<string> :: iterator itr;
//         for (itr =perm.begin(); itr != perm.end(); itr++)
            
//             cout << (*itr) << endl;
        
        if(perm.size() == count)
        {
            return true;
        }
        else{
            return false;
    }
    }
};
