#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int x, y, e, w, s, n;
    cin >> x >> y;
    cin >> w >> s;
    cin >> e >> n;

    if(x >= w && x <= e) {
        //���u��(�n | �_)���L�h
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
        if(y < s) { //�b�_�ޫn��
           sum += s - y;
        }
        else {
            sum += y - n;
        }


        if(x < w) { //�b�_�ަ���
            sum += w - x;
        }
        else {
            sum += x - e;
        }
        cout << sum;
    }


    return 0;
}
