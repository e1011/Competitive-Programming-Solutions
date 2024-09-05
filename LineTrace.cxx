#include <iostream>
#include <vector>

using namespace std;


int main() {
	int n, works = 1, ans=0;
	cin >> n;
	
	vector <int> seen(n, 0);
	vector <int> arr(n, 0);
	for (int i = 0; i < n; i ++) {
		int x;
		cin >> x;
		arr[i] = x-1;
		if (seen[x-1] == 1) {
			works = 0;
		}
		seen[x-1] = 1;
	}
	
	if (works == 0) {
		cout << "-1\n";
	} 
	else {
		for (int i = 0; i < n; i ++) {
			for (int j = 0; j < i; j ++) {
				if (arr[j] > arr[i]) {
					ans += 1;
				}
			}
		}
		cout << ans << "\n";
	}
	
	return 0;
}

