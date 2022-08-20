class Solution {
public:
    bool check(int i , vector<int> adj[], vector<int> &color)
    {
        queue<int> q;
	    q.push(i);
	    color[i] = 0;
	    while(!q.empty())
	    {
	        int front = q.front();
	        q.pop();
	        for(auto x:adj[front])
	        {
                // If parent node and child node have same color then it is not bipartite graph
	            if(color[x]==color[front])
	            {
	                return false;
	            }
                // If parent is not visited then color it as 0 else 1 and push it to queue
	            if(color[x]==-1)
	            {
	                color[x] = color[front]?0:1;
	                q.push(x);
	            }
	        }
	    }
	    return true;
}
	bool isBipartite(int V, vector<int>adj[]){
	    vector<int> color(V+1,-1);
	    
	    for(int i=0;i<V;i++)
       {
           if(color[i]==-1)
           {
               if(!check(i,adj,color))
                return false;
           }
       }
       return true;
	}

};