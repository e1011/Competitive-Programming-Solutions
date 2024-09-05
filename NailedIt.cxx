#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, ans=0, count=0;
	cin >> n;
	
	vector <int> arr(2001, 0);
	for (int i = 0; i < n; i ++) {
		int x;
		cin >> x;
		arr[x] += 1;
	}
	
	for (int i = 2; i < 4001; i ++) {
		int length = 0;
		for (int j = 1; j < 2001; j ++) {
			if (i-j <= 2000 && j < (i-j)) {
				length += min(arr[j], arr[i-j]);
			}
			else if (j == (i-j)) {
				length += arr[j]/2;
			}
		}
		if (length > ans) {
			ans = length;
			count = 1;
		}
		else if (length == ans) {
			count += 1;
		}
	}
	
	cout << ans << " " << count << "\n";
	
	return 0;
}

