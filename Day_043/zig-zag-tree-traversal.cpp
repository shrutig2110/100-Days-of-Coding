/*Traverse and print binary tree in zig-zag manner*/ 
class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
        vector<int> ans;
        // In queue we'll store each level nodes at a time
        queue<Node*> q;
        // We'll start from 1st level of tree that is root node
        q.push(root);
        int size = q.size();
        // For checking if traversal should be done from r->l or l->r
    	bool leftToRight = true;
    	while(!q.empty())
    	{
    	    size = q.size(); 
    	    vector<int> temp(size);
    	   
    	    for(int i=0;i<size;i++)
    	    {
    	        Node* frontNode = q.front();
    	        q.pop();
        	   // Index will be the start point to traverse nodes, so in case of 
        	   //l->r it will be 0 otherwise start from last
        	    int index = leftToRight?i:size-i-1; 
        	    temp[index] = frontNode->data;
        	    if(frontNode->left)
        	    {
        	        q.push(frontNode->left);
        	    }
        	    if(frontNode->right)
        	    {
        	        q.push(frontNode->right);
        	    }
    	    }
    	    for(auto x: temp)
    	    {
    	        ans.push_back(x);
    	    }
    	    leftToRight = !leftToRight;
    	    
    	}
    	return ans;
    }
};