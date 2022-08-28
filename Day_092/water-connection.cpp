class Solution
{
    public:
    void dfs(int node, vector<pair<int,int>>g[], int &max_w, int &end, vector<int> &vis)
    {
        vis[node] = 1;
        for(auto e:g[node])
        {
            if(!vis[e.first])
            {
                // Store the min weight of path
                max_w = min(max_w, e.second);
                end = e.first;
                dfs(e.first, g, max_w, end, vis);
            }
        }
    }
    vector<vector<int>> solve(int n,int p,vector<int> a,vector<int> b,vector<int> d)
    {
        vector<vector<int>> ans;
        vector<int> vis(n+1,0);
        // Declare in and out vectors to store the in coming and outgoing edges of each node
        vector<int> in(n+1,0);
        vector<int> out(n+1,0);
        // To store the weights and destination of each edge
        vector<pair<int,int>> g[n+1];
        for(int i =0;i<p;i++)
        {
            out[a[i]] = 1;
            in[b[i]] = 1;
            g[a[i]].push_back({b[i],d[i]});
        }
        for(int i=1;i<=n;i++)
        {
            if(in[i] == 0 && out[i] == 1 && !vis[i])
            {
                int s = i;
                int e;
                int max_w = INT_MAX;
                dfs(i,g,max_w,e,vis);
                ans.push_back({s,e,max_w});
            }
        }
    return ans;
    }
};