#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, ans=0;
	cin >> n;
	
	vector <int> arr1(n, 0), arr2(n, 0);
	for (int i = 0; i < n; i ++) {
		cin >> arr1[i];
		if (arr1[i] == 1) {
			ans += 3;
		}
	}
	for (int i = 0; i < n; i ++) {
		cin >> arr2[i];
		if (arr2[i] == 1) {
			ans += 3;
		}
	}
	
	for (int i = 0; i < n; i += 2) {
		if (arr1[i] == 1 && arr2[i] == 1) {
			ans -= 2;
		}
	} 
	
	for (int i = 1; i < n; i ++) {
		if (arr1[i] == 1 && arr1[i-1] == 1) {
			ans -= 2;
		}
		if (arr2[i] == 1 && arr2[i-1] == 1) {
			ans -= 2;
		}
	}
	
	cout << ans << "\n";
	
	return 0;
}

