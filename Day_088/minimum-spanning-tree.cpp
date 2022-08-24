class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        int key[V];
        int parent[V];
        bool MST[V];
        // Setting all keys = max value, parent = -1, and mst = false
        for( int i =0;i<V;i++)
        {
            key[i] = INT_MAX;
            parent[i] = -1;
            MST[i] = false;
        }
        // Creating a priority queue to maintain min heap - reduce time complexity(logN)
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
        // Setting the root node key as 0 and parent as -1
        key[0] = 0;
        parent[0] = -1;
        // pair of key, node for root node
        pq.push({0,0});
        while(!pq.empty())
        {
            // node with the least value of key
            int u = pq.top().second;
            pq.pop();
            
            MST[u] = true;
            for(auto x: adj[u])
            {
                int node = x[0];
                int weight = x[1];
                // x.first = node , x.second - weight
                if(!MST[node] && weight<key[node])
                {
                    parent[node] = u; 
                    key[node] = weight;
                    pq.push({key[node],node});
                }
            }
        }
        int sum =0;
        for( int i =0;i<V;i++)
        {
            sum += key[i];
        }
        return sum;
    }
};