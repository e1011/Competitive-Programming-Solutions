#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	
	vector <int> ans(n, 0);
	if (k == n) {
		for (int i = 0; i < n; i ++) {
			cout << i+1 << " ";
		}
		cout << "\n";
		return 0;
	}
	
	for (int i = 1; i < k; i ++) {
		ans[i] = i+1;
	}
	ans[0] = n;
	for (int i = 1; i < n; i ++) {
		if (i > k) {
			ans[i] = i;
		}
		if (i == k) {
			ans[i] = 1;
		}
	} 
	
	for (int i = 0; i < n; i ++) {
		cout << ans[i] << " ";
	}
	cout << "\n";
	
	return 0;
}

