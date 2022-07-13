class Solution{
    //Function to find the leaders in the array.
    public:
    vector<int> leaders(int a[], int n){
        vector<int> ans;
        int max = a[n-1];
        ans.push_back(max);
        for(int i =n-2;i>=0;i--)
        {
            if(a[i]>=max)
            {
                max = a[i];
                ans.push_back(max);
            }
        }
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};