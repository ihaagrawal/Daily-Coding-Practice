// Union of Two Sorted Arrays (MEDIUM)
// https://www.geeksforgeeks.org/problems/union-of-two-sorted-arrays-1587115621/1

//Brute, Better, Optimal
//Time: O(n+m)
//Space: O(n+m)
class Solution{
    public:
    //arr1,arr2 : the arrays
    // n, m: size of arrays
    //Function to return a list containing the union of the two arrays. 
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        vector<int> result;
        int i=0, j=0;
        while(i<n && j<m){
            if(arr1[i] == arr2[j]){
                if (result.empty() || result.back() != arr1[i])
                    result.push_back(arr1[i]);
                i++;
                j++;
            }
            else if(arr1[i] < arr2[j]){
                if (result.empty() || result.back() != arr1[i])
                    result.push_back(arr1[i]);
                i++;
            }else{
                if (result.empty() || result.back() != arr2[j])
                    result.push_back(arr2[j]);
                j++;
            }
        }
        
        while(i<n){
            if(result.empty() || result.back() != arr1[i]) 
                result.push_back(arr1[i]);
            i++;
        }
        while(j<m){
            if(result.empty() || result.back() != arr2[j]) 
                result.push_back(arr2[j]);
            j++;
        }
        
        return result;
    }
};
