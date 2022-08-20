class Solution {
public:
    bool check(int i , vector<int> adj[], vector<int> &color, int par)
    {
        if(color[i]==-1)
        {
            color[i]=1;
        }
        for(auto x: adj[i])
         {
            if(color[x] == color[i])
            {
                return false;
            }
            if(color[x]==-1)
            {
                color[x] = 1- color[i];
                if(!check(x,adj,color,i)) return false;
            }
         }
         return true;
    }
	bool isBipartite(int V, vector<int>adj[]){
	    vector<int> color(V+1,-1);
	    
	    int par = 0;
	    for(int i=0;i<V;i++)
       {
           if(color[i]==-1)
           {
               if(!check(i,adj,color, par))
                return false;
           }
       }
       return true;
	}

};