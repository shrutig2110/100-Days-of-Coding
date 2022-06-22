/*
PROBLEM: Given two strings s and t, return true if t is an anagram of s, and false otherwise.
*/
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> count;
//         Two strings can be anagram only if they have same length
        if(s.length() != t.length())
        {
            return false;
        }
//      Simultaneously add chars from s string and remove chars from t string
//      So that every char will be added and subracted(nullify) and hence count = 0
        for(int i =0;i<s.length();i++)
        {
            count[s[i]]++;
            count[t[i]]--;
        }
        for(auto i: count)
        {
//          If any char count is atleast 1 means there is an extra char in any of the string
//          hence the two strings are not anagrams
            if(i.second)
            {
                return false;
            }
        }
        return true;
        
    }
};