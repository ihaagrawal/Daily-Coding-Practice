// Disjoint Set Data Structures


#include <iostream>
#include <vector>
using namespace std;

class disjointSet{
  private:
    vector<int> rank, parent;

  public:
    disjointSet(int n){
        rank.resize(n+1, 0);
        parent.resize(n+1);
        for(int i=1;i<=n;i++){
            parent[i]=i;
        }
    }
    
    int findParent(int x){
        if(x==parent[x]) 
            return x;
        
        return parent[x] = findParent(parent[x]);
    }
    
    void unionByRank(int v, int u){
        int pv = findParent(v), pu = findParent(u);
        if(v==u) return;

        if(rank[pv]<rank[pu]){
            parent[pv] = pu;
        }else if(rank[pv]>rank[pu]){
            parent[pu] = pv;
        }else{
            parent[pu] = pv;
            rank[pv]++;
        }
    }
};


int main() {
    
    disjointSet ds(7);
    ds.unionByRank(1, 2);
    ds.unionByRank(2, 3);
    ds.unionByRank(4, 5);
    ds.unionByRank(6, 7);
    ds.unionByRank(5, 6);

    if(ds.findParent(3)==ds.findParent(7)){
        cout << "Same" << endl;
    }else{
        cout << "Not Same" << endl;
    }
    
    ds.unionByRank(3, 7);
    
    if(ds.findParent(3)==ds.findParent(7)){
        cout << "Same" << endl;
    }else{
        cout << "Not Same" << endl;
    }
    
    return 0;
}
