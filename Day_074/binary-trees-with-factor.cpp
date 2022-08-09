/*
PROBLEM: Binary Trees with Factor
*/ 
class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
       int n = arr.size();
       sort(arr.begin(),arr.end());
       unordered_map<int,long>trees;
//     Store number of binary trees that can be made out of an element from array in the map
//     At least n binary trees can be made out of given array of single node
       for(int i =0;i<n;i++)
       {
          trees[arr[i]]++;
       }
       long long int count = 0;
       
       for(int i =1;i<n;i++)
       {
         for(int j =0;j<i;j++)
         {
//           Check if the element at ith position(4) is divisible to element at jth position(2) 
//           and if the other factor(4/2 = 2) is also present in the given array
             if(arr[i]%arr[j]==0 && trees[arr[i]/arr[j]]>0)
             {
//               Add the total no. of new ways possible to the map
// Number of ways in which jth element can be used to form binary tree(2) * no. of ways in which ith element can be used to form binary tree(4) + the existing number of ways to form a binary tree from ith element(4) 
                 trees[arr[i]] += trees[arr[j]]*trees[arr[i]/arr[j]];
             }
         }
       }
        for(auto x: trees)
        {
            count += x.second;
        }
       return count% 1000000007;
    }
};