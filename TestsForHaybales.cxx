#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	
	vector <int> ans(n, 0), constraints(n, -1);
	
	for (int i = 0; i < n; i ++) {
		int x;
		cin >> x;
		constraints[x-1] = i;
	}
	
	for (int i = 1; i < n; i ++) {
		if (constraints[i] != -1) {
			ans[i] = ans[constraints[i]]+1000000;
		}
		else {
			ans[i] = ans[i-1]+1;
		}
		if (constraints[i-1] != -1) {
			ans[i] = ans[i-1]+10000000;
		}
	}
	cout << "1100000\n";
	for (int i = 0; i < n; i ++) {
		cout << ans[i] << "\n";
	}
	
	return 0;
}

