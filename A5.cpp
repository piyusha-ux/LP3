#include <iostream>
#include <vector>

// Function to partition the array into two sub-arrays.
// Elements less than the pivot are on the left, and elements greater are on the right.
int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // Choose the last element as the pivot
    int i = (low - 1); // Index of the smaller element

    for (int j = low; j < high; j++) {
        // If the current element is less than or equal to the pivot
        if (arr[j] <= pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }

    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}

// The main QuickSort function
void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        // Partition the array into two sub-arrays and get the pivot position
        int pivot = partition(arr, low, high);

        // Recursively sort the sub-arrays
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

int main() {
    std::vector<int> arr = {12, 11, 13, 5, 6, 7};

    int arrSize = arr.size();

    std::cout << "Original array: ";
    for (int element : arr) {
        std::cout << element << " ";
    }

    quickSort(arr, 0, arrSize - 1);

    std::cout << "\nSorted array: ";
    for (int element : arr) {
        std::cout << element << " ";
    }

    return 0;
}
