#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, q;
	cin >> n >> q;
	
	vector <int> arr(n, 0);
	vector <int> minsuffix(n, 0);
	vector <int> maxsuffix(n, 0);
	
	for (int i = 0; i < n; i ++) {
		cin >> arr[i];
	}
	for (int i = n-1; i >= 0; i --) {
		if (i == n-1) {
			minsuffix[i] = arr[i];
		}
		else {
			minsuffix[i] = min(arr[i], minsuffix[i+1]);
		}
	}
	for (int i = n-1; i >= 0; i --) {
		if (i == n-1) {
			maxsuffix[i] = arr[i];
		}
		else {
			maxsuffix[i] = max(arr[i], maxsuffix[i+1]);
		}
	}
	
	for (int i = 0; i < q; i ++) {
		int a, b, l=0, r=n-1;
		cin >> a >> b;
		while (l < r) {
			int mid = (l+r+1)/2;
			if (abs(minsuffix[mid]-a) > b || abs(maxsuffix[mid]-a) > b) {
				l = mid;
			}
			else {
				r = mid-1;
			}
		}
		if (l == 0 && !(abs(minsuffix[0]-a) > b || abs(maxsuffix[0]-a) > b)) {
			cout << n << "\n";
		}
		else {
			cout << n-1-l << "\n";
		}
	}
	
	return 0;
}

