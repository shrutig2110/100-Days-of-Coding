class Solution {
public:
    
    bool dfs(vector<int> matchsticks, int target, vector<int> &sides, int idx){
        
        // base case
        if(idx == matchsticks.size()){
//          If all sides are equal
            if(sides[0] == sides[1] && sides[1] == sides[2] && sides[2] == sides[3]){
                return true;
            }
            return false;
        }
        
        for(int i = 0; i < 4; i++){
//          Optimization 1 - Check if the addition is not exceeding the max value of sides
            if (sides[i] + matchsticks[idx] > target){  
//          Do not perfrom recursion for this case
                continue;
            }

//          Optimization 3 - Check if same pattern has been solved before, by checking if same number occured before in               
//          array, if true->no need to solve again
            int j = i - 1;  
            while (j>=0){
                if(sides[j] == sides[i]){
                    break;
                }
//          Same element found, so skip
                j -= 1;
            }
            
            if(j != -1){
                continue;
            }
            
//          Try to add the element to curr array pos to see if it completes one side of square
            sides[i] += matchsticks[idx];
//          Try other possible ways to fill up the array to see if 4 sides can get equal
            if( dfs(matchsticks, target, sides, idx+1) ){
                return true;
            }
//          Backtrack
            sides[i] -= matchsticks[idx];
        }
        
        return false;
    
        
    }
    
    
    bool makesquare(vector<int>& matchsticks) {
        
        if(matchsticks.size() == 0){
            return false;
        }
        
        int sum = 0;
        for(int i = 0; i < matchsticks.size() ; i++){
            sum += matchsticks[i];
        }
        
        int target = sum / 4;
        vector<int> sides(4,0);
//      Optimization 2 - After sorthing the greatest number will be on start of array and hence no solution possible
        sort(matchsticks.begin(), matchsticks.end(), greater<int>()); 
        return dfs(matchsticks, target, sides, 0);
        
    }
};