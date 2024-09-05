#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, q, k;
	string a, b;
	cin >> n >> a >> b;
	
	vector <int> arr1(n, 0), arr2(n, 0);
	
	for (int i = 0; i < n; i ++) {
		if (a[i] == 'R') {
			arr1[i] = 0;
		}
		if (a[i] == 'G') {
			arr1[i] = 1;
		}
		if (a[i] == 'B') {
			arr1[i] = 2;
		}
		if (b[i] == 'R') {
			arr2[i] = 0;
		}
		if (b[i] == 'G') {
			arr2[i] = 1;
		}
		if (b[i] == 'B') {
			arr2[i] = 2;
		}
	}
	
	k = (arr1[0] == arr2[0]);
	for (int i = 1; i < n; i ++) {
		arr1[i] -= arr1[i-1];
		arr1[i] = (arr1[i]+3)%3;		
		arr2[i] -= arr2[i-1];
		arr2[i] = (arr2[i]+3)%3;
		k += (arr1[i] == arr2[i]);
	}
	
	cin >> q;
	for (int i = 0; i < q; i ++) {
		int l, r;
		cin >> l >> r;
		if (arr1[l-1] == arr2[l-1]) {
			k -= 1;
		}
		arr1[l-1] += 1;
		arr1[l-1] %= 3;
		if (arr1[l-1] == arr2[l-1]) {
			k += 1;
		}
		
		if (arr1[r] == arr2[r]) {
			k -= 1;
		}
		arr1[r] -= 1;
		arr1[r] += 3;
		arr1[r] %= 3;
		if (arr1[r] == arr2[r]) {
			k += 1;
		}
		
		if (k == n) {
			cout << i+1 << "\n";
			break;
		}
	}
	
	return 0;
}

