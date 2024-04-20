// Min Heap Implementation (MODERATE)
// https://www.naukri.com/code360/problems/min-heap-implementation_5480527?leftPanelTabValue=PROBLEM


class minHeap {
public:
    vector<int> heap;
    int size, capacity;

    // Constructor for the class.
    minHeap(int cap) {
        heap.resize(cap);
        size=0;
        capacity=cap;
    }

    void heapify(int i){
        int smallest=i, left=2*i+1, right=2*i+2;
        
        if(left<size && heap[left]<heap[smallest]) smallest=left;
        if(right<size && heap[right]<heap[smallest]) smallest=right;

        if(smallest!=i){
            swap(heap[i], heap[smallest]);
            heapify(smallest);
        }
    }

    // Implement the function to remove minimum element.
    int extractMinElement() {
        if(size==0) return -1;
        int smallest=heap[0];
        swap(heap[0], heap[size-1]);
        size--;
        heapify(0);
        return smallest;
    }

    // Implement the function to delete an element.
    void deleteElement(int ind) {
        if(ind>=size) return;
        swap(heap[ind], heap[size-1]);
        size--;
        heapify(ind);
    }

    // Implement the function to insert 'val' in the heap.
    void insert(int val) {
        if(size==capacity) return;
        heap[size]=val;
        size++;
        int ind=size-1;
        while(ind>=0){
            int parent=(ind-1)/2;
            if(heap[parent]>heap[ind]){
                swap(heap[parent], heap[ind]);
                ind=parent;
            }else break;
        }
    }
};













