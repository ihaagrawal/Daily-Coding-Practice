// Counting Sort (EASY)
// https://www.geeksforgeeks.org/problems/counting-sort/1?ref=header_search

class Solution{
    public:
    string countSort(string arr){
        vector<int> count(256,0);
        int n=arr.length();
        vector<char> sorted(n);
        for(int i=0;i<n;i++) count[arr[i]]++;
        for(int i=1;i<256;i++) count[i]+=count[i-1];
        for(int i=n-1;i>=0;i--){
            sorted[count[arr[i]]-1]=arr[i];
            count[arr[i]]--;
        }
        string result;
        for(auto c:sorted) result+=c;
        return result;
    }
};
