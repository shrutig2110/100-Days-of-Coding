/*
There are n children standing in a line. Each child is assigned a rating value given in the integer array ratings.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
Return the minimum number of candies you need to have to distribute the candies to the children.
*/ 
class Solution {
public:
    int candy(vector<int>& r) {
        int no_of_candies = 0;
        int n = r.size();
//      This vector will help to check how many candies a particular child is having at a time
        vector<int> temp(n,1);
        //      Traversing from left to right and incrementing no of candies  
       for(int i =1;i<n;i++)
       {
           if(r[i]>r[i-1])
           {
               temp[i] = temp[i-1]+1;
           }
       }
        //      Traversing from right to left and incrementing no of candies 
        for(int i = n-2; ~i;i--)
        {
            if(r[i]>r[i+1])
            {
                temp[i] = max(temp[i], temp[i+1]+1);
            }
        }
        
        for(auto x:temp)
        {
            no_of_candies += x;
        }
        return no_of_candies;
        
    }
};