class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> pq;
        int n = heights.size();
        int furthest = 0;
        stack<int> st;
        unsigned int sum_heights = 0;
        for (int i=1;i<n;i++){
            int diff = heights[i] - heights[i-1];
            if (diff > 0){
                sum_heights += diff;
                pq.push(diff);
                if (sum_heights > bricks){
                    if (ladders > 0)
                    {
                        ladders--;
                        sum_heights-=pq.top();
                        pq.pop();
                        furthest++;
                    }
                    else
                        break;
                }
            }
            else
                furthest++;
        }
        while (!pq.empty()){
            st.push(pq.top());
            pq.pop();
        }
        while (!st.empty() && bricks >= st.top()){
            bricks-=st.top();
            sum_heights-=st.top();
            st.pop();
            furthest++;
        }
        return furthest;
    }
};