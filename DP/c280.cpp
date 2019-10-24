#include <bits/stdc++.h>
#define loli long long int
using namespace std;
loli fib[82];
int main(){
    fib[0] = 0;
    fib[1] = 1;
    fib[2] = 1;
    for(int i = 3; i < 82; i++) {
        fib[i] = fib[i-2] + fib[i-1];
    }
    int n;
    cin >> n;
    cout << fib[n];


}
