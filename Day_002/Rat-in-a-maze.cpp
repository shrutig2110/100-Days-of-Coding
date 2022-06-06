#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution{
    private:
    bool isSafe(int x, int y, vector<vector<int>> visited, vector<vector<int>> m, int n)
    {
        if((x>0 && x<n) && (y>0 && y < n) && visited[x][y] == 0 && m[x][y] == 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void maze(int x, int y, string path, vector<vector<int>> visited, vector<vector<string>>& ans, 
                vector<vector<int>> m, int n)
    {
        if(x==n-1 && y==n-1)
        {
            ans.push_back(path);
            return;
        }
        
        visited[x][y] = 1;
        //Down
        int newx = x+1;
        int newy = y;
        if(isSafe(newx, newy, visited, m, n))
        {
            path.push_back('D');
            maze(newx, newy, path, visited, ans, m, n);
            path.pop_back();
        }
        
        //Left
        newx = x;
        newy = y-1;
        if(isSafe(newx, newy, visited, m, n))
        {
            path.push_back('L');
            cout<<path<<endl;
            maze(newx, newy, path, visited, ans, m, n);
            path.pop_back();
        }
        
        //Right
        newx = x;
        newy = y+1;
        if(isSafe(newx, newy, visited, m, n))
        {
            path.push_back('R');
            maze(newx, newy, path, visited, ans, m, n);
            path.pop_back();
        }
        
        //up
        newx = x-1;
        newy = y;
        if(isSafe(newx, newy, visited, m, n))
        {
            path.push_back('U');
            maze(newx, newy, path, visited, ans, m, n);
            path.pop_back();
        }
        
        visited[x][y]=0;
    }
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<vector<string>> ans;
        string path="";
        vector<vector<int>> visited = m;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                visited[i][j]=0;
            }
        }
        int x = 0;
        int y = 0;
        
        //Base case
        for(m[x][y] == 0)
        {
            return -1;
        }
        maze(x, y, path, visited, ans, m, n);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  