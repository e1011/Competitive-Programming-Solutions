#include <iostream>
#include <vector>

using namespace std;

template <class T> struct SegTree { // cmb(ID,b) = b
	const T ID{}; T cmb(T a, T b) { return max(a, b); } 
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
	int n;
	cin >> n;
	
	vector <int> height(n, 0);
	vector <int> values(n, 0);
	for (int i = 0; i < n; i ++) {
		cin >> height[i];
		height[i] -= 1;
	}
	for (int i = 0; i < n; i ++) {
		cin >> values[i];
	}
	
	long long ans=0;
	SegTree <long long> seg;
	seg.init(n);
	
	for (int i = 0; i < n; i ++) {
		seg.upd(height[i], seg.query(0, height[i])+values[i]);
		ans = max(ans, seg.query(height[i], height[i]));
	}
	
	cout << ans << "\n";
	
	return 0;
}

