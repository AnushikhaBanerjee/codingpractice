#include <bits/stdc++.h>
using namespace std;

int nonDivisibleSubset(int k, vector<int> S) {
    vector<int> freq(k, 0);

    // Count remainders
    for (int num : S) {
        freq[num % k]++;
    }

    // Start with at most one element divisible by k
    int result = min(freq[0], 1);

    // Handle pairs of remainders
    for (int i = 1; i <= k / 2; i++) {
        if (i != k - i) {
            result += max(freq[i], freq[k - i]);
        } else {
            // Special case: when remainder is exactly half of k
            result += 1;
        }
    }

    return result;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> S(n);
    for (int i = 0; i < n; i++) {
        cin >> S[i];
    }
    cout << nonDivisibleSubset(k, S) << endl;
    return 0;
}


// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna