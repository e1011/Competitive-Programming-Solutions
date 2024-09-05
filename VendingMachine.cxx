#include <iostream>
#include <vector>

using namespace std;

long long exp(long long x, long long y) {
	long long res = 1; 
	while (y) {
		if (y & 1) {
			res *= x;
		}
		x *= x;
		y >>= 1;
	}
	return res;
}

int main() {
	int n, k=0;
	cin >> n;
	
	for (int i = 0; i < n; i ++) {
		if (exp(2, i) >= n) {
			k = i;
			break;
		}
	}
	
	vector <int> ans(k, 0);
	vector <int> arr1(n, 0);
	for (int i = 0; i < n; i ++) {
		arr1[i] = i;
	}
	
	for (int i = k-1; i >= 0; i --) {
		cout << "$ " << arr1.size() << " ";
		for (int j = 0; j < arr1.size(); j ++) {
			cout << arr1[j] << " ";
		}
		cout << exp(2, i) << "\n";
		
		cin >> ans[i];
		vector <int> arr2(0);
		for (int j = 0; j < arr1.size(); j ++) {
			if (arr1[j] != ans[i]) {
				cout << "? " << ans[i] << " " << arr1[j] << "\n";
				int x;
				cin >> x;
				if (x == 1) {
					arr2.push_back(arr1[j]);
				}
			}
		}
		arr1 = arr2;
	}
	
	cout << "! " << k-1 << " ";
	for (int i = 0; i < k; i ++) {
		cout << ans[i];
		if (i+1 == k) {
			cout << "\n";
		}
		else {
			cout << " ";
		}
	}
	
	return 0;
}

