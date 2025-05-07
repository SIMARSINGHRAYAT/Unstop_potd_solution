#include <iostream>
#include <vector>
#include <tuple>
#include <sstream>
#include <algorithm>

using namespace std;

// Function to calculate trapped energy and tallest column
tuple<long long, int> trapEnergy(vector<int>& pillars, int D) {
    int N = pillars.size();
    if (N == 0) return make_tuple(0LL, 0);

    int left = 0, right = N - 1;
    int left_max = 0, right_max = 0;
    long long total_trapped = 0;
    int max_height = 0;

    while (left <= right) {
        if (pillars[left] <= pillars[right]) {
            if (pillars[left] >= left_max) {
                left_max = pillars[left];
            } else {
                int water = left_max - pillars[left];
                total_trapped += water;
                max_height = max(max_height, water);
                if (water >= D) {
                    return make_tuple(-1LL, 0); // Immediate overload
                }
            }
            ++left;
        } else {
            if (pillars[right] >= right_max) {
                right_max = pillars[right];
            } else {
                int water = right_max - pillars[right];
                total_trapped += water;
                max_height = max(max_height, water);
                if (water >= D) {
                    return make_tuple(-1LL, 0); // Immediate overload
                }
            }
            --right;
        }
    }

    return make_tuple(total_trapped, max_height);
}

int main() {
    string line;
    vector<int> data;

    // Read all input at once
    while (getline(cin, line)) {
        istringstream iss(line);
        int val;
        while (iss >> val) {
            data.push_back(val);
        }
    }

    if (data.empty()) {
        cout << "0\n0\n";
        return 0;
    }

    int N = data[0];
    if (N < 1 || N > 1e6) {
        cout << "0\n0\n";
        return 0;
    }

    if (data.size() < static_cast<size_t>(N + 1)) {
        cout << "0\n0\n";
        return 0;
    }

    vector<int> pillars(data.begin() + 1, data.begin() + 1 + N);
    int D = data[N + 1];

    long long total;
    int max_height;
    tie(total, max_height) = trapEnergy(pillars, D);

    if (total == -1) {
        cout << "-1" << endl; // Only print one line
    } else {
        cout << total << endl;
        cout << max_height << endl;
    }

    return 0;
}