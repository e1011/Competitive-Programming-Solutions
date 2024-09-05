#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, q;
	cin >> n >> q;
	
	vector <int> arr(n, 0);
	
	for (int i = 0; i < n; i ++) {
		cin >> arr[i];
	}
	for (int i = 1; i < n; i ++) {
		arr[i] += arr[i-1];
	}
	
	for (int i = 0; i < q; i ++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (b == 1) {
			cout << arr[c-1] << "\n";
		}
		else {
			cout << arr[c-1]-arr[b-2] << "\n";
		}
	}
	
	return 0;
}

