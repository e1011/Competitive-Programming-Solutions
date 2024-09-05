#include <iostream>
#include <complex>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int t;
	long double pi = 3.14159265;
	cin >> t;
	
	for (int _ = 0; _ < t; _ ++) {
		int n, ans=1000000000, pointer=0;
		cin >> n;
		
		vector <long double> arr(0);
		for (int i = 0; i < n; i ++) {
			long double x, y;
			cin >> x >> y;
			long double radians = arg(complex <long double> {x, y});
			if (radians < 0) {
				radians = 2*pi + radians;
			}
			arr.push_back(radians);
			arr.push_back(radians+2*pi);
		}
		sort(arr.begin(), arr.end());
		
		for (int i = 0; i < n; i ++) {
			while (arr[pointer+1]-arr[i] < pi) {
				pointer += 1;
			}
			ans = min(ans, max(0, pointer-i));
		}
		
		cout << ans << "\n";
	}
	
	
	return 0;
}

