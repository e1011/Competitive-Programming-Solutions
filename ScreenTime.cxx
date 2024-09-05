#include <iostream>
#include <vector>

using namespace std;

// x^y mod p
long long exp(long long x, long long y, long long p) {
	long long res = 1; x %= p;
	while (y) {
		if (y & 1) {
			res *= x; res %= p; 
		}
		x *= x; x %= p;
		y >>= 1;
	}
	return res;
}

int main() {
	long long n, a=0, b=0, c=0, ans=0;
	cin >> n;
	
	for (int i = 0; i < n; i ++) {
		int x, y;
		cin >> x >> y;
		
		if (x > y) {
			swap(x, y);
		}
		if (x == 2 && y == 3) {
			a += 1;
		}
		else if (x == 1 && y == 3) {
			b += 1;
		}
		else {
			c += 1;
		}
	}
	
	vector <long long> factorials(n+1, 1), finverses(n+1, 1), bsubs(n+1, 0), csubs(n+1, 0);
	long long factorial = 1;
	for (int i = 2; i <= n; i ++) {
		factorial *= i;
		factorial %= 1000000007;
		factorials[i] = factorial;
		finverses[i] = exp(factorial, 1000000005, 1000000007);
	}
	
	// b choose i, c choose i
	for (int i = 0; i <= n; i ++) {
		if (i <= b) {
			bsubs[i] = (factorials[b]*finverses[i] % 1000000007)*finverses[b-i] % 1000000007;
		}
		if (i <= c) {
			csubs[i] = (factorials[c]*finverses[i] % 1000000007)*finverses[c-i] % 1000000007;
		}
	}
	
	// how many subsets of size i and above
	for (int i = n-1; i >= 0; i --) {
		bsubs[i] += bsubs[i+1];
		bsubs[i] %= 1000000007;
		csubs[i] += csubs[i+1];
		csubs[i] %= 1000000007;
	}
	
	for (int i = 0; i <= a; i ++) {
		long long achoosei = (factorials[a]*finverses[i] % 1000000007)*finverses[a-i] % 1000000007;
		if (i != n) {
			achoosei *= bsubs[i+1];
			achoosei %= 1000000007;
			achoosei *= csubs[i+1];
			achoosei %= 1000000007;
		}
		else {
			achoosei = 0;
		}
		ans += achoosei;
		ans %= 1000000007;
	}
	
	cout << ans << "\n";
	
	return 0;
}

