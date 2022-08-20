class Solution {
  public:
  bool cycle_dfs(vector<int> adj[], vector<int> &vis, int par, int i )
  {
      vis[i] = 1;
    // Perform dfs for every adjacent node and store it's prev element
      for(auto x: adj[i])
        {
            if(!vis[x])
            {
                if(cycle_dfs(adj,vis,i,x)) return true;
            }
            // If a node is visited and it is not the previous node then cycle is present 
            else if(x!=par){
                return true;
            }
        }
        return false;
  }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> isVisited(V+1,0);
        int parent = -1;
        for(int i =0;i<V;i++)
        {
            if(!isVisited[i])
            {
                if(cycle_dfs(adj, isVisited, parent, i))
                    return true;
            }
        }
        return false;
    }
};