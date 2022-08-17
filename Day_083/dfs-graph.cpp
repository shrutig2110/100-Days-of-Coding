class Solution {
  public:
    void dfs_traversal(int node,vector<int> adj[], vector<int> &dfs, vector<int> &vis)
    {
        dfs.push_back(node);
        vis[node]=1;
        for(auto it: adj[node])
        {
            if(!vis[it])
            {
                dfs_traversal(it,adj,dfs,vis);
            }
        }
    }
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> dfs;
        vector<int> isVisited(V+1,0);
        // dfs.push_back(0);
        // isVisited[0] = 1;
        dfs_traversal(0,adj,dfs,isVisited);
        return dfs;
    }
};