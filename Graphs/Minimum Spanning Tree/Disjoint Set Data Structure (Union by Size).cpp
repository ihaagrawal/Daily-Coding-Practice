#include <iostream>
#include <vector>
using namespace std;

class disjointSet{
  private:
    vector<int> size, parent;

  public:
    disjointSet(int n){
        size.resize(n+1, 1);
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
    
    void unionBySize(int v, int u){
        int pv = findParent(v), pu = findParent(u);
        if(v==u) return;

        if(size[pv]<size[pu]){
            parent[pv] = pu;
            size[pu] += size[pv];
        }else{
            parent[pu] = pv;
            size[pv] += size[pu];
        }
    }
};


int main() {
    
    disjointSet ds(7);
    ds.unionBySize(1, 2);
    ds.unionBySize(2, 3);
    ds.unionBySize(4, 5);
    ds.unionBySize(6, 7);
    ds.unionBySize(5, 6);

    if(ds.findParent(3)==ds.findParent(7)){
        cout << "Same" << endl;
    }else{
        cout << "Not Same" << endl;
    }
    
    ds.unionBySize(3, 7);
    
    if(ds.findParent(3)==ds.findParent(7)){
        cout << "Same" << endl;
    }else{
        cout << "Not Same" << endl;
    }
    
    return 0;
}
