#include<unordered_map>
#include<list>
#include<set>
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
//     Create adjacency list
    unordered_map<int, list<pair<int,int>>> adj;
    for(int i =0;i<edges ;i++)
    {
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];
//      For undirected graph
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }
//  Vector to return for min distance
    vector<int> dist(vertices);
    for(int i =0;i<vertices;i++)
    {
        dist[i] = INT_MAX;
    }
//  Set allows to access the smallest path possible for each node
    set<pair<int,int>> s;
//  Distance from source to source = 0
    dist[source] = 0;
    s.insert(make_pair(0,source));
    while(!s.empty())
    {
        auto top = *(s.begin());
        int node_distance = top.first;
        int topNode = top.second;
//      Remove top node
        s.erase(s.begin());
//      Traverse neighbouring nodes
        for(auto neighbour:adj[topNode])
        {
//          Calculate each neighbours distance and update the dist vector with the smallest one existing
            if(neighbour.second + node_distance < dist[neighbour.first])
            {
//              If same node with greater distance exists in the set delete it
                auto record = s.find(make_pair(dist[neighbour.first], neighbour.first));
                if(record!=s.end())
                {
                    s.erase(record);
                }
//              Now update distance in dist vector
                dist[neighbour.first] = neighbour.second + node_distance;
//              Push record in the set
                s.insert(make_pair(dist[neighbour.first], neighbour.first));
                
            }
        }  
    }
    return dist;
}