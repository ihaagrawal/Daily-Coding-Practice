// Implement a priority queue (MODERATE)
// https://www.naukri.com/code360/problems/implement-a-priority-queue-_1743878?leftPanelTabValue=PROBLEM

void heapify(vector<int>& heap, int i){
    int n=heap.size();
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;

    if(left<n && heap[left]>heap[largest]) largest=left;
    if(right<n && heap[right]>heap[largest]) largest=right;

    if(largest!=i){
        swap(heap[i], heap[largest]);
        heapify(heap, largest);
    } 
}

int pop(vector<int> &heap)
{
    int n=heap.size();
    if(n==0) return -1;
    swap(heap[0], heap[n-1]);
    int last=heap[n-1];
    heap.pop_back();
    n--;
    heapify(heap, 0);
    return last;
}

// Code Snippet of the push function: 
//
//     void push(vector<int> &heap, int x)
//     {
//           heap.push_back(x);
//
//            // Posistion of the current inserted element.
//            int pos=heap.size()-1;
//
//            // Shifting the element up until it reaches the top most node if it is larger than its parent.
//            while(pos>0)
//            {
//                int parent = (pos-1)/2;
//                if(heap[pos] > heap[parent])
//                {
//                    swap(heap[parent],heap[pos]);
//                    pos=parent;
//               }
//              else
//              {
//                  // As parent is larger the element now is in its correct position. 
//                  break;
//              }
//          }
//      }
