#include <iostream>

void swap(int *array, int i, int j) {
    int t = array[i];
    array[i] = array[j];
    array[j] = t;
}

// make sure element i follows the max-heap rule
void heapify(int *array, int size, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && array[left] > array[largest])
        largest = left;

    if (right < size && array[right] > array[largest])
        largest = right;

    if (largest != i) {
        swap(array, i, largest);
        heapify(array, size, largest);
    }
}

// build the maxheap
void buildHeap(int *array, int size) {
    for (int i = size / 2 - 1; i >= 0; --i) {
        heapify(array, size, i);
    }
}

void heapsort(int *array, int size) {
    if (!array) return ;
    buildHeap(array, size);

    for (int i = size - 1; i > 0; --i) {
        swap(array, 0, i);
        heapify(array, i, 0);
    }
}

void print(int *array, int size) {
    for (int i = 0; i < size; ++i)
        std::cout << array[i] << " ";

    std::cout << "\n";
}

#ifndef UNIT_TESTING
int main() {
    int n = 0;

    std::cout << "Insert the length: ";
    std::cin >> n;

    if (n < 0) {
        std::cout << "Invalid array size.\n";
        return 1;
    }

    int *a = new int[n];
    for (int i = 0; i < n; ++i) {
        std::cout << "Insert element {" << i << "}: "; std::cin >> a[i];
    }

    print(a, n);
    heapsort(a, n);
    print(a, n);

    delete[] a;
    return 0;
}
#endif