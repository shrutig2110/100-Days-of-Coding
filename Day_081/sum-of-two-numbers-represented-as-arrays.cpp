/*
PROBLEM: Sum of two numbers represented as arrays
*/ 
class Solution{
public:	
	
	vector<int> findSum(vector<int> &a, vector<int> &b) {
	    int m = a.size(), n = b.size();
        int i = m - 1, j = n - 1;
        int carry = 0;
        int sum = 0;
        vector<int> res;
        while(i >= 0 || j >= 0){
               sum = 0;
               if(i >= 0){ 
                   sum += a[i--];
               }
               if(j >= 0){ 
                   sum += b[j--];
               }
               sum += carry;
               res.push_back(sum % 10);
               carry = sum / 10;         
        }
        if(carry > 0){
            res.push_back(carry);
        }
        reverse(res.begin(), res.end());
        return res;
	}

};