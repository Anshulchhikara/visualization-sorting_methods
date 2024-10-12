#include <iostream>
using namespace std;

int partition(int arr[], int low, int high) {  // Corrected: removed the extra comma
    int pivot = arr[high];  // Pivot element
    int i = (low - 1);  // Index of the smaller element

    // Loop to rearrange elements based on pivot
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);  // Swap if the element is smaller than the pivot
        }
    }
    swap(arr[i + 1], arr[high]);  // Move pivot to the correct position
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);  // Get the pivot element

        // Recursively sort the subarrays before and after the pivot
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = { 10, 7, 8, 9, 1, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);
    
    quickSort(arr, 0, n - 1);  // Call the quickSort function
    cout << "Sorted array: \n";
    printArray(arr, n);  // Print the sorted array

    return 0;
}
