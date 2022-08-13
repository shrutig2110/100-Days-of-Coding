  
  int smallestSubWithSum(int arr[], int n, int x)
    {
        int i = 0,j =0, sum = 0;
        int min_size = INT_MAX;
        while(j<n)
        {
            // Add numbers until sum becomes greater than x
             while (sum <= x && j<n)
               sum += arr[j++];

            // If current sum becomes greater than x.
            while (sum > x && i < n) {
                // Update minimum length 
                min_size=min(min_size, j-i);
    
                // remove starting elements
                sum -= arr[i++];
            }
        }
            return min_size;
    }