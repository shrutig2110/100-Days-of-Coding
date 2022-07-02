/*
PROBLEM: Write a function to find the longest common prefix string amongst an array of strings.
If there is no common prefix, return an empty string "".
*/ 
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
         if(strs.size()==0){
            return "";
        }
        if(strs.size()==1){
            return strs[0];
        }

      sort(strs.begin(),strs.end());
         for(int i=0;i<strs.size();i++)
        {
            cout<<strs[i]<<endl;
        }
        int n=strs.size();
// The middle element is assume to have the least common prefix from 1st string therfore we are checking only the 1st and last string after sorting
        string s1=strs[0];
        string s2=strs[n-1];
        string res="";
        for(int i=0;i<s1.length();i++){
            if(s1[i]!=s2[i]){
//          Break the loop when first discontinuity occurs
                break;
            }
            else{
                res=res+s1[i];
            }
        }
        return res;

    }
};