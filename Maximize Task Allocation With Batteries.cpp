#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maximizeTasks(vector<int>& energy, vector<int>& power) {
    sort(energy.begin(), energy.end());
    sort(power.begin(), power.end());

    int taskCount = 0, batteryIndex = 0;

    for (int i = 0; i < energy.size(); i++) {
        while (batteryIndex < power.size() && power[batteryIndex] < energy[i]) {
            batteryIndex++; // Skip incompatible batteries
        }
        if (batteryIndex < power.size()) {
            taskCount++;
            batteryIndex++; // Use battery for the task
        }
    }
    return taskCount;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> energy(n), power(m);

    for (int i = 0; i < n; i++) cin >> energy[i];
    for (int i = 0; i < m; i++) cin >> power[i];

    cout << maximizeTasks(energy, power) << endl;
    return 0;
}
