#include <iostream>
#include <vector>

using namespace std;

int n, q;
vector <vector <int>> segtree(0);

// max seq, unpaired l brackets, unpaired r brackets
vector <int> comb(vector <int> a, vector <int> b) {
	if (a.size() == 1) {
		return b;
	}
	if (b.size() == 1) {
		return a;
	}
	
	int newseq = min(a[1], b[2]);
	return {a[0]+b[0]+2*newseq, 
		a[1]+b[1]-newseq, 
		a[2]+b[2]-newseq};
}

void modify(int index, vector <int> val) {
	segtree[index+n] = val;
	for (int i = (index+n)/2; i > 0; i /= 2) {
		segtree[i] = comb(segtree[2*i], segtree[2*i+1]);
	}
}

int query(int l, int r) {
	vector <int> lsum = {0}, rsum = {0};
	for (l += n, r += n; l < r; l /= 2, r /= 2) {
		if (l % 2 == 1) {
			lsum = comb(lsum, segtree[l++]); 
		}
		if (r % 2 == 1) {
			rsum = comb(segtree[--r], rsum);
		}
	}
	return comb(lsum, rsum)[0];
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string s;
	cin >> n >> q >> s;
	
	segtree = vector <vector <int>> (2*n, vector <int> (1, 0));
	for (int i = 0; i < n; i ++) {
		if (s[i] == '(') {
			modify(i, {0, 1, 0});
		}
		else {
			modify(i, {0, 0, 1});
		}
	}
	
	for (int i = 0; i < q; i ++) {
		int a, b, c;
		cin >> a >> b;
		if (a == 1) {
			cin >> c;
			cout << query(b-1, c) << "\n";
		}
		else {
			modify(b-1, {0, !segtree[n+b-1][1], !segtree[n+b-1][2]});
		}
	}
	
	return 0;
}

