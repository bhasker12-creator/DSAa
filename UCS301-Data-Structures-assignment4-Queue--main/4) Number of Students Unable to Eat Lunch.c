#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int countStudents(vector<int>& students, vector<int>& sandwiches) {
    queue<int> q;
    stack<int> s;

    for (int student : students) q.push(student);
    // Push sandwiches in reverse so top of stack is at the end of vector
    for (int i = sandwiches.size() - 1; i >= 0; i--) {
        s.push(sandwiches[i]);
    }

    int rotations = 0;
    while (!q.empty() && rotations < q.size()) {
        if (q.front() == s.top()) {
            q.pop();
            s.pop();
            rotations = 0; // reset rotation count
        } else {
            int front = q.front();
            q.pop();
            q.push(front);
            rotations++;
        }
    }
    return q.size();
}

int main() {
    vector<int> students = {1, 1, 0, 0};
    vector<int> sandwiches = {0, 1, 0, 1};

    cout << "Output: " << countStudents(students, sandwiches) << endl;
    return 0;
}