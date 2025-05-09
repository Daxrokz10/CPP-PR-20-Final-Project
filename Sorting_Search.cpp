#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& arr, int left, int mid, int right) {
    vector<int> temp;
    int i = left, j = mid + 1;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i++]);
        } else {
            temp.push_back(arr[j++]);
        }
    }

    while (i <= mid) temp.push_back(arr[i++]);
    while (j <= right) temp.push_back(arr[j++]);

    for (int k = left; k <= right; ++k) {
        arr[k] = temp[k - left];
    }
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left >= right) return;
    
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; ++j) {
        if (arr[j] < pivot) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int binarySearch(const vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) return mid; 
        else if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }

    return -1; 
}

int main() {
    vector<int> arr = {3, 5, 2, 4, 1};

    cout << "Original Array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;

    // Quick Sort
    vector<int> quickSortedArr = arr;
    quickSort(quickSortedArr, 0, quickSortedArr.size() - 1);
    cout << "Array after Quick Sort: ";
    for (int num : quickSortedArr) cout << num << " ";
    cout << endl;

    // Merge Sort
    vector<int> mergeSortedArr = arr;
    mergeSort(mergeSortedArr, 0, mergeSortedArr.size() - 1);
    cout << "Array after Merge Sort: ";
    for (int num : mergeSortedArr) cout << num << " ";
    cout << endl;

    // Binary Search
    int target = 4;
    cout << "Binary Search for " << target << ": ";
    cout << (binarySearch(mergeSortedArr, target) != -1 ? "Found" : "Not Found") << endl;

    return 0;
}