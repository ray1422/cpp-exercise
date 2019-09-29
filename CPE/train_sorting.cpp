#include <bits/stdc++.h>

using namespace std;

int getMaxLength(int* cars, int idx) {
    if (idx == 0) return 1;
    int my_max = 0;
    for(int i = 0; i < idx; i++) {
        int tmp_max = getMaxLength(idx - i);
        my_max = max(my_max, tmp_max);

    }
}

int main() {
	int n, m;

	cin >> n;
	for(int i = 0 ; i < n; i++) {
		cin >> m;
		int cars[m];
		int ls[m*2+10]; // longest seq
		int start_idx = m, end_idx = m;

		for(int j = 0 ; j < m; j++) {
			cin >> cars[j];
		}
		ls[m] = cars[0];
		for(int j = 1; j < m; j++) {

		}
        cout << end_idx - start_idx << endl;
    }
}
