class Solution {
  public:
  bool cyclebfs(int src,vector<int> adj[], vector<bool> visited)
  {
        unordered_map<int, int> parent;
    
        parent[src] = -1; // mark parent = -1 of src node received of the connected component
        visited[src] = 1; // mark src node as visited
    
        queue<int> q;
        q.push(src);
       
        while(!q.empty())
        {
            int front = q.front();
            q.pop();
                     
            // take neighbours of frontnode
            for(auto neighbour :adj[front])
            {
                if(visited[neighbour]==true && neighbour != parent[front])
                    return true;
                else if(!visited[neighbour])
                { 
                    /* push the neighbour in queue, mark it as true and set 
                       neighbour as front. */
                    q.push(neighbour);
                    visited[neighbour] = 1;
                    parent[neighbour] = front;
                  }
                }
            }
    return false;
}
    bool isCycle(int V, vector<int> adj[])
    {
       vector<bool>vis(V,false);
       
          for(int i=0; i<V; i++)
          {
              if(!vis[i])
              {
                  if(cyclebfs(i,adj,vis))
                    return true;
              }
                
          }
          
          return false;
    }
};