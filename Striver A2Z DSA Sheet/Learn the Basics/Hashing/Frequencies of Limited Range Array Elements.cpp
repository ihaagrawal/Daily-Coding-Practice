// Frequencies of Limited Range Array Elements (EASY)
// https://www.geeksforgeeks.org/problems/frequency-of-array-elements-1587115620/0

class Solution{
    public:
    //Function to count the frequency of all elements from 1 to N in the array.
    void frequencyCount(vector<int>& arr,int N, int P)
    { 
        unordered_map<int, int> mp;
        for(int i=0;i<N;i++) mp[arr[i]]++;
        
        for(int i=1;i<=N;i++){
            arr[i-1] = mp[i];
            arr[0] = mp[1];
        }
    }
};
