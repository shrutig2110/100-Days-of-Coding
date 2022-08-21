/*
GFG CONTEST PROBLEM
PROBLEM: Given an arr of length n, split elements into pair such that each element should be part of exactly one pair 
and their sum is even. Find if such split is possible or not.
*/ 
class Solution {
  public:
    bool makeEven(vector<int> arr) {
        // Base case for size 2
        if(arr.size()==2)
        {
            return (arr[0]+arr[1])%2==0?1:0;
        }
        if(arr.size()%2!=0)
        {
            return 0;
        }
        vector<int> even;
        vector<int> odd;
        for(int i =0;i<arr.size();i++)
        {
            if(arr[i]%2==0)
            {
                even.push_back(arr[i]);
            }
            else{
                odd.push_back(arr[i]);
            }
        }
        
        if(odd.size()%2==0 && even.size()==0 || odd.size()==0 && even.size()%2==0)
        {
            return 1;
        }
        if(odd.size()%2==0 && even.size()%2!=0 
        || odd.size()%2!=0 && even.size()%2==0 || odd.size()%2!=0 && even.size()%2!=0)
        {
            return 0;
        }
        
        return 1;
    }
};