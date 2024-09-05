#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, money=0, ans=0, earliest=-1;
	cin >> n;
	
	vector <int> arr(n, 0);
	for (int i = 0; i < n; i ++) {
		cin >> arr[i];
	}
	
	for (int i = 0; i < n; i ++) {
		money += arr[i];
		if (earliest == -1 && money < 0) {
			earliest = i;
		}
		if (earliest != -1 && money >= 0) {
			ans += (i-earliest)*2;
			earliest = -1;
		}
	}
	
	cout << ans+n << "\n";
	
	return 0;
}

