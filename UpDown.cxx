#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t;
	cin >> t;
	
	for (int _ = 0; _ < t; _++) {
		int n, works1=1, works2=1;
		cin >> n;
		vector <int> arr(n, 0);
		for (int i = 0; i < n; i ++) {
			cin >> arr[i];
		}
		vector <int> arr2 = arr;
		
		for (int i = 0; i < n; i ++) {
			if (arr[i] == 0) {
				if (i % 2 == 0) {
					arr[i] = -1000000001;
				}
				else {
					arr[i] = 1000000001;
				}
			}
		}
		for (int i = 0; i < n; i ++) {
			if (arr2[i] == 0) {
				if (i % 2 == 1) {
					arr2[i] = -1000000001;
				}
				else {
					arr2[i] = 1000000001;
				}
			}
		}
		
		for (int i = 1; i < n; i ++) {
			if (i % 2 == 1 && arr[i] <= arr[i-1]) {
				works1 = false;
			}
			if (i % 2 == 0 && arr[i] >= arr[i-1]) {
				works1 = false;
			}
			if (i % 2 == 1 && arr2[i] >= arr2[i-1]) {
				works2 = false;
			}
			if (i % 2 == 0 && arr2[i] <= arr2[i-1]) {
				works2 = false;
			}
		}
		
		if (works1 || works2) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
		
	}
	
	return 0;

}
