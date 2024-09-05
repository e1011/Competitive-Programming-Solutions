#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, k, t;
	cin >> n >> k >> t;
	
	for (int _ = 0; _ < t; _ ++) {
		vector <int> arr(n, 0);
		for (int i = 0; i < n; i ++) {
			cin >> arr[i];
		}
		
		if (k == 2) {
			int v1 = 0, v2;
			for (int i = n-1; i >= 0; i --) {
				if (arr[i] > 0) {
					v2 = arr[i]+v1;
				}
				else {
					v1 += 1;
				}
			}
			cout << v2 << " " << 100-v2 << "\n";
		}
		if (k == 5) {
			int v2a=0, v3a=0, v4a=0, v5a=0, v2=-1, v3=-1, v4=-1, v5=-1;
			for (int i = n-1; i >= 0; i --) {
				if (arr[i] > 70 && v5 == -1) {
					v5 = arr[i]+v5a;
				}
				else if (arr[i] > 50 && v4 == -1) {
					v4 = arr[i]+v4a;
				}
				else if (arr[i] > 30 && v3 == -1) {
					v3 = arr[i]+v3a;
				}
				else if (arr[i] != 0 && v2 == -1) {
					v2 = arr[i]+v2a;
				}
				if (arr[i] < 10) {
					v2a += 1;
				}
				if (arr[i] < 30) {
					v3a += 1;
				}				
				if (arr[i] < 50) {
					v4a += 1;
				}				
				if (arr[i] < 70) {
					v5a += 1;
				}
			}
			cout << v2 << " " << v3-v2 << " " << v4-v3 << " " << v5-v4 << " " << 100-v5 << "\n";
		}
		
	}
	
	return 0;
}

