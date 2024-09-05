#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, k, counter = 1;
	cin >> n >> k;
	
	vector <vector <int>> ans(n, vector <int> (n, 0));
	for (int i = n*n; i > (n*n-n); i --) {
		if (i > n*n-k) {
			ans[n*n-i][n*n-i] = i;
		}
		else {
			ans[0][n*n-i] = i;
		}
	}
	
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < n; j ++) {
			if (ans[i][j] == 0) {
				ans[i][j] = counter;
				counter += 1;
			}
			
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}
	
	return 0;
}

