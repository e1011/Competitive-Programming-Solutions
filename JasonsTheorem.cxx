#include <iostream>
#include <vector>

using namespace std;

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
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	long long n, MOD=1000000007;
	cin >> n;
	
	n = exp(2, n, MOD);
	n = 8*n + MOD - 5;
	n %= MOD;
	
	if (n < 0) {
		throw;
	}
	cout << n << "\n";
	
	return 0;
}

// f(0) = 1
// f(n) = 2*f(n-1)+7
// output f(n)+2;


// f(1) = 2*1+7 = 9
// f(2) = 2*9+7 = 25
// f(3) = 2*25+7 = 57


// f(n) = 2^n + 7*2^n - 7
// = 8*2^n - 7
// = 2^3 * 2^n - 7
// = 2^(n+3) - 7


