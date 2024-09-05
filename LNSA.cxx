#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, ans=0;
	cin >> n;
	
	vector <int> arr(n, 0);
	for (int i = 0; i < n; i ++) {
		cin >> arr[i];
	}
	
	int counter = 1;
	for (int i = 1; i < n; i ++) {
		if (arr[i] <= arr[i-1]) {
			counter += 1;
		}
		else {
			counter = 1;
		}
		ans = max(ans, counter);
	}
	
	cout << ans << "\n";
	
	return 0;
}

