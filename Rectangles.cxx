#include <iostream>
#include <vector>
#include <set>

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

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m, k, ans=0, ivalue1=370912027, jvalue1=429339013, ivalue2=172230103, jvalue2=411401267, MOD=1631425921;
	cin >> n >> m >> k;
	
	vector <vector <long long>> prefixhash1(n, vector <long long> (m, 0));
	vector <vector <long long>> prefixhash2(n, vector <long long> (m, 0));
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < m; j ++) {
			char c;
			cin >> c;
			prefixhash1[i][j] = c*(exp(ivalue1, i, MOD)*exp(jvalue1, j, MOD) % MOD) % MOD;
			prefixhash2[i][j] = c*(exp(ivalue2, i, MOD)*exp(jvalue2, j, MOD) % MOD) % MOD;
			if (i > 0) {
				prefixhash1[i][j] += prefixhash1[i-1][j];
				prefixhash1[i][j] %= MOD;
				prefixhash2[i][j] += prefixhash2[i-1][j];
				prefixhash2[i][j] %= MOD;
			}
			if (j > 0) {
				prefixhash1[i][j] += prefixhash1[i][j-1];
				prefixhash1[i][j] %= MOD;
				prefixhash2[i][j] += prefixhash2[i][j-1];
				prefixhash2[i][j] %= MOD;
			}
			if (i > 0 && j > 0) {
				prefixhash1[i][j] -= prefixhash1[i-1][j-1];
				prefixhash1[i][j] += MOD;
				prefixhash1[i][j] %= MOD;
				prefixhash2[i][j] -= prefixhash2[i-1][j-1];
				prefixhash2[i][j] += MOD;
				prefixhash2[i][j] %= MOD;
			}
		}
	}
	
	set <int> seenhashes1;
	set <int> seenhashes2;
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < m; j ++) {
			if (i > k-2 && j > k-2) {
				long long hash1 = prefixhash1[i][j];
				long long hash2 = prefixhash2[i][j];
				
				if (i-k >= 0) {
					hash1 -= prefixhash1[i-k][j];
					hash1 += MOD;
					hash1 %= MOD;
					hash2 -= prefixhash2[i-k][j];
					hash2 += MOD;
					hash2 %= MOD;
				}
				if (j-k >= 0) {
					hash1 -= prefixhash1[i][j-k];
					hash1 += MOD;
					hash1 %= MOD;
					hash2 -= prefixhash2[i][j-k];
					hash2 += MOD;
					hash2 %= MOD;
				}
				if (i-k >= 0 && j-k >= 0) {
					hash1 += prefixhash1[i-k][j-k];
					hash1 %= MOD;
					hash2 += prefixhash2[i-k][j-k];
					hash2 %= MOD;
				}
				
				hash1 *= exp(exp(ivalue1, i-k+1, MOD), MOD-2, MOD);
				hash1 %= MOD;
				hash1 *= exp(exp(jvalue1, j-k+1, MOD), MOD-2, MOD);
				hash1 %= MOD;
				hash2 *= exp(exp(ivalue2, i-k+1, MOD), MOD-2, MOD);
				hash2 %= MOD;
				hash2 *= exp(exp(jvalue2, j-k+1, MOD), MOD-2, MOD);
				hash2 %= MOD;
				
				if (seenhashes1.count(hash1) == 0 || seenhashes2.count(hash2) == 0) {
					ans += 1;
					seenhashes1.insert(hash1);
					seenhashes2.insert(hash2);
				}
			}
		}
	}
	
	cout << ans << "\n";
	
	return 0;
}

