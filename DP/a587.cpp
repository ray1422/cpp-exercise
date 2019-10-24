#include <bits/stdc++.h>
using namespace std;
struct Item {
    int weight = 0;
    int value = 0;
};
Item items[105]; // weight, value
int DP[105][10005];

int dp(int idx, int weight) {
    if(idx == 0 || weight == 0) return 0;
    if(items[idx].weight > weight) return dp(idx-1, weight);
    int a = dp(idx-1, weight - items[idx].weight) + items[idx].value; // 울
    int b = dp(idx-1, weight); // ㄳ울
    return max(a, b);
}
int main() {
    int n, w_max;
    while(cin >> n){
        for(int i = 1 ; i <= n; i++) {
            int w, v;
            cin >> w >> v;
            items[i].weight  = w;
            items[i].value = v;
        }
        cin >> w_max;
        memset(DP, 0, sizeof(DP));
        for(int i = 0 ; i <= n; i++) {
            for(int j = 0; j <= w_max; j++) {
                if(!(i&&j)) { DP[i][j] = 0; continue; }
                if(items[i].weight > j) {DP[i][j] = DP[i-1][j]; continue;}
                int a = DP[i-1][j - items[i].weight] + items[i].value; // 울
                int b = DP[i-1][j]; // ㄳ울
                DP[i][j] = max(a, b);
            }
        }
        cout << DP[n][w_max] << "\n";
    }
}
