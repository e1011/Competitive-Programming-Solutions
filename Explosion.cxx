#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, d, ans1=0, ans2=0;
	cin >> n >> d;
	
	vector <int> arr(n, 0);
	
	for (int i = 0; i < n; i ++) {
		cin >> arr[i];
	}
	int counter = 1;
	for (int i = 1; i < n; i ++) {
		if (abs(arr[i]-arr[i-1]) > d) {
			ans1 += 1;
			counter = 1;
		}
		else {
			counter += 1;
			ans2 = max(ans2, counter);
		}
	}
	
	cout << ans1+1 << "\n" << ans2 << "\n";
	
	
	return 0;
}

