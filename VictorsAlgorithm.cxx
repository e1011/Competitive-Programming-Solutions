#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	
	vector <int> arr(n, 0);
	vector <long long> prefix(n, 0);
	vector <long long> suffix(n, 0);
	for (int i = 0; i < n; i ++) {
		cin >> arr[i];
	}
	
	int max;
	for (int i = 0; i < n; i ++) {
		if (i == 0 || arr[i] > max) {
			max = arr[i];
		}
		else {
			prefix[i] += max-arr[i];
		}
		if (i != 0) {
			prefix[i] += prefix[i-1];
		}
	}
	for (int i = n-1; i >= 0; i --) {
		if (i == n-1 || arr[i] > max) {
			max = arr[i];
		}
		else {
			suffix[i] += max-arr[i];
		}
		if (i != n-1) {
			suffix[i] += suffix[i+1];
		}
	}
	
	long long ans = min(suffix[0], prefix[n-1]);
	for (int i = 0; i < n-1; i ++) {
		ans = min(ans, prefix[i]+suffix[i+1]);
	}
	cout << ans << "\n";
	
	
	return 0;
}

