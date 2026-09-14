#include <iostream>
#include <queue>
#include <stack>

using namespace std;

bool checkSorted(queue<int>& q) {
    stack<int> s;
    int expected = 1;
    int n = q.size();
    queue<int> outputQ;

    while (!q.empty()) {
        int front = q.front();
        q.pop();

        if (front == expected) {
            expected++;
        } else {
            // If stack has elements and top is expected
            while (!s.empty() && s.top() == expected) {
                s.pop();
                expected++;
            }
            if (!s.empty() && s.top() < front) {
                return false;
            }
            s.push(front);
        }
    }

    while (!s.empty() && s.top() == expected) {
        s.pop();
        expected++;
    }

    return (expected - 1 == n);
}

int main() {
    queue<int> q;
    int arr[] = {5, 1, 2, 3, 4};
    for (int x : arr) q.push(x);

    if (checkSorted(q)) cout << "Output: Yes\n";
    else cout << "Output: No\n";

    return 0;
}