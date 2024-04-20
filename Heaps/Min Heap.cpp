// Min Heap (MODERATE)
// https://www.naukri.com/code360/problems/min-heap_4691801?topList=striver-sde-sheet-problems&leftPanelTabValue=PROBLEM

#include <bits/stdc++.h> 

void insert(vector<int>& pq, int element){
    pq.push_back(element);
    int n=pq.size();
    int child=n-1;
    while(child>=0){
        int parent=(child-1)/2;
        if(pq[parent]>pq[child]) swap(pq[parent], pq[child]);
        else break;
        child=parent;
    }
}

void heapify(vector<int>& pq, int i){
    int n=pq.size();
    int smallest=i, left=2*i+1, right=2*i+2;
    
    if(left<n && pq[left]<pq[smallest]) smallest=left;
    if(right<n && pq[right]<pq[smallest]) smallest=right;

    if(smallest!=i){
        swap(pq[smallest], pq[i]);
        heapify(pq, smallest);
    }

}

int deleteFromHeap(vector<int>& pq){
    int ans=pq[0], n=pq.size();
    swap(pq[0], pq[n-1]);
    pq.pop_back();
    heapify(pq, 0);
    return ans;
}

vector<int> minHeap(int n, vector<vector<int>>& q) {
    vector<int> pq;
    vector<int> ans;
    for(int i=0;i<n;i++){
        if(q[i][0]==0) insert(pq, q[i][1]);
        else{
            int minelement=deleteFromHeap(pq);
            ans.push_back(minelement);
        }
    }
    return ans;
}
