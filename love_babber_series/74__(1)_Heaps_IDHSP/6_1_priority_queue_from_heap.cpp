#include<iostream>
using namespace std;

class PriorityQueue {
public:
    int arr[100];
    int size;

    PriorityQueue() {
        arr[0] = -1;
        size = 0;
    }

    void insert(int val) {
        size = size + 1;
        int index = size;
        arr[index] = val;

        while (index > 1) {
            int parent = index / 2;

            if (arr[parent] < arr[index]) {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else {
                return;
            }
        }
    }

    int extractMax() {
        if (size == 0) {
            cout << "Priority Queue is empty." << endl;
            return -1; // Assuming -1 as a placeholder for an invalid value.
        }

        int maxVal = arr[1];
        swap(arr[1], arr[size]);
        size--;

        heapify(1);

        return maxVal;
    }

    void heapify(int i) {
        int largest = i;
        int leftChild = 2 * i;
        int rightChild = 2 * i + 1;

        if (leftChild <= size && arr[leftChild] > arr[largest]) {
            largest = leftChild;
        }

        if (rightChild <= size && arr[rightChild] > arr[largest]) {
            largest = rightChild;
        }

        if (largest != i) {
            swap(arr[i], arr[largest]);
            heapify(largest);
        }
    }

    void print() {
        for (int i = 1; i <= size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    PriorityQueue pq;

    pq.insert(60);
    pq.insert(30);
    pq.insert(50);
    pq.insert(20);
    pq.insert(70);
    pq.insert(40);
    pq.insert(55);

    cout << "Priority Queue: ";
    pq.print();

    int maxVal = pq.extractMax();
    cout << "Extracted Max Value: " << maxVal << endl;

    cout << "Priority Queue after extraction: ";
    pq.print();

    return 0;
}
