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
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	long long p = 31, MOD = 1000000009, hash2=0, ans=0;
	string a, b;
	cin >> a >> b;
	
	vector <long long> hash1(a.size(), 0);
	for (int i = 0; i < a.size(); i ++) {
		if (i != 0) {
			hash1[i] += hash1[i-1];
		}
		hash1[i] += exp(p, i, MOD)*a[i];
		hash1[i] %= MOD;
	}
	
	for (int i = 0; i < b.size(); i ++) {
		hash2 += exp(p, i, MOD)*b[i];
		hash2 %= MOD;
	}
	
	for (int i = 0; i <= (int)a.size() - b.size(); i ++) {
		long long subhash1 = hash1[i-1+b.size()];
		if (i != 0) {
			subhash1 += MOD - hash1[i-1];
			subhash1 %= MOD;
			subhash1 *= exp(exp(p, i, MOD), MOD-2, MOD);
			subhash1 %= MOD;
		}
		if (subhash1 == hash2) {
			ans += 1;
		}
	}
	
	cout << ans << "\n";
	
	return 0;
}

