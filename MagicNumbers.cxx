#include <iostream>

using namespace std;

int main() {
	long long n, ans1=0;
	cin >> n;
	
	for (long long i = 1; i*i < n; i ++) {
		if (n % i == 0) {
			if (n % (n/i - 1) == n/(n/i - 1)) {
				ans1 += (n/i) - 1;
			}
		}
	}
	
	/*
	for (int i = 1; i < n; i ++) {
		if (n/i == n % i) {
			ans2 += i;
		}
	}
	*/
	
	cout << ans1 << "\n";
	
	return 0;
}
