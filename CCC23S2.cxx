#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	
	vector <int> arr(n, 0);
	vector <int> ans(n+1, 1000000000);
	for (int i = 0; i < n; i ++) {
		cin >> arr[i];
	}
	
	for (int i = 0; i < n; i ++) {
		int sum1 = 0, sum2 = 0;
		
		for (int j = 0; i-j >= 0; j ++) {
			if (i+j >= n) {
				break;
			}
			sum1 += abs(arr[i-j]-arr[i+j]);
			ans[2*j+1] = min(sum1, ans[2*j+1]);
		}
		
		for (int j = 1; i-j >= 0; j ++) {
			if (i+j > n) {
				break;
			}
			//cout << i << ", " << j << ", " << abs(arr[i-j]-arr[i+j-1]) << "\n";
			sum2 += abs(arr[i-j]-arr[i+j-1]);
			ans[2*j] = min(sum2, ans[2*j]);
		}
	}
	
	for (int i = 1; i <= n; i ++) {
		cout << ans[i];
		if (i == n) {
			cout << "\n";
		}
		else {
			cout << " ";
		}
	}
	
	return 0;
}

