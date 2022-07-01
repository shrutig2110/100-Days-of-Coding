/*
PROBLEM: You are assigned to put some amount of boxes onto one truck. You are given a 2D array boxTypes, where boxTypes[i] = [numberOfBoxesi, numberOfUnitsPerBoxi]:

numberOfBoxes(i) is the number of boxes of type i.
numberOfUnitsPerBox(i) is the number of units in each box of the type i.
You are also given an integer truckSize, which is the maximum number of boxes that can be put on the truck. You can choose any boxes to put on the truck as long as the number of boxes does not exceed truckSize.

Return the maximum total number of units that can be put on the truck.
*/ 
class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int max_num_of_units = 0;
        int curr_box_size = 0;
//      Sorted the boxes in decreasing order of units with lambda function
        sort(boxTypes.begin(),boxTypes.end(),[]( const vector<int>& v1,
               const vector<int>& v2 )
             {
                 return v1[1] > v2[1];
             });
        
        for(int i =0;i<boxTypes.size();i++)
        {
//          Adding the box acc to the remaining space on truck
            curr_box_size = min(truckSize, boxTypes[i][0]);
//          Multiplying the no. of box added to no. of units
            max_num_of_units += curr_box_size* boxTypes[i][1];
//          update the curr size by subtracting the newly added box size
            truckSize -= curr_box_size;
//          If truck is full
            if(truckSize <=0)
            {
                break;
            }
        }
        return max_num_of_units;
        
    }
};