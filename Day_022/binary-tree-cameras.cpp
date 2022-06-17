/**
 DFS => Post-order 
 Starting from bottom to up
 
 */
class Solution {
private:
pair<bool,bool> count_camera(TreeNode* root)
{
//  Leaf node condition
    if(root == NULL)
    {
        return {false,true};
    }
    pair<bool,bool> L = count_camera(root->left);
    pair<bool,bool> R = count_camera(root->right);
    
    bool has_camera = false;
    bool is_monitored = false;
//  If at least one of node has camera so the root will be monitored
    if(L.first || R.first)
    {
        is_monitored = true;
    }
//  If any node is monitored it's root node must have a camera
    if(!L.second || !R.second)
    {
        has_camera = true;
        is_monitored = true;
        nCamera++;
    }
    return {has_camera, is_monitored};
    
}
public:
    int nCamera;
    int minCameraCover(TreeNode* root) {
        nCamera=0;
//      Starting from root node
        pair<bool,bool> temp = count_camera(root);
//      Root node if not monitored, then add a camera 
        if(!temp.second)
        {
            nCamera++;
        }
        return nCamera;
    }
};