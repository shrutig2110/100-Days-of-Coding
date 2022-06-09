class Solution {
private:
     vector<int> nextSmallerElement(vector<int>& arr, int n)
    {
         // vector<int> arr(n);
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
    
    vector<int> prevSmallerElement(vector<int>& arr, int n)
    {
        // vector<int> arr(n);
        // cout<<endl;
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
     int largestRectangleArea(vector<int>& heights, int n) 
    {
        int area=INT_MIN,l,b;
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
public:
    int maximalRectangle(vector<vector<char>>& M) {
        
        int rows = M.size();
        int cols = M[0].size();
        vector<int> matrix;
        
        for (int i = 0; i < cols; ++i)
        {
            matrix.push_back(M[0][i] - '0');
        }
        int area = largestRectangleArea(matrix,cols);
           for(int i =1;i<rows;i++)
           {
               for (int j =0;j<cols;j++)
               {
                        
                    if (M[i][j] == '0')
                        matrix[j] = 0;
                    else
                        ++matrix[j];
               }
               area = max(area, largestRectangleArea(matrix,cols));
           }
           return area;
        }
    
};