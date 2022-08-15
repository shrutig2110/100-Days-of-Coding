	
class Solution{	
	public:
	long long countTriplets(long long arr[], int n, long long sum)
	{
	    sort(arr,arr+n);
	   int count = 0;
	   int j = 0,k=0;
	   for(int i =0;i<n-2;i++)
	   {
	       j=i+1; k =n-1;
	       while(j<k)
	       {
	           if(arr[i]+arr[j]+arr[k]>=sum)
	           {
	               k--;
	           }
	           else
	           {
	               count += (k-j);
	               j++;
	           }
	       }
	   }
	   return count;
	}
		 

};