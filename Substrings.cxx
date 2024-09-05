#include <iostream>
#include <vector>
#include <set>

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
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i ++) {
		int m=1000000007, p=31;
		string s;
		cin >> s;
		
		vector <long long> prefixhash(s.size(), 0);
		for (int j = 0; j < s.size(); j ++) {
			prefixhash[j] = (s[j]*exp(p, j, m) + m) % m;
			if (j > 0) {
				prefixhash[j] += prefixhash[j-1];
				prefixhash[j] %= m;
			}
		}
		
		set <int> seenhashes;
		for (int j = 0; j < s.size(); j ++) {
			for (int k = j; k < s.size(); k ++) {
				long long hash = prefixhash[k];
				if (j > 0) {
					hash = (hash-prefixhash[j-1]+m)%m;
				}
				hash *= exp(exp(p, j, m), m-2, m);
				hash %= m;
				seenhashes.insert(hash);
			}
		}
		
		cout << seenhashes.size()+1 << "\n";
	}
	
	
	return 0;
}

