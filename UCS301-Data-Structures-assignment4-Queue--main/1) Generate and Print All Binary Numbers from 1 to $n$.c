#include <iostream>
#include <queue>
#include <string>

using namespace std;

void generateBinaryNumbers(int n) {
    queue<string> q;
    q.push("1");

    for (int i = 0; i < n; i++) {
        string curr = q.front();
        q.pop();
        
        cout << curr;
        if (i < n - 1) cout << ", ";

        q.push(curr + "0");
        q.push(curr + "1");
    }
    cout << endl;
}

int main() {
    int n = 2;
    cout << "Input: n = " << n << "\nOutput: ";
    generateBinaryNumbers(n);
    return 0;
}