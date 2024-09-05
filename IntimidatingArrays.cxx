#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int n, q;
vector <int> segtree(0);

int comb(int a, int b) {
	return a+b;
}

void modify(int index, int val) {
	segtree[index+n] += val;
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
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> q;
	
	segtree = vector <int> (2*n, 0);
	vector <int> arr(n, 0);
	for (int i = 0; i < n; i ++) {
		cin >> arr[i];
	}
	
	vector <vector <int>> queries(q, vector <int> (3, 0));
	vector <int> ans(q, 0);
	for (int i = 0; i < q; i ++) {
		cin >> queries[i][0] >> queries[i][1];
		queries[i][0] -= 1;
		queries[i][2] = i;
	}
	sort(queries.begin(), queries.end());
	for (int i = 0; i < q; i ++) {
	}
	
	stack <vector <int>> monotonic;
	int qpointer = q-1;
	
	for (int i = n-1; i >= 0; i --) {
		while (!monotonic.empty() && arr[i] > monotonic.top()[0]) {
			modify(monotonic.top()[1], -1);
			monotonic.pop();
		}
		modify(i, 1);
		monotonic.push({arr[i], i});
		
		while (qpointer >= 0 && queries[qpointer][0] == i) {
			ans[queries[qpointer][2]] = query(queries[qpointer][0], queries[qpointer][1]);
			qpointer -= 1;
		}
	}
	
	for (int i = 0; i < q; i ++) {
		cout << ans[i] << "\n";
	}
	
	return 0;
}

