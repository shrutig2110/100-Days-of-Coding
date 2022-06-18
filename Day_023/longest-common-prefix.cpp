class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
         if(strs.size()==0){
            return "";
        }
        if(strs.size()==1){
            return strs[0];
        }
        for(int i=0;i<strs.size();i++)
        {
            cout<<strs[i]<<endl;
        }
      sort(strs.begin(),strs.end());
         for(int i=0;i<strs.size();i++)
        {
            cout<<strs[i]<<endl;
        }
        int n=strs.size();
        string s1=strs[0];
        string s2=strs[n-1];
        string res="";
        for(int i=0;i<s1.length();i++){
            if(s1[i]!=s2[i]){
                break;
            }
            else{
                res=res+s1[i];
            }
        }
        return res;
    }
};