#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <chrono>

// Function to perform deterministic partition for QuickSort
int deterministicPartition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int lowIndex = low - 1;

    for (int currentIndex = low; currentIndex < high; currentIndex++) {
        if (arr[currentIndex] <= pivot) {
            lowIndex++;
            std::swap(arr[lowIndex], arr[currentIndex]);
        }
    }

    std::swap(arr[lowIndex + 1], arr[high]);
    return (lowIndex + 1);
}

// Deterministic QuickSort
void deterministicQuickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivot = deterministicPartition(arr, low, high);
        deterministicQuickSort(arr, low, pivot - 1);
        deterministicQuickSort(arr, pivot + 1, high);
    }
}

// Function to perform randomized partition for QuickSort
int randomizedPartition(std::vector<int>& arr, int low, int high) {
    int randomIndex = low + rand() % (high - low + 1);
    std::swap(arr[randomIndex], arr[high]);
    return deterministicPartition(arr, low, high);
}

// Randomized QuickSort
void randomizedQuickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivot = randomizedPartition(arr, low, high);
        randomizedQuickSort(arr, low, pivot - 1);
        randomizedQuickSort(arr, pivot + 1, high);
    }
}

int main() {
    // Seed for random number generation
    srand(static_cast<unsigned int>(time(nullptr)));

    // Generate a random array
    const int size = 10;
    std::vector<int> arr(size);
    for (int& element : arr) {
        element = rand() % 100; // Random values between 0 and 99
    }

    // Print the original array
    std::cout << "Original array: ";
    for (int element : arr) {
        std::cout << element << " ";
    }
    std::cout << "\n";

    // Measure the time for deterministic QuickSort
    auto start = std::chrono::high_resolution_clock::now();
    deterministicQuickSort(arr, 0, size - 1);
    auto end = std::chrono::high_resolution_clock::now();
    auto deterministicTime = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

    // Re-generate the random array for randomized QuickSort
    for (int& element : arr) {
        element = rand() % 100;
    }

    // Print the array before randomized QuickSort
    std::cout << "Array before randomized QuickSort: ";
    for (int element : arr) {
        std::cout << element << " ";
    }
    std::cout << "\n";

    // Measure the time for randomized QuickSort
    start = std::chrono::high_resolution_clock::now();
    randomizedQuickSort(arr, 0, size - 1);
    end = std::chrono::high_resolution_clock::now();
    auto randomizedTime = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

    // Print the array after randomized QuickSort
    std::cout << "Array after randomized QuickSort: ";
    for (int element : arr) {
        std::cout << element << " ";
    }
    std::cout << "\n";

    // Output the results
    std::cout << "Deterministic QuickSort took " << deterministicTime << " milliseconds." << std::endl;
    std::cout << "Randomized QuickSort took " << randomizedTime << " milliseconds." << std::endl;

    return 0;
}
