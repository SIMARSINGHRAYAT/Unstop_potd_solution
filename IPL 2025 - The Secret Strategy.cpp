#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <sstream>

using namespace std;

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}

string encryptMessage(const vector<int>& nums) {
    int n = nums.size();
    vector<string> result(n);
    
    for (int i = 0; i < n; i++) {
        if (isPrime(nums[i])) {
            result[i] = "*";
        } else {
            result[i] = to_string(nums[i]);
        }
    }
    
    ostringstream out;
    for (int i = 0; i < n; i++) {
        out << result[i];
        if (i < n - 1) {
            out << " ";
        }
    }
    
    return out.str();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<int> arr(N);

    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    string result = encryptMessage(arr);
    cout << result << "\n";

    return 0;
}