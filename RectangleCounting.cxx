#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, q;
vector <int> segtree1(0);

int comb1(int a, int b) {
	return (a + b);
}

void modify1(int index, int val) {
	segtree1[index+n] += val;
	for (int i = (index+n)/2; i > 0; i /= 2) {
		segtree1[i] = comb1(segtree1[2*i], segtree1[2*i+1]);
	}
}

int query1(int l, int r) {
	int lsum = 0, rsum = 0;
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

vector <int> segtree2(0);

int comb2(int a, int b) {
	return (a + b);
}

void modify2(int index, int val) {
	segtree2[index+n] += val;
	for (int i = (index+n)/2; i > 0; i /= 2) {
		segtree2[i] = comb2(segtree2[2*i], segtree2[2*i+1]);
	}
}

int query2(int l, int r) {
	int lsum = 0, rsum = 0;
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
	int n;
	cin >> n;
	long long ans = 0;
	
	segtree1 = vector <int> (1000002, 0);
	segtree2 = vector <int> (1000002, 0);
	vector <vector <int>> edges(0);
	
	for (int i = 0; i < n; i ++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		
		edges.push_back({a, 0, b, d});
		edges.push_back({c, 1, b, d});
	}
	
	sort(edges.begin(), edges.end());
	for (int i = 0; i < n; i ++) {
		if (edges[i][1] == 0) {
			modify2(edges[i][2], 1);
			modify1(edges[i][2], 1);
			modify1(edges[i][3]-1, -1);
			ans += query2(edges[i][2], edges[i][3]+1);
			ans += query1(0, edges[i][2]);
		}
		else {
			modify2(edges[i][2], -1);
			modify1(edges[i][2], -1);
			modify1(edges[i][2]-1, 1);
		}
	}
	
	cout << ans << "\n";
	
	return 0;
}

