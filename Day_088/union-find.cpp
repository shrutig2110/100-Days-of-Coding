class Solution
{
    public:
    // find parent of node
    int findPar(int node, int par[])
    {
        if(node == par[node])
        {
            return node;
        }
        
        par[node] = findPar(par[node], par);
        return par[node];
        
    }
    //Function to merge two nodes a and b.
    void union_( int a, int b, int par[], int rank1[]) 
    {
        
        int par1 = findPar(a, par);
        int par2 = findPar(b, par);
        
        int rank_a = rank1[par1];
        int rank_b = rank1[par2];
        
        if(rank_a < rank_b)
        {
            par[par1] = par2;
        }
        else if(rank_a > rank_b)
        {
            par[par2] = par1;
        }
        else{
            par[par2] = par1;
            rank1[par1]++;
        }
        
        
    }
    
    //Function to check whether 2 nodes are connected or not.
    bool isConnected(int x,int y, int par[], int rank1[])
    {
        return findPar(x,par)==findPar(y,par)? :0;
        
    }
};