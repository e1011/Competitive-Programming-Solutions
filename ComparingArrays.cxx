#include <iostream>
#include <vector>

using namespace std;

template <class T> struct SegTree { // cmb(ID,b) = b
	const T ID{}; T cmb(T a, T b) { return (a + b); } 
	int n; vector <T> seg;
	void init(int _n) { // upd, query also work if n = _n
		for (n = 1; n < _n; ) n *= 2; 
		seg.assign(2*n,ID); }
	void pull(int p) { seg[p] = cmb(seg[2*p],seg[2*p+1]); }
	void upd(int p, T val) { // set val at position p
		seg[p += n] = val; for (p /= 2; p; p /= 2) pull(p); }
	T query(int l, int r) {	// associative op on [l, r]
		T ra = ID, rb = ID;
		for (l += n, r += n+1; l < r; l /= 2, r /= 2) {
			if (l&1) ra = cmb(ra,seg[l++]);
			if (r&1) rb = cmb(seg[--r],rb);
		}
		return cmb(ra,rb);
	}
};

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
	int n, q, MOD=1000000009, P=320129;
	cin >> n >> q;
	
	SegTree <long long> seg;
	seg.init(n);
	for (int i = 0; i < n; i ++) {
		int x;
		cin >> x;
		seg.upd(i, (x*exp(P, i, MOD))%MOD);
	}
	
	for (int i = 0; i < q; i ++) {
		int a, b, c, d, e;
		cin >> a;
		if (a == 1) {
			cin >> b >> c >> d >> e;
			c -= 1;
			b -= 1;
			d -= 1;
			e -= 1;
			long long s1=seg.query(b, c)%MOD, s2=seg.query(d, e)%MOD;
			s1 *= exp(exp(P, b, MOD), MOD-2, MOD);
			s1 %= MOD;
			s2 *= exp(exp(P, d, MOD), MOD-2, MOD);
			s2 %= MOD;
			if (s1 == s2) {
				cout << "1\n";
			}
			else {
				cout << "0\n";
			}
		}
		else {
			cin >> b >> c;
			b -= 1;
			seg.upd(b, (c*exp(P, b, MOD))%MOD);
		}
	}
	
	return 0;
}

