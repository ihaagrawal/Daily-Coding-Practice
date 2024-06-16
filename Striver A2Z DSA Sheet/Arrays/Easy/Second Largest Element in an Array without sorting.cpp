// Second Largest (EASY)
// https://www.geeksforgeeks.org/problems/second-largest3735/1


//Time: O(n)
//SPace: O(1)
class Solution{
public:	
	// Function returns the second
	// largest elements
	int print2largest(int arr[], int n) {
	    int largest = -1, second = -1;
	    for(int i=0;i<n;i++){
	        if(arr[i] > largest){
	            second = largest;
	            largest = arr[i];
	        }else if(arr[i]<largest && arr[i]>second){
	            second = arr[i];
	        }
	    }
	    return second;
	}
};
