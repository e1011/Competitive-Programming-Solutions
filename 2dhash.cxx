#include <iostream>
#include <vector>

using namespace std;

long long binexp(long long a, long long b, long long m) {
    a %= m;
    long long result = 1;
    while (b) {
        if (b & 1) {
            result *= a;
            result %= m;
        }
        b = (b >> 1);
        a *= a;
        a %= m;
    }
    return result;
}

int main() {
	int n, m, q, p1 = 31, p2 = 29, MOD = 1000000007;
	cin >> n >> m >> q;
	
	vector <vector <int>> grid(n, vector <int> (m, 0));
	vector <vector <long long>> prefixhash(n, vector <long long> (m, 0));
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < m; j ++) {
			cin >> grid[i][j];
		}
	}
	
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < m; j ++) {
			prefixhash[i][j] = grid[i][j]*binexp(p1, i, MOD) % MOD;
			prefixhash[i][j] *= binexp(p2, j, MOD);
			prefixhash[i][j] %= MOD;
			
			if (i != 0 && j != 0) {
				prefixhash[i][j] -= prefixhash[i-1][j-1];
				prefixhash[i][j] += MOD;
				prefixhash[i][j] %= MOD;
			}
			if (i != 0) {
				prefixhash[i][j] += prefixhash[i-1][j];
				prefixhash[i][j] %= MOD;
			}
			if (j != 0) {
				prefixhash[i][j] += prefixhash[i][j-1];
				prefixhash[i][j] %= MOD;
			}
		}
	}
	
	
	for (int i = 0; i < q; i ++) {
		// bottom right, then top left
		int i1, j1, i2, j2;
		cin >> i1 >> j1 >> i2 >> j2;
		
		long long hash = prefixhash[i1][j1];
		if (i2 != 0 && j2 != 0) {
			hash += prefixhash[i2-1][j2-1];
			hash %= MOD;
		}
		if (i2 != 0) {
			hash -= prefixhash[i2-1][j1];
			hash += MOD;
			hash %= MOD;
		}
		if (j2 != 0) {
			hash -= prefixhash[i1][j2-1];
			hash += MOD;
			hash %= MOD;
		}
		
		hash *= binexp(binexp(p1, i2, MOD), MOD-2, MOD);
		hash %= MOD;
		hash *= binexp(binexp(p2, j2, MOD), MOD-2, MOD);
		hash %= MOD;
		
		cout << hash << "\n";
	}
	
	
	return 0;
}

