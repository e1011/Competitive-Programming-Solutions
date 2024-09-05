#include <iostream>
#include <vector>

using namespace std;

int main() {
	long long n, ans=0;
	cin >> n;
	
	if (n <= 3) {
		cout << 0 << "\n";
	}
	else {
		for (long long k = 0; 2*k < n; k ++) {
			ans = max(ans, k*(n-(2*k))*(n-1-(2*k))/2);
		}
		cout << ans << "\n";
	}
	
	
	return 0;
}

