#include <iostream>

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
	int n, m, k;
	cin >> n >> m >> k;
	
	cout << (n-k+1)*exp(m, n-k+1, 1000000007) % 1000000007 << "\n";
	
	return 0;
}

