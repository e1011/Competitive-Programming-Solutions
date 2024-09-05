#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	long long n, l=-1, r=-1;
	cin >> n;
	
	vector <vector <long long>> arr(n, vector <long long> (2, 0));
	for (int i = 0; i < n; i ++) {
		cin >> arr[i][0];
		arr[i][1] = i;
	}
	
	sort(arr.begin(), arr.end());
	reverse(arr.begin(), arr.end());
	
	long long ans=0;
	for (int i = 0; i < n; i ++) {
		if (l == -1) {
			l = arr[i][1];
			r = arr[i][1];
		}
		else if (arr[i][1] < l) {
			ans += arr[i][0]*(l-arr[i][1]-1);
			l = arr[i][1];
		}
		else if (arr[i][1] > r) {
			ans += arr[i][0]*(arr[i][1]-r-1);
			r = arr[i][1];
		}
		else {
			ans -= arr[i][0];
		}
	}
	
	cout << ans << "\n";
	
	return 0;
}

