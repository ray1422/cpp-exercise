#pragma GCC optimize("Ofast, no-stack-protector")
#include <bits/stdc++.h>

//注意輸出大小寫。我真得是幹你老師欸

using namespace std;

void visualize(int cars_in_left, int cars_in_right, int cars[], int total, stack<int> station){
    cout << endl << "====================" << endl;
    for(int i = 0 ; i < cars_in_left; i++) {
        cout << cars[i] << " ";
    }
    cout << " * ";

    for(int i = 0; i < cars_in_right; i++) {

        cout << "#" << total - cars_in_right + i + 1 <<  " ";
    }
    cout << endl;
    while(!station.empty()) {
            cout << " ";
        for(int i = 0 ; i < cars_in_left; i++) {
            cout << "  ";
        }
        cout << station.top() << endl;
        station.pop();
    }
    cout << endl << endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for(int i = 0 ; i < t; i++) {
        int n, counter;
        stack<int> station;
        cin >> n;
        int cars_in_right = 0, cars_in_left = n;
        int cars[n];
        for(int j = 0 ; j < n; j++) {
            int c;
            cin >> c;
            cars[j] = c;
        }
        bool flag = true;
        while(cars_in_right < n) {
            visualize(cars_in_left, cars_in_right, cars, n, station);
            if (!station.empty() && station.top() == (n - cars_in_right)) {
                station.pop();
                cars_in_right++;
            } else if (cars_in_left > 0) {
                station.emplace(cars[cars_in_left-1]);
                cars_in_left--;
            } else {
                flag = false;
                break;
            }
        }
        if (flag) {
            cout << "Yes\n";
        } else {
            cout <<"No\n";
        }
    }
}
