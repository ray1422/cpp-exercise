#include <bits/stdc++.h>
using namespace std;
int _min(int a, int b, int c, int d){return min(a, min(b, min(c, d)));}
bool m[30][30];
bool hasSet[30][30][30][30];
short history[30][30][30][30];
int getCost(bool is_row, int a, int b, int c) {
    int cost = 0;
    if(is_row){
        for(int i = a ; i < b; i++) {
            cost += m[i][c] ? 1 : 0;
        }
    } else {
        for(int i = a ; i < b; i++) {
            cost += m[c][i] ? 1 : 0;
        }
    }
    //cout << "###" << a <<" " << b << endl;
    cost = min(b-a-cost, cost);
    return cost;
}
int dp(int h, int w, int h_min, int w_min) {
    if(h-h_min <= 1 || w - w_min <= 1) return 0;
    if(hasSet[h][w][h_min][w_min]) return history[h][w][h_min][w_min];
    int costL = getCost(true,  h_min, h, w_min) + dp(h, w, h_min, w_min + 1);
    int costR = getCost(true,  h_min, h, w-1) + dp(h, w - 1, h_min, w_min);
    int costT = getCost(false, w_min, w, h_min) + dp(h, w, h_min + 1, w_min);
    int costB = getCost(false, w_min, w, h-1) + dp(h - 1, w, h_min, w_min);
    int cost = _min(costL, costR, costT, costB);
    hasSet[h][w][h_min][w_min] = 1;
    history[h][w][h_min][w_min] = cost;
    return cost;
}
int main() {
    for(int i = 0 ; i <25*25; i++) m[i/25][i%25]=i%2;
    cout << dp(25, 25, 0, 0);
}
