#include<stack>
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);
    for(int i=n-1;i>=0;i--)
    {
//      Starting from end element of array
        int curr = arr[i];
//      Pop all numbers until we find the next smaller element
        while(s.top() >= curr)
        {
            s.pop();
        }
//      We found the next smaller element
        ans[i] = s.top();
        s.push(curr);
    }
    return ans;

}