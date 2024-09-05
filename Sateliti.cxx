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
	int n, m, p1 = 29, p2 = 31, MOD = 150467111, besti=0, bestj=0;
	cin >> n >> m;
	
	vector <vector <int>> smallgrid(n, vector <int> (m, 0));
	vector <vector <int>> grid(2*n, vector <int>(2*m, 0));
	vector <vector <long long>> prefixhash(2*n, vector <long long> (2*m, 0));
	for (int i = 0; i < n; i ++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j ++) {
			if (s[j] == '.') {
				smallgrid[i][j] = 1;
			}
		}
	}
	for (int i = 0; i < 2*n; i ++) {
		for (int j = 0; j < 2*m; j ++) {
			grid[i][j] = smallgrid[i % n][j % m];
		}
	}
	
	for (int i = 0; i < 2*n; i ++) {
		for (int j = 0; j < 2*m; j ++) {
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
	
	for (int i = 0; i <= n; i ++) {
		for (int j = 0; j <= m; j ++) {
			
			int li=0, ri=n-1;
			while (li < ri) {
				int mid = (li+ri)/2;
				
				long long hash1 = prefixhash[i+mid][j+m-1];
				if (i != 0 && j != 0) {
					hash1 += prefixhash[i-1][j-1];
					hash1 %= MOD;
				}
				if (i != 0) {
					hash1 -= prefixhash[i-1][j+m-1];
					hash1 += MOD;
					hash1 %= MOD;
				}
				if (j != 0) {
					hash1 -= prefixhash[i+mid][j-1];
					hash1 += MOD;
					hash1 %= MOD;
				}
				hash1 *= binexp(binexp(p1, i, MOD), MOD-2, MOD);
				hash1 %= MOD;
				hash1 *= binexp(binexp(p2, j, MOD), MOD-2, MOD);
				hash1 %= MOD;
				
				long long hash2 = prefixhash[besti+mid][bestj+m-1];
				if (besti != 0 && bestj != 0) {
					hash2 += prefixhash[besti-1][bestj-1];
					hash2 %= MOD;
				}
				if (besti != 0) {
					hash2 -= prefixhash[besti-1][bestj+m-1];
					hash2 += MOD;
					hash2 %= MOD;
				}
				if (bestj != 0) {
					hash2 -= prefixhash[besti+n-1][bestj-1];
					hash2 += MOD;
					hash2 %= MOD;
				}
				hash2 *= binexp(binexp(p1, besti, MOD), MOD-2, MOD);
				hash2 %= MOD;
				hash2 *= binexp(binexp(p2, bestj, MOD), MOD-2, MOD);
				hash2 %= MOD;
				
				if (hash1 == hash2) {
					li = mid+1;
				}
				else {
					ri = mid;
				}
			}
			//cout << besti << ", " << bestj << ", " << i << ", " << j << ", " << ri << "\n";
			
			int lj = 0, rj = m-1;
			while (lj < rj) {
				int mid = (lj+rj)/2;
				
				long long hash1 = prefixhash[i+ri][j+mid];
				if (i != 0 && j != 0) {
					hash1 += prefixhash[i-1][j-1];
					hash1 %= MOD;
				}
				if (i != 0) {
					hash1 -= prefixhash[i-1][j+mid];
					hash1 += MOD;
					hash1 %= MOD;
				}
				if (j != 0) {
					hash1 -= prefixhash[i+ri][j-1];
					hash1 += MOD;
					hash1 %= MOD;
				}
				hash1 *= binexp(binexp(p1, i, MOD), MOD-2, MOD);
				hash1 %= MOD;
				hash1 *= binexp(binexp(p2, j, MOD), MOD-2, MOD);
				hash1 %= MOD;
				
				
				long long hash2 = prefixhash[besti+ri][bestj+mid];
				if (besti != 0 && bestj != 0) {
					hash2 += prefixhash[besti-1][bestj-1];
					hash2 %= MOD;
				}
				if (besti != 0) {
					hash2 -= prefixhash[besti-1][bestj+mid];
					hash2 += MOD;
					hash2 %= MOD;
				}
				if (bestj != 0) {
					hash2 -= prefixhash[besti+ri][bestj-1];
					hash2 += MOD;
					hash2 %= MOD;
				}
				hash2 *= binexp(binexp(p1, besti, MOD), MOD-2, MOD);
				hash2 %= MOD;
				hash2 *= binexp(binexp(p2, bestj, MOD), MOD-2, MOD);
				hash2 %= MOD;
				
				if (hash1 == hash2) {
					lj = mid+1;
				}
				else {
					rj = mid;
				}
			}
			
			if (grid[besti+ri][bestj+rj] > grid[i+ri][j+rj]) {
				besti = i;
				bestj = j;
			}
			else if (rj == 0 && grid[besti+ri][bestj+rj] == grid[i+ri][j+rj] && grid[besti+ri][bestj+rj+1] > grid[i+ri][j+rj+1]) {
				besti = i;
				bestj = j;
			}
		}
	}
	
	for (int i = besti; i < besti+n; i ++) {
		for (int j = bestj; j < bestj+m; j ++) {
			if (grid[i][j] == 0) {
				cout << "*";
			}
			else {
				cout << ".";
			}
		}
		cout << "\n";
	}
	
	return 0;
}

