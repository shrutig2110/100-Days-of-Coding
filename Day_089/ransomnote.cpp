class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> freq;
       
        for(int i =0;i<magazine.length();i++)
        {
            freq[magazine[i]]++;
        }
        for(int i =0;i<ransomNote.length();i++)
        {
            if(freq[ransomNote[i]]>0 ) 
            {
                freq[ransomNote[i]]--;
                
            }
            else return false;
        }
        return true;
    }
};