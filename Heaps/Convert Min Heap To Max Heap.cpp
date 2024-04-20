// Convert Min Heap To Max Heap (MODERATE)
// https://naukri.com/code360/problems/convert-min-heap-to-max-heap_1381084?leftPanelTabValue=PROBLEM

void heapify(vector<int>& arr, int i, int n){
	int largest=i, left=2*i+1, right=2*i+2;

	if(left<n && arr[left]>arr[largest]) largest=left;
	if(right<n && arr[right]>arr[largest]) largest=right;

	if(largest!=i){
		swap(arr[i], arr[largest]);
		heapify(arr, largest, n);
	}
}

vector<int>MinToMaxHeap(int n, vector<int>&arr)
{
	for(int i=n-1;i>=0;i--) heapify(arr, i, n);
	return arr;
}
