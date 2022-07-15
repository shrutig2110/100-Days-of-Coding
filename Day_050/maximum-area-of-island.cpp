/*
PROBLEM : Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) 
connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded 
by water.
*/ 
class Solution {
private:
    void solve(vector<vector<int>>& grid, int i, int j, int n ,int m, int &count )
    {
        if(i>=n || j>=m || i<0 ||j<0 )
        {
            return;
        }
        if(grid[i][j]==0)
        {
            return;
        }
//      Mark it as visited by 
        grid[i][j] = 0;
        count++;
//      Right side
        solve(grid, i, j+1, n, m, count);
        solve(grid, i, j-1, n, m, count); //Left 
        solve(grid, i-1, j, n, m, count); //Above
        solve(grid, i+1, j, n, m, count); //Below
        
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int size_of_island = 0;
        for(int i =0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                int count = 0;
                if(grid[i][j]==1)
                {
                    solve(grid, i, j ,n ,m, count);
                    size_of_island = max(count,size_of_island );
                }
            }
        }
        return size_of_island;
    }
};