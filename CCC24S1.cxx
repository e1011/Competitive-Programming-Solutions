#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, ans=0;
	cin >> n;
	vector <int> arr(2*n, 0);
	for (int i = 0; i < n; i ++) {
		cin >> arr[i];
		arr[i+n] = arr[i];
	}
	
	for (int i = 0; i < n; i ++) {
		if (arr[i] == arr[i+n/2]) {
			ans += 1;
		}
	}
	
	cout << ans << "\n";
	
	return 0;
}

