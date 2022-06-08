class Solution 
{
    private:
        bool knows(int a, int b, vector<vector<int> >& M )
        {
            if(M[a][b] == 1)
            {
                return true;
            }
            return false;
        }
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int> s;
        // Push all elements in stack i.e no of people
        for (int i = 0; i<n; i++)
        {
            s.push(i);
        }
        while(s.size()!=1)
        {
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            if(knows(a,b,M))
            {
                s.push(b);
            }
            else{
                s.push(a);
            }
        }
        int potential_celeb = s.top();
        // Check condition for being a celeb i.e all row elements zero and 
        bool rowCheck = false;
        int rowCount=0;
        for(int i =0;i<n;i++)
        {
            if(M[potential_celeb][i] == 0)
            {
                rowCount++;
            }
        }
        if(rowCount == n)
        {
            rowCheck=true;
        }
        bool colCheck = false;
        int colCount = 0;
        for(int i =0;i<n;i++)
        {
            if(M[i][potential_celeb] == 1)
            {
                colCount++;
            }
        }
        if(colCount == n-1)
        {
            colCheck=true;
        }
        if(rowCheck && colCheck)
        {
            return potential_celeb;
        }
        return -1;
    }
};