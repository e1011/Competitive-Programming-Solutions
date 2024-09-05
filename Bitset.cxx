#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m, ans=0;
	cin >> n >> m;
	
	vector <bitset <50000>> arr(n, bitset <50000>(0));
	vector <vector <int>> arr2(n, vector <int> (n, 0));
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < m; j ++) {
			int x;
			cin >> x;
			arr[i][j] = x;
		}
	}
	
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < n; j ++) {
			arr2[i][j] = (arr[i]^arr[j]).count();
		}
	}
	
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < n; j ++) {
			for (int k = 0; k < n; k ++) {
				if (i != j && i != k && j != k && arr2[i][j] == arr2[j][k] && arr2[i][j] == arr2[i][k]) {
					ans += 1;
					//cout << i << ", " << j << ", " << k << "\n";
				}
			}
		}
	}
	
	cout << ans/6 << "\n";
	
	return 0;
}

//https://dmoj.ca/problem/uhcc1p5
