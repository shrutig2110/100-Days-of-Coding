class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode *> q;
    q.push(root);
    q.push(NULL);

    int lev{0};

    vector<int> cur_lev;

    while (!q.empty())
    {
        TreeNode *cur = q.front();
        q.pop();

        if (cur == NULL)
        {

            if (!q.empty())
                q.push(NULL);

            if (lev % 2 == 0)
            {
                if (cur_lev[0] % 2 == 0)
                    return false;

                for (int i = 1; i < cur_lev.size(); i++)
                {
                    if (cur_lev[i] % 2 == 0 || cur_lev[i] <= cur_lev[i - 1])
                        return false;
                }
            }
            else
            {
                if (cur_lev[0] % 2 != 0)
                    return false;

                for (int i = 1; i < cur_lev.size() ; i++)
                {
                    if (cur_lev[i] % 2 != 0 || cur_lev[i] >= cur_lev[i - 1])
                        return false;
                }
            }

            lev++;
            cur_lev.clear();

            continue;
        }

        cur_lev.push_back(cur->val);

        if (cur->left != NULL)
            q.push(cur->left);

        if (cur->right != NULL)
            q.push(cur->right);
    }

    return true;
    }
};