class Solution
{
public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Create adjacency list
        // create bool visited array
        // run a for loop for every node as there are multiple disconnected components in graph
        // one node of a component makes every node count in bfs
        // bfs uses queue
        // if node not visited push it on the queue
        // take one by one node in to consideration and push the neighbouring nodes using 
        // by taking reference from adj list into queue and set it true in visited array 
        vector<int> bfs;
        vector<int> isVisited(V+1,0);
        queue<int> q;
        q.push(0);
        isVisited[0]=1;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            bfs.push_back(node);
            for(auto it:adj[node])
            {
                if(!isVisited[it])
                {
                    q.push(it);
                    isVisited[it]=1;
                }
            }
        }
        return bfs;
    }
};