#include <iostream>
#include <vector>
#include <set>
#include <algorihmt>

using namespace std;

int n, q;

long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }

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

vector<int> factor(int n) {
	vector<int> ret;
	for (int i = 2; i * i <= n; i++) {
		while (n % i == 0) {
			ret.push_back(i);
			n /= i;
		}
	}
	if (n > 1) { ret.push_back(n); }
	return ret;
}

// initialize this to 2*n length
vector <int> segtree(0);

int comb(int a, int b) {
	if (a == -1) {
		return b;
	}
	if (b == -1) {
		return a;
	}
	return gcd(a, b);
}

void modify(int index, int val) {
	segtree[index+n] *= val;
	for (int i = (index+n)/2; i > 0; i /= 2) {
		segtree[i] = comb(segtree[2*i], segtree[2*i+1]);
	}
}

int query(int l, int r) {
	int lsum = -1, rsum = -1;
	for (l += n, r += n; l < r; l /= 2, r /= 2) {
		if (l % 2 == 1) {
			lsum = comb(lsum, segtree[l++]); 
		}
		if (r % 2 == 1) {
			rsum = comb(rsum, segtree[--r]);
		}
	}
	return comb(lsum, rsum);
}

int main() {
	cin >> n >> q;
	
	segtree = vector <int> (2*n, 0);
	vector <multiset <int>> factors3(14, multiset <int> ());
	vector <vector <int>> arr(0);
	
	for (int i = 0; i < q; i ++) {
		int a, b, c;
		cin >> a >> b >> c;
		arr.push_back({a-1, c});
		arr.push_back({b-1, c});
	}
	sort(arr.begin(), arr.end());
	
	for (int i = 0; i < n; i ++) {
		int pointer = 0;
		while (arr[pointer][0] <= i) {
			if (arr[pointer][1] > 0) {
				vector <int> factors = factor(arr[pointer][1]);
				vector <int> factors2(14, 0);
				
				for (int j = 0; j < factors.size(); j ++) {
					factors2[factors[j]] += 1;
				}
				for (int j = 0; j < 14; j ++) {
					factors3[j].insert(factors2[j]);
				}
			}
			else {
				vector <int> factors = factor(-arr[pointer][1]);
				vector <int> factors2(14, 0);
				
				for (int j = 0; j < factors.size(); j ++) {
					factors2[factors[j]] += 1;
				}
				for (int j = 0; j < 14; j ++) {
					factors3[j].remove(factors2[j]);
				}
			}
		}
		
		for (int j = 0; j < 14; j ++) {
			if (factors[j].lower_bund)
			modify(i, exp(j, ));
		}
	}
	
	return 0;
}

