#include <bits/stdc++.h>
using namespace std;

int beautifulTriplets(int d, vector<int> arr) {
    unordered_set<int> s(arr.begin(), arr.end());

    int count = 0;

    for (int x : arr) {
        if (s.count(x + d) && s.count(x + 2 * d)) {
            count++;
        }
    }

    return count;
}

int main() {
    int n, d;
    cin >> n >> d;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << beautifulTriplets(d, arr);

    return 0;
}


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna