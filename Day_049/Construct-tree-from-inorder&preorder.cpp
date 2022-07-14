class Solution{
    private:
    void createMapping(int in[], map<int,int> &nodetoIndex ,int n)
    {
        for(int i =0;i<n;i++)
        {
            nodetoIndex[in[i]] = i;
        }
    }
    Node* solve(int in[], int pre[],int &index, map<int,int> &nodeToIndex, int inorder_start, int inorder_last, int n)
    {
        if(index>=n || inorder_start>inorder_last)
        {
            return NULL;
        }
        int element = pre[index++];
        Node* temp = new Node(element);
        int position = nodeToIndex[element];
        temp->left = solve(in, pre, index,nodeToIndex, inorder_start, position-1, n);
        temp->right = solve(in, pre, index, nodeToIndex, position+1, inorder_last,n );
        return temp;
        
    }
    public:
    Node* buildTree(int in[],int pre[], int n)
    {
        int preorderindex = 0;
        map<int,int> nodeToIndex;
        createMapping(in, nodeToIndex, n);
        Node* ans = solve(in, pre, preorderindex, nodeToIndex, 0, n-1, n);
        return ans;
    }
};