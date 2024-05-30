// Minimum Platforms (MEDIUM)
// https://www.geeksforgeeks.org/problems/minimum-platforms-1587115620/1

//we are sorting both the arrays arr and dep
//we check the first index of arr
//if the arr[0] is less than the dep[0] then we need an extra platform
//if this is the case then we move forward in arr
//we check arr[1], if it is greater than dep[0]
//then we reduce the platform which we had and we move forward in dep
//we store the max platforms we'll need

class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
        //sort arr and dep in ascending order
    	sort(arr, arr+n);
    	sort(dep, dep+n);
    	
    	int i=0, j=0, count=0, result=1;
    	while(i<n && j<n){
    	    
    	    //check if the arrival time is less than or equal to departure time
    	    //increase the platform and move forward in arr
    	    if(arr[i] <= dep[j]){
    	        count++;
    	        i++;
    	    }
    	    
    	    //check if arrival time is greater than departure time
    	    //decrease the platform and move forward in dep
    	    else if(arr[i] > dep[j]){
    	        count--;
    	        j++;
    	    }
    	    
    	    //store the max number of platforms
    	    result = max(result, count);
    	}
    	return result;
    }
};
