#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int n, q;
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
	cin >> n >> q;
	
	vector <int> ans(q, 0), arr(n, 0);
	vector <vector <int>> queries(0);
	segtree = vector <int> (2*n, 0);
	for (int i = 0; i < n; i ++) {
		cin >> arr[i];
		queries.push_back({arr[i], -1, i});
	}
	for (int i = 0; i < q; i ++) {
		int a, b, c;
		cin >> a >> b >> c;
		queries.push_back({c, a-1, b-1, i});
	}
	
	sort(queries.begin(), queries.end());
	modify(0, 1);
	
	set <vector <int>> s;
	s.insert({0, 0});
	s.insert({n-1, 1});
	
	for (int i = 0; i < queries.size(); i ++) {
		// remove a column
		if (queries[i][1] == -1) {
			s.erase({queries[i][2], 0});
			s.erase({queries[i][2], 1});
			modify(queries[i][2], 0);
			if (queries[i][2] > 0 && arr[queries[i][2]-1] > queries[i][0]) {
				s.insert({queries[i][2]-1, 1});
			}
			if (queries[i][2]+1 < n && arr[queries[i][2]+1] > queries[i][0]) {
				s.insert({queries[i][2]+1, 0});
				modify(queries[i][2]+1, 1);
			}
		}
		// query number of islands
		else {
			int islands = query(queries[i][1], queries[i][2]+1);
			//cout << queries[i][1] << ", " << queries[i][2]+1 << ", " << islands << "\n";
			//cout << arr[queries[i][1]] << ", " << s.size() << "\n";
			if (arr[queries[i][1]] > queries[i][0] && s.lower_bound({queries[i][1], -1}) != s.end() && (*s.lower_bound({queries[i][1], -1}))[1] == 1) {
				islands += 1;
			}
			ans[queries[i][3]] = islands;
		}
	}
	
	for (int i = 0; i < q; i ++) {
		cout << ans[i] << "\n";
	}
	
	
	return 0;
}

