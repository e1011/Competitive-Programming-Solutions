#include <iostream>
#include <vector>

using namespace std;

int n, q;
vector <vector <long long>> segtree;

vector <long long> comb(vector <long long> a, vector <long long> b) {
	if (a.size() == 1) {
		return b;
	}
	if (b.size() == 1) {
		return a;
	}
	vector <long long> ret(4, 0);
	ret[0] = max(a[0], a[3]+b[0]);
	ret[1] = max(b[1], a[1]+b[3]);
	ret[2] = max(a[2], max(b[2], max(a[1]+b[0], max(ret[0], ret[1]))));
	ret[3] = a[3]+b[3];
	return ret;
}

void modify(int index, vector <long long> val) {
	segtree[index+n] = val;
	for (int i = (index+n)/2; i > 0; i /= 2) {
		segtree[i] = comb(segtree[2*i], segtree[2*i+1]);
	}
}

vector <long long> query(int l, int r) {
	vector <long long> lsum = {-1}, rsum = {-1};
	for (l += n, r += n; l < r; l /= 2, r /= 2) {
		if (l % 2 == 1) {
			lsum = comb(lsum, segtree[l++]); 
		}
		if (r % 2 == 1) {
			rsum = comb(segtree[--r], rsum);
		}
	}
	return comb(lsum, rsum);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> q;
	
	segtree = vector <vector <long long>> (2*n, {-1});
	for (int i = 0; i < n; i ++) {
		int x;
		cin >> x;
		modify(i, {max(0, x), max(0, x), max(0, x), x});
	}
	
	for (int i = 0; i < q; i ++) {
		int a, b;
		cin >> a >> b;
		modify(a-1, {max(0, b), max(0, b), max(0, b), b});
		cout << segtree[1][2] << "\n";
	}
	
	return 0;
}

// 0 = max l, 1 = max r, 2 = max all, 3 = total
