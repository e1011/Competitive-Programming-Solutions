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
	int n, q;
	cin >> n;
	
	vector <SegTree <int>> heights(0);
	vector <int> trees(n, 0);
	for (int i = 0; i < n; i ++) {
		SegTree <int> seg;
		seg.init(n);
		heights.push_back(seg);
	}
	for (int i = 0; i < n; i ++) {
		cin >> trees[i];
		heights[trees[i]].upd(i, 1);
	}
	
	cin >> q;
	for (int i = 0; i < q; i ++) {
		int x, a, b, c, d, sum=0;
		cin >> x;
		if (x == 1) {
			cin >> a >> b >> c >> d;
			for (int j = c; j <= d; j ++) {
				sum += heights[j].query(a, b);
			}
			cout << sum << "\n";
		}
		else {
			cin >> a >> b;
			heights[trees[a]].upd(a, -1);
			trees[a] = b;
			heights[trees[a]].upd(a, 1);
		}
	}
	
	return 0;
}

