 #include <bits/stdc++.h>
using namespace std;

int partitionArray(vector<int>& arr, int low, int high) {
    int pivot = arr[low];
    int i = low;
    int j = high;

    while (i < j) {
        // Find first element greater than pivot from left
        while (arr[i] <= pivot && i <= high - 1) {
            i++;
        }

        // Find first element smaller than pivot from right
        while (arr[j] > pivot && j >= low + 1) {
            j--;
        }

        // Swap misplaced elements
        if (i < j) {
            swap(arr[i], arr[j]);
        }
    }

    // Put pivot in its correct sorted position
    swap(arr[low], arr[j]);

    return j; // Partition index
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pIndex = partitionArray(arr, low, high);

        quickSort(arr, low, pIndex - 1);
        quickSort(arr, pIndex + 1, high);
    }
}

int main() {
    vector<int> arr = {4, 6, 2, 5, 7, 9, 1, 3};

    quickSort(arr, 0, arr.size() - 1);

    for (int x : arr) {
        cout << x << " ";
    }

    return 0;
}