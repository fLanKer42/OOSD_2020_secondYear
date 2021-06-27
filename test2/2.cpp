#include<iostream> 
#include<climits> 

using namespace std; 

void swapper(int *x, int *y); 

class MinHeap { 
	int *arr; 
	int cap; 
	int heapSize; 
public: 

	MinHeap(int cap); 
	void Heapify(int ); 
	int parent(int i) { return (i-1)/2; } 
	int left(int i) { return (2*i + 1); } 
	int right(int i) { return (2*i + 2); } 
	int extract(); 
	void dec(int i, int new_val); 
	int getMin() { return arr[0]; } 
	void deleteKey(int i); 
	void insertKey(int k); 
}; 

MinHeap::MinHeap(int cap) { 
	heapSize = 0; 
	cap = cap; 
	arr = new int[cap]; 
} 
void MinHeap::insertKey(int k) { 
	if (heapSize == cap) { 
		cout << "\nCould not insertKey\n"; 
		return; 
	} 
	heapSize++; 
	int i = heapSize - 1; 
	arr[i] = k; 
	while (i != 0 && arr[parent(i)] > arr[i]) 
	{ 
	swapper(&arr[i], &arr[parent(i)]); 
	i = parent(i); 
	} 
} 
void MinHeap::dec(int i, int new_val) { 
	arr[i] = new_val; 
	while (i != 0 && arr[parent(i)] > arr[i]) 
	{ 
	swapper(&arr[i], &arr[parent(i)]); 
	i = parent(i); 
	} 
} 
int MinHeap::extract() { 
	if (heapSize <= 0) 
		return INT_MAX; 
	if (heapSize == 1) { 
		heapSize--; 
		return arr[0]; 
	} 

	int root = arr[0]; 
	arr[0] = arr[heapSize-1]; 
	heapSize--; 
	Heapify(0); 

	return root; 
} 

void MinHeap::deleteKey(int i) { 
	dec(i, INT_MIN); 
	extract(); 
} 


void MinHeap:: Heapify(int i) { 
	int l = left(i); 
	int r = right(i); 
	int smallest = i; 
	if (l < heapSize && arr[l] < arr[i]) 
		smallest = l; 
	if (r < heapSize && arr[r] < arr[smallest]) 
		smallest = r; 
	if (smallest != i) 
	{ 
		swapper(&arr[i], &arr[smallest]); 
		Heapify(smallest); 
	} 
} 

void swapper(int *x, int *y) { 
	int temp = *x; 
	*x = *y; 
	*y = temp; 
} 

int main() 
{ 
    MinHeap hepe(11); 
    hepe.insertKey(3); 
    hepe.insertKey(2); 
    hepe.deleteKey(1); 
    hepe.insertKey(15); 
    hepe.insertKey(5); 
    hepe.insertKey(4); 
    hepe.insertKey(45); 
    return 0; 
}
