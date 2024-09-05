#include <iostream>
#include <vector>

using namespace std;

int n;
vector <int> segtree(0);

int comb(int a, int b) {
	return a+b;
}

void modify(int index, int val) {
	segtree[index+n] = val;
	for (int i = (index+n)/2; i > 0; i /= 2) {
		segtree[i] = comb(segtree[2*i], segtree[2*i+1]);
	}
}

int query(int l, int r) {
	int lsum = 0, rsum = 0;
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
	int s, t, ans = 0;
	cin >> n >> s >> t;
	
	segtree = vector <int>(2*n, 0);
	
	for (int i = 0; i < n; i ++) {
		int x;
		cin >> x;
		modify(i, x);
	}
	
	if (s*t >= n) {
		cout << query(0, n) << "\n";
		return 0;
	}
	
	for (int i = 0; i <= t; i ++) {
		//cout << query(0, i*s) << ", " << query(n-((t-i)*s), n) << "\n";
		ans = max(ans, query(0, i*s)+query(n-((t-i)*s), n));
	}
	cout << ans << "\n";
	
	return 0;
}

