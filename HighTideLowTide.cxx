#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector <int> arr1(n, 0);
	vector <int> arr2(0);
	vector <int> arr3(0);
	
	for (int i = 0; i < n; i ++) {
		cin >> arr1[i];
	}
	
	sort(arr1.begin(), arr1.end());
	for (int i = 0; i < (n+1)/2; i ++) {
		arr2.push_back(arr1[i]);
	}
	reverse(arr2.begin(), arr2.end());
	for (int i = (n+1)/2; i < n; i ++) {
		arr3.push_back(arr1[i]);
	}
	
	for (int i = 0; i < n; i ++) {
		if (i % 2 == 0) {
			cout << arr2[i/2];
		}
		else {
			cout << arr3[(i)/2];
		}
		if (i == n-1) {
			cout << "\n";
		}
		else {
			cout << " ";
		}
	}
	
	
	return 0;
}

