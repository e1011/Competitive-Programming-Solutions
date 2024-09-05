#include <iostream>
#include <vector>

using namespace std;

int n, q;
vector <vector <int>> segtree;

vector <int> comb(vector <int> a, vector <int> b) {
	if (a.size() == 1) {
		return b;
	}
	if (b.size() == 1) {
		return a;
	}
	
	vector <int> ret(4, 0);
	ret[0] = max(a[0]+b[2], a[1]+b[0]);
	ret[1] = max(a[1]+b[1], a[0]+b[3]);
	ret[2] = max(a[2]+b[2], a[3]+b[0]);
	ret[3] = max(a[3]+b[1], a[2]+b[3]);
	return ret;
}

void modify(int index, vector <int> val) {
	segtree[index+n] = val;
	for (int i = (index+n)/2; i > 0; i /= 2) {
		segtree[i] = comb(segtree[2*i], segtree[2*i+1]);
	}
}

vector <int> query(int l, int r) {
	vector <int> lsum = {-1}, rsum = {-1};
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
	freopen("optmilk.in", "r", stdin);
	freopen("optmilk.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	long long ans = 0;
	cin >> n >> q;
	
	segtree = vector <vector <int>> (2*n, vector <int> (1, -1));
	for (int i = 0; i < n; i ++) {
		int x;
		cin >> x;
		modify(i, {0, 0, 0, x});
	}
	
	for (int i = 0; i < q; i ++) {
		int a, b;
		cin >> a >> b;
		modify(a-1, {0, 0, 0, b});
		ans += query(0, n)[3];
	}
	
	cout << ans << "\n";
	
	return 0;
}

// 
