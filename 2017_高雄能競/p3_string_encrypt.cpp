#include <bits/stdc++.h>
using namespace std;

int getIdxFromArray(char c){
    if (c >= '0' && c <= '9') return c - '0' + 26 + 26;
    return c >= 'a' ? c - 'a' + 26 : c - 'A';
}

string dict = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";

void dict_update(char a, char b) {
    //cout << dict << endl;
    for(int i = 0; i < dict.length(); i++) {
        if(dict[i] == a) dict[i] = b;
    }
    //cout << dict << endl << "==========================" << endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long int n, m;
    cin >> n >> m;
    string origin;
    cin >> origin;

    string before, after;
    cin >> before;
    cin >> after;

    for(long long int i = 0; i < m; i++) {
        dict_update(before[i], after[i]);
    }
    string mystr = "";
    for(long long int i = 0 ; i < n; i++) {
        mystr += dict[getIdxFromArray(origin[i])];
    }
    cout << mystr;
}
