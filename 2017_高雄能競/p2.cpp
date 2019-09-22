#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int x, y, e, w, s, n;
    cin >> x >> y;
    cin >> w >> s;
    cin >> e >> n;

    if(x >= w && x <= e) {
        //直線往(南 | 北)飛過去
        if(y < s) {
            cout << s - y;
        }
        else {
            cout << y - n;
        }
    } else if (y >= s && y <= n) {
        if(x < w) {
            cout << w - x;
        }
        else {
            cout << x - e;
        }
    }
    else {
        long long int sum = 0;
        if(y < s) { //在巢穴南邊
           sum += s - y;
        }
        else {
            sum += y - n;
        }


        if(x < w) { //在巢穴西邊
            sum += w - x;
        }
        else {
            sum += x - e;
        }
        cout << sum;
    }


    return 0;
}
