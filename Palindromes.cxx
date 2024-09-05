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

// too slow, and also wrong
// bsearch max even/odd palindrome length, use hashing to check if length exists

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t, MOD=1000000007, P=31;
	cin >> t;
	
	for (int _ = 0; _ < t; _ ++) {
		string s;
		cin >> s;
		int n = s.size();
		vector <long long> hash1(n, 0);
		vector <long long> hash2(n, 0);
		for (int i = 0; i < n; i ++) {
			hash1[i] = s[i]*exp(P, i, MOD);
			if (i > 0) {
				hash1[i] += hash1[i-1];
			}
			hash1[i] %= MOD;
		}
		for (int i = n-1; i >= 0; i --) {
			hash2[i] = s[i]*exp(P, n-1-i, MOD);
			if (i < n-1) {
				hash2[i] += hash2[i+1];
			}
			hash2[i] %= MOD;
		}
		
		int lIndex, rIndex, longest=0;
		for (int j = 0; j < 2; j ++) {
			int l=!j, r=n;
			while (l < r) {
				int mid0 = (l+r+1)/2, found=0;
				int mid = 2*mid0 + j;
				
				for (int i = 0; i+mid-1 < n; i ++) {
					long long s1 = hash1[i+mid-1], s2 = hash2[i];
					if (i > 0) {
						s1 -= hash1[i-1];
						s1 += MOD;
						s1 %= MOD;
					}
					if (i+mid < n) {
						s2 -= hash2[i+mid];
						s2 += MOD;
						s2 %= MOD;
					}
					
					s1 *= exp(exp(P, i, MOD), MOD-2, MOD);
					s1 %= MOD;
					s2 *= exp(exp(P, n-(i+mid), MOD), MOD-2, MOD);
					s2 %= MOD;
					if (s1 == s2) {
						found = 1;
						if (mid > longest) {
							longest = mid;
							lIndex = i;
							rIndex = i+mid-1;
						}
						break;
					}
				}
				
				if (found) {
					l = mid0;
				}
				else {
					r = mid0-1;
				}
			}
		}
		for (int i = lIndex; i <= rIndex; i ++) {
			cout << s[i];
		}
		cout << "\n" << longest << "\n";
	}
	
	return 0;
}

