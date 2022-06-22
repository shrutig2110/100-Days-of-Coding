/*
PROBLEM - A shop is selling candies at a discount. For every two candies sold, the shop gives a third candy for free. 
*/
class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end());
        int count =0;
        int sum =0;
        if(cost.size() == 1)
        {
            return cost[0];
        }
        if(cost.size() == 2)
        {
            return cost[0]+cost[1];
        }
//      We can buy the two costly candies and we get the third one free so we skip to add the third candy cost as we don't have to pay for every third element after two top costly candies
        for(int i =cost.size(); i>=0;i--)
        {
            if(count%3 ==0)
            {
                count++;
                continue;
            }
            sum += cost[i];
            count++;
        }
        return sum;
    }
};