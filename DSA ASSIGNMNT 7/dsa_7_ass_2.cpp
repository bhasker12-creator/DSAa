#include <iostream>
using namespace std;

void doubleSelectionSort(int arr[], int n)
{
    int start = 0;
    int end = n - 1;

    while(start < end)
    {
        int minIndex = start;
        int maxIndex = start;

        // Find minimum and maximum
        for(int i = start; i <= end; i++)
        {
            if(arr[i] < arr[minIndex])
                minIndex = i;

            if(arr[i] > arr[maxIndex])
                maxIndex = i;
        }

        // Put minimum at beginning
        swap(arr[start], arr[minIndex]);

        // If maximum was at start, its index changed after swap
        if(maxIndex == start)
            maxIndex = minIndex;

        // Put maximum at end
        swap(arr[end], arr[maxIndex]);

        start++;
        end--;
    }
}

int main()
{
    int arr[100], n;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    doubleSelectionSort(arr, n);

    cout << "Sorted array: ";
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}