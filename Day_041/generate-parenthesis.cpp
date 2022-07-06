class Solution {
private:
    vector<string> result;
    void perm(int open,int close,int n,string current)
    {
//      The max perm will be n*2
        if(current.length()==n*2)
        {
            result.push_back(current);
            return;
        }
//      The number of open brackets should always be less than n 
//      Eg:- for n =2 max open brackets will be "(())"/ "()()"
        if(open<n)  perm(open+1,close,n,current+"(");
//      The number of closing brackets can be less than the open brackets otherwise the case would be
//      Rg: (( )) "(" -> extra closing bracket more than open
        if(close<open) perm(open,close+1,n,current+")");
    }
public:
    vector<string> generateParenthesis(int count) {
        perm(0,0,count,"");
        return result;
        
    }
};