#include <iostream>
#include <vector>

using namespace std;

int n, q;
// initialize this to 2*n length
vector <int> segtree(0);

int comb(int a, int b) {
	return min(a, b);
}

void modify(int index, int val) {
	segtree[index+n] = val;
	for (int i = (index+n)/2; i > 0; i /= 2) {
		segtree[i] = comb(segtree[2*i], segtree[2*i+1]);
	}
}

int query(int l, int r) {
	int lsum = 1000000000, rsum = 1000000000;
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
	
	for (int i = 0; i < n; i ++) {
		cin >> segtree[i+n];
		modify(i, segtree[i+n]);
	}
	
	for (int i = 0; i < q; i ++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 1) {
			modify(b-1, c);
		}
		else {
			cout << query(b-1, c) << "\n";
		}
	}
	
	return 0;
}

