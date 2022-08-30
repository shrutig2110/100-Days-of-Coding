class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int i,j;
        int n=matrix.size();
        for(i=0;i<n;i++)
        {
            for(j=i;j<n;j++)
            {
                // cout<<j<<"for i: "<<i<<endl;
                // cout<<matrix[i][j]<<" with "<<matrix[j][i]<<endl;
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        for(i=0;i<n;i++)
        {
            reverse(matrix[i].begin(),matrix[i].end());
        }
        
        
    }
};