class Solution {
    vector<int> nextSmallerElement(vector<int> & arr, int n)
    {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);
        for(int i=n-1;i>=0;i--)
        {
    //      Starting from end element of array
            int curr = arr[i];
    //      Pop all numbers until we find the next smaller element
            while(s.top()!=-1 && arr[s.top()] >= curr)
            {
                s.pop();
            }
    //      We found the next smaller element
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }
    
    vector<int> prevSmallerElement(vector<int> & arr, int n)
    {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);
        for(int i=0;i<n;i++)
        {
    //      Starting from end element of array
            int curr = arr[i];
    //      Pop all numbers until we find the next smaller element
            while(s.top()!=-1 && arr[s.top()] >= curr)
            {
                s.pop();
            }
    //      We found the next smaller element
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }
public:
    int largestRectangleArea(vector<int>& heights) 
    {
        int area=INT_MIN,l,b;
        int n = heights.size();
        vector<int> nextsmall(n);
        nextsmall = nextSmallerElement(heights,n);
        vector<int> prevsmall(n);
        prevsmall = prevSmallerElement(heights,n);
        
        for(int i =0;i<n;i++)
        {
            if(nextsmall[i]==-1)
            {
                nextsmall[i]=n;
            }
            l = heights[i];
            b = nextsmall[i] - prevsmall[i] - 1;
            area = max(area,l*b); 
            
        }
        return area;
    }
};