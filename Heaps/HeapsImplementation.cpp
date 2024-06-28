#include<iostream>
#include<vector>

using namespace std;

class minHeap {
    vector<int> heap;

    void heapify(int i) {
        int minIdx = i;
        int leftChild = 2 * i + 1;
        int rightChild = 2 * i + 2;

        if(leftChild < heap.size() && heap[minIdx] > heap[leftChild])
            minIdx = leftChild;

        if(rightChild < heap.size() && heap[minIdx] > heap[rightChild])
            minIdx = rightChild;

        if(minIdx != i) {
            swap(heap[i], heap[minIdx]);
            heapify(minIdx);
        }
    }

    public:
        // Time: O(logn)
        void push(int val) {
            heap.push_back(val);

            int childIndex = heap.size()-1;
            int parentIndex = childIndex % 2 ? childIndex / 2 : childIndex / 2 - 1;

            while (childIndex > 0 && heap[parentIndex] > heap[childIndex])
            {
                swap(heap[parentIndex], heap[childIndex]);
                childIndex = parentIndex;
                parentIndex = childIndex % 2 ? childIndex / 2 : childIndex / 2 - 1;
            }            
        }

        // O(logn)
        void pop() {
            swap(heap[0], heap[heap.size()-1]);
            heap.pop_back();
            heapify(0);
        }

        int top() {
            return heap[0];
        }

        int size() {
            return heap.size();
        }

        bool empty() {
            return heap.empty();
        }
};

int main() {

	minHeap m;

	m.push(9);
	m.push(7);
	m.push(8);
	m.push(5);
	m.push(4);
	m.push(6);
	m.push(3);
	m.push(2);
	m.push(1);

	cout << m.size() << endl;

	while (!m.empty()) {
		cout << m.top() << " ";
		m.pop();
	}

	cout << endl;

	cout << m.size() << endl;

	return 0;
}