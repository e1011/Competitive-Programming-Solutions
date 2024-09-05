#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	
	int ans = n-1;
	vector <int> arr(n, 0);
	vector <int> costs(n, 0);
	
	for (int i = 0; i < n; i ++) {
		cin >> arr[i];
		if (i != 0) {
			costs[i] = max(0, arr[i]-arr[i-1]);
			ans += costs[i];
		}
	}
	
	for (int i = 0; i < n; i ++) {
		if (costs[i] > (n-i-1)) {
			ans -= costs[i];
			ans += n-i-1;
		}
	}
	
	
	cout << ans << "\n";
	1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
	
	return 0;
}

