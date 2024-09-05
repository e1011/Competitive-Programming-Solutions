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
	
	long long n, m, MOD=1000000007, P=328193, ans=0;
	cin >> n >> m;
	
	vector <long long> phash(n, 0);
	for (int i = 0; i < n; i ++) {
		cin >> phash[i];
		phash[i] += P;
		phash[i] %= MOD;
		if (i > 0) {
			phash[i] *= phash[i-1];
			phash[i] %= MOD;
		}
	}
	
	
	for (int i = m; i <= n; i += m) {
		long long target=1;
		for (int j = 1; j <= m; j ++) {
			target *= exp(j+P, i/m, MOD);
			target %= MOD;
		}
		for (int j = i-1; j < n; j ++) {
			long long hash = phash[j];
			if (j - i >= 0) {
				hash *= exp(phash[j-i], MOD-2, MOD);
				hash %= MOD;
			}
			ans += (hash == target);
		}
	}
	
	cout << ans << "\n";
	
	return 0;
}



