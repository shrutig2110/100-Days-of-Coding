class Solution{
    public:
     bool seatingarrangement(int n, int m, vector<int> &seats){
        int count = 0;
        vector<int> temp;
        temp = seats;
        for(int i = 0; i < n; i++)
        {   
            if(temp[i] == 0)
            {
                if(temp[i+1] == 0&& i==0 || temp[i-1]==0 && i==n-1 ||temp[i+1] == 0 && temp[i-1] == 0)
                {
                    count++;
                    temp[i] = 1;
                }
            }
        }
        if(count == m){
            return true;
        }
        return false;
        
}