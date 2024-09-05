#include <iostream>
#include <vector>

using namespace std;

template <class T> struct SegTree { // cmb(ID,b) = b
	const T ID{}; T cmb(T a, T b) { return (a+b); } 
	int n; vector <T> seg;
	void init(int _n) { // upd, query also work if n = _n
		for (n = 1; n < _n; ) n *= 2; 
		seg.assign(2*n,ID); }
	void pull(int p) { seg[p] = cmb(seg[2*p],seg[2*p+1]); }
	void upd(int p, T val) { // set val at position p
		seg[p += n] += val; for (p /= 2; p; p /= 2) pull(p); }
	T query(int l, int r) {	// associative op on [l, r]
		T ra = ID, rb = ID;
		for (l += n, r += n+1; l < r; l /= 2, r /= 2) {
			if (l&1) ra = cmb(ra,seg[l++]);
			if (r&1) rb = cmb(seg[--r],rb);
		}
		return cmb(ra,rb);
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, ans=0;
	cin >> n;
	
	vector <SegTree <long long>> field;
	for (int i = 0; i < 2000; i ++) {
		SegTree <long long> seg;
		seg.init(i+1);
		field.push_back(seg);
	}
	
	for (int i = 0; i < n; i ++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		if (a == 1) {
			field[b+c-2].upd(c-1, d);
		}
		else {
			ans += field[b+c-2].query(c-1, c-1+d);
			ans %= 1000000007;
		}
	}
	
	cout << ans << "\n";
	
	return 0;
}

