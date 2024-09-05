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
	int n, k;
	cin >> n >> k;
	
	SegTree <long long> seg;
	seg.init(n);
	for (int i = 0; i < n; i ++) {
		int x;
		cin >> x;
		seg.upd(i, x);
	}
	
	int numberofdays=(n/k)+min(1, n%k);
	int maxbreaks = (k-(n%k))%k;
	vector <vector <long long>> dp(numberofdays+1, vector <long long> (maxbreaks+1, -1));
	dp[0][0] = 0;
	for (int i = 0; i < numberofdays; i ++) {
		for (int j = 0; j <= maxbreaks; j ++) {
			if (dp[i][j] != -1) {
				for (int l = (maxbreaks-j); l >= 0; l --) {
					if ((i+1)*k-j-l-1 < n) {
						dp[i+1][j+l] = max(dp[i+1][j+l], dp[i][j]+seg.query(i*k-j, (i+1)*k-j-l-1));
					}
					else {
						break;
					}
				}
			}
		}
	}
	
	/*
	for (int i = 0; i <= numberofdays; i ++) {
		for (int j = 0; j <= maxbreaks; j ++) {
			cout << dp[i][j] << " ";
		}
		cout << "\n";
	}
	* */
	
	cout << dp[numberofdays][maxbreaks] << "\n";
	
	return 0;
}


