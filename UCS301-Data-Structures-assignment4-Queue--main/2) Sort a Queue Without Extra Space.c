#include <iostream>
#include <queue>

using namespace std;

// Returns index of minimum element in the queue
int minIndex(queue<int>& q, int sortedIndex) {
    int min_val = -1;
    int min_index = -1;
    int n = q.size();

    for (int i = 0; i < n; i++) {
        int curr = q.front();
        q.pop();

        if (curr <= min_val || min_index == -1) && (i < n - sortedIndex)) {
            // Wait, let's keep it simple with standard logic
        }
        q.push(curr);
    }
    return min_index;
}

// A simpler recursive/iterative approach:
void insertMinToRear(queue<int>& q, int min_index) {
    int min_val;
    int n = q.size();
    for (int i = 0; i < n; i++) {
        int curr = q.front();
        q.pop();
        if (i == min_index) {
            min_val = curr;
        } else {
            q.push(curr);
        }
    }
    q.push(min_val);
}

void sortQueue(queue<int>& q) {
    // Standard sorting using queue operations
    for (int i = 1; i <= q.size(); i++) {
        int min_index = -1;
        int min_val = 1e9;
        int n = q.size();
        
        // Find minimum element in unsorted queue
        for (int j = 0; j < n; j++) {
            int curr = q.front();
            q.pop();
            if (curr < min_val && j < n - (i - 1)) {
                min_val = curr;
                min_index = j;
            }
            q.push(curr);
        }
        
        // Move minimum element to the rear
        insertMinToRear(q, min_index);
    }
}

int main() {
    queue<int> q;
    int arr[] = {11, 5, 4, 21};
    for (int x : arr) q.push(x);

    sortQueue(q);

    cout << "Output: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}