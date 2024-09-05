#include <iostream>
#include <vector>

using namespace std;

int n, q;
vector <int> segtree1, segtree2, prices;

int comb1(int a, int b) {
	if (b == -1) {
		return a;
	}
	else if (a == -1 || prices[a]-a > prices[b]-b) {
		return b;
	}
	return a;
}

void modify1(int index, int val) {
	prices[index] = val;
	for (int i = (index+n)/2; i > 0; i /= 2) {
		segtree1[i] = comb1(segtree1[2*i], segtree1[2*i+1]);
	}
}

int query1(int l, int r) {
	int lsum = -1, rsum = -1;
	for (l += n, r += n; l < r; l /= 2, r /= 2) {
		if (l % 2 == 1) {
			lsum = comb1(lsum, segtree1[l++]); 
		}
		if (r % 2 == 1) {
			rsum = comb1(rsum, segtree1[--r]);
		}
	}
	return comb1(lsum, rsum);
}

int comb2(int a, int b) {
	if (b == -1) {
		return a;
	}
	else if (a == -1 || prices[a]+a > prices[b]+b) {
		return b;
	}
	return a;
}

void modify2(int index, int val) {
	prices[index] = val;
	for (int i = (index+n)/2; i > 0; i /= 2) {
		segtree2[i] = comb2(segtree2[2*i], segtree2[2*i+1]);
	}
}

int query2(int l, int r) {
	int lsum = -1, rsum = -1;
	for (l += n, r += n; l < r; l /= 2, r /= 2) {
		if (l % 2 == 1) {
			lsum = comb2(lsum, segtree2[l++]); 
		}
		if (r % 2 == 1) {
			rsum = comb2(rsum, segtree2[--r]);
		}
	}
	return comb2(lsum, rsum);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> q;
	
	segtree1 = vector <int> (2*n, -1);
	segtree2 = vector <int> (2*n, -1);
	prices = vector <int> (n, 0);
	
	for (int i = 0; i < n; i ++) {
		int x;
		cin >> x;
		segtree1[i+n] = i;
		segtree2[i+n] = i;
		modify1(i, x);
		modify2(i, x);
	}
	
	for (int i = 0; i < q; i ++) {
		int a, b, c;
		cin >> a >> b;
		if (a == 1) {
			cin >> c;
			modify1(b-1, c);
			modify2(b-1, c);
		}
		else {
			int l = query1(0, b-1), r=query2(b, n);
			if (b == n) {
				cout << min(prices[b-1], prices[l]+b-1-l) << "\n";
			}
			else if (b == 1) {
				cout << min(prices[b-1], prices[r]-(b-1)+r) << "\n";
			}
			else {
				cout << min(prices[b-1], min(prices[l]+b-1-l, prices[r]-(b-1)+r)) << "\n";
			}
		}
	}
	
	return 0;
}
/*
6 6
8 6 4 5 7 5
2 2
1 5 1
2 2
* */

