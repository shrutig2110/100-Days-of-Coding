class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        // default matrix creation with rows= no.of columns of matrix and columns= no.of rows of matrix
        
        vector<vector<int>> res(matrix[0].size(),vector<int> (matrix.size(),0)); 
        
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                res[j][i] = matrix[i][j];  
            }
        }
        return res;
    }
};