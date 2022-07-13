/*
Find the equilibrium index of an array. An equilibrium index of an array is an index such that the sum of 
elements at lower indexes is equal to the sum of elements at higher indexes. For example, in the following array,
 3 is an equilibrium index, because the sum of elements at lower indexes is equal to the sum of elements at 
 higher indexes.
[-7, 1, 5, 2, -4, 3, 0]
*/
 class solution { 
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long a[], int n) 
    {
        if(n==1)
        {
            return 1;
        }
        if(n==2)
        {
            return -1;
        }
        int prefix_sum[n];
        int lsum = 0;
        int rsum = 0;
        int total_sum = 0;
        prefix_sum[0] = a[0];
        for(int i =0;i<n;i++)
        {
            total_sum += a[i];
        }
        for(int i = 1;i<n;i++)
        {
            prefix_sum[i] = a[i] + prefix_sum[i-1];
        }
        for(int i =1;i<n;i++)
        {
            lsum = prefix_sum[i] - a[i];
            rsum = total_sum - prefix_sum[i];
            if(rsum==lsum)
            {
                return i+1;
            }
        }
        return -1;
    }
};