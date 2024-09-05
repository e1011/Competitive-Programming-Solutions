#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, ans=0, bits=0;
	cin >> n;
	
	vector <int> arr(n, 0);
	for (int i = 0; i < n; i ++) {
		cin >> arr[i];
	}
	vector <int> arr2 = arr;
	for (int i = 1; i < n; i ++) {
		arr2[i] ^= arr[i-1];
	}
	
	for (int i = 1; i < n; i ++) {
		if ((arr2[i]^bits) < (arr2[i-1]^bits)) {
			for (int j = 0; j < 1000000; j ++) {
				if ((arr2[i] | (1 << j)) >= arr2[i-1]) {
					bits ^= (1 << j);
					ans += 1;
					//cout << i << ", " << j << "\n";
					break;
				}
			}
		}
	}
	
	cout << ans << "\n";
	
	return 0;
}

