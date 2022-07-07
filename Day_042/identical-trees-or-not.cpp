   
class Solution
{
    public:
    //Traverse both the trees in same direction and check each node
    bool isIdentical(Node *r1, Node *r2)
    {
        if(r1 == NULL && r2==NULL)
        {
            return true;
        }
        if(r1 == NULL && r2!=NULL || r1!= NULL && r2==NULL )
        {
            return false;
        }
        int left = isIdentical(r1->left,r2->left);
        int right = isIdentical(r1->right,r2->right);
        if(left && right && r1->data == r2->data)
        {
            return true;
        }
        else{
            return false;
        }
    }
};