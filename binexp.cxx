#include <iostream>

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
	long long a, b, MOD;
	cin >> a >> b >> MOD;
	
	cout << exp(a, b, MOD) << "\n";
	
	return 0;
}

