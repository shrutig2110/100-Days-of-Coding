class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int N, vector<int> adj[]) 
	{
	    vector<int> inDegree(N,0);
	   // Create in-degree vector
	    for(int i =0;i<N;i++)
	    {
	        for(auto x: adj[i])
	        {
	            inDegree[x]++;
	        }
	    }
	    queue<int> q;
	    vector<int> ans;
	   // Push all the nodes with indegree = 0
	    for(int i =0;i<N;i++)
	    {
	        if(inDegree[i]==0)
	        {
	            q.push(i);
	        }
	    }
	    
	    while(!q.empty())
	    {
	        int front = q.front();
	        ans.push_back(front);
	        q.pop();
	        for(auto x: adj[front])
	        {
	           // Decrement indegree by 1 and push in queue if 0
	            inDegree[x]--;
	            if(inDegree[x]==0) q.push(x);
	        }
	    }
	    return ans;
	}
};