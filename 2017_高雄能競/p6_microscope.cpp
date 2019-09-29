#include <bits/stdc++.h>

using namespace std;
int sums[210000];
int idx_of_sums[200000];
vector<long long int> elements;
int main() {
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 0 ; i < n; i++) {
        cin >> sums[i];
    }
    long long int ans;
    for(int i = 0; i <= k+1; i++) {
        long long int sum = 0;
        int idx = i;
        // line i with (i + k + 1) elements before line k+1 (included)
        // and line i with (k-(n - i - 1)) elements from line n-k-1 to n-1;
        // in line n-1 to n-k, elements start with id n-k-1 to n-k

        while (idx < n-k-1) {
            sum += sums[idx];
            idx += 2 * k + 1;
        }

        if(idx == n-1) {
            sum += sums[idx];
            cout << sum << endl;
            return 0;
        } else if((n - k - 1) - idx >= 0) {
            sum += sums[idx];
            cout << sum << endl;
            return 0;
        }
        // else continue
    }
    cout << "SEARCH FAILED!";

}
