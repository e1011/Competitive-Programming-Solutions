#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
	int n;
	long double ans=1000000000000000;
	cin >> n;
	vector <int> villages(n, 0);
	
	for (int i = 0; i < n; i ++) {
		cin >> villages[i];
	}
	sort(villages.begin(), villages.end());
	
	for (int i = 1; i < n-1; i ++) {
		if (ans > villages[i+1]-villages[i-1]) {
			ans = villages[i+1]-villages[i-1];
		}
	}
	
	cout << fixed << setprecision(1) << ans/2 << "\n";
	
	return 0;
}

