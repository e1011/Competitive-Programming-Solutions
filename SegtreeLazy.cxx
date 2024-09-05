#include <iostream>
#include <vector>

using namespace std;

int n, q;
vector <int> segtree, lazy1, lazy2, size;

void apply(int index, int val1, int val2) {
	if (val1 != 0) {
		segtree[index] = size[index]*(val1+val2);
		if (index < n) {
			lazy1[index] = val1;
			lazy2[index] = val2;
		}
	}
	else {
		segtree[index] += size[index]*val2;
		if (index < n) {
			lazy2[index] += val2;
		}
	}
}

void build(int index) {
	for (int i = (index+n)/2; i > 0; i /= 2) {
		segtree[i] = segtree[2*i]+segtree[2*i+1];
	}
}

void push(int index) {
	vector <int> path(0);
	for (int i = (index+n)/2; i > 0; i /= 2) {
		path.push_back(i);
	}
	for (int i = 0; i < path.size(); i ++) {
		if (lazy1[path[i]] != 0 || lazy2[path[i]] != 0) {
			apply(2*path[i], lazy1[path[i]], lazy2[path[i]]);
			apply(2*path[i]+1, lazy1[path[i]], lazy2[path[i]]);
			lazy1[path[i]] = 0;
			lazy2[path[i]] = 0;
		}
	}
}

void modify(int l, int r, int val1, int val2) {
	int l0 = l, r0 = r;
	for (l += n, r += n; l < r; l /= 2, r /= 2) {
		if (l % 2 == 1) {
			apply(l++, val1, val2);
		}
		if (r % 2 == 1) {
			apply(--r, val1, val2);
		}
	}
	build(l0);
	build(r0-1);
}

int query(int l, int r) {
	int lsum = 0, rsum = 0;
	push(l);
	push(r-1);
	for (int i = 0; i < 10; i ++) {
		cout << segtree[i] << " ";
	}
	cout << "\n";
	for (int i = 0; i < 5; i ++) {
		cout << lazy1[i] << " ";
	}
	cout << "\n";
	for (int i = 0; i < 5; i ++) {
		cout << lazy2[i] << " ";
	}
	cout << "\n";
	for (l += n, r += n; l < r; l /= 2, r /= 2) {
		if (l % 2 == 1) {
			lsum += segtree[l++];
		}
		if (r % 2 == 1) {
			rsum += segtree[--r];
		}
	}
	return lsum + rsum;
}

int main() {
	cin >> n >> q;
	
	segtree = vector <int> (2*n, 0);
	lazy1 = vector <int> (n, 0);
	lazy2 = vector <int> (n, 0);
	size = vector <int>(2*n, 0);
	for (int i = 2*n-1; i > 0; i --) {
		if (i >= n) {
			size[i] = 1;
		}
		else {
			size[i] = size[2*i]+size[2*i+1];
		}
	}
	
	for (int i = 0; i < n; i ++) {
		int x;
		cin >> x;
		modify(i, i+1, x, 0);
	}
	
	for (int i = 0; i < q; i ++) {
		int a, b, c, d;
		cin >> a >> b >> c;
		if (a == 1) {
			cin >> d;
			modify(b-1, c, 0, d);
		}
		else if (a == 2) {
			cin >> d;
			modify(b-1, c, d, 0);
		}
		else {
			cout << query(b-1, c) << "\n";
		}
	}
	
	
	return 0;
}

// apparently the build function can causes errors by replacing the lazy value if the children are not updated
// to solve, update children before calling it
// but how to reconcile build with multiple updates on the tree?

