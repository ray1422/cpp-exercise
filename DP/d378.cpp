#include <bits/stdc++.h>
#define loli long long int
using namespace std;
unsigned int g[105][105];
unsigned loli v[105][105];

int main() {
    int w, h, ct=0;
    while(cin >> h >> w) {
        for(int i = 0; i < h; i++)for(int j = 0 ; j < w; j++)cin >> g[i][j];
        memset(v, 0, sizeof(v));
        v[0][0] = g[0][0];
        for(int i = 0 ; i < h; i++) {
            for(int j = 0 ; j < w; j++) {
                loli a, b;
                a = b = LONG_MAX;
                if(i!=0) a = v[i-1][j];
                if(j!=0) b = v[i][j-1];
                if(i!=0||j!=0)v[i][j] = min(a, b) + g[i][j];
            }
        }

        cout << "Case #"<< ++ct <<" :\n";
        cout << v[h-1][w-1] << "\n";


    }



}
