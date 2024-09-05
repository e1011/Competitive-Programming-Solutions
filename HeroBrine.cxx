#include <iostream>
#include <vector>

using namespace std;

long long n2 = 2000000;

vector <long long> segtree(4000000, 0);

long long comb(long long a, long long b) {
	return a+b;
}

void modify(int index, long long val) {
	segtree[index+n2] += val;
	for (int i = (index+n2)/2; i > 0; i /= 2) {
		segtree[i] = comb(segtree[2*i], segtree[2*i+1]);
	}
}

long long query(int l, int r) {
	long long lsum = 0, rsum = 0;
	for (l += n2, r += n2; l < r; l /= 2, r /= 2) {
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
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i ++) {
		int x;
		cin >> x;
		if (x != i) {
			throw;
		}
	}
	
	vector <vector <long long>> ores(n, vector <long long> (0));
	vector <long long> ans(n, 0);
	for (int i = 0; i < n; i ++) {
		int m;
		cin >> m;
		for (int j = 0; j < m; j ++) {
			int x;
			cin >> x;
			ores[i].push_back(x);
			if (x > 1000000) {
				throw;
			}
		}
	}
	
	vector <long long> frequency(1000001, 0);
	for (int i = n-1; i >= 0; i --) {
		if (i != n-1) {
			ans[i] = ans[i+1];
		}
		for (int j = 0; j < ores[i].size(); j ++) {
			if (frequency[ores[i][j]] == 0) {
				frequency[ores[i][j]] += 1;
				modify(1, 1);
				ans[i] = max(ans[i], query(1, 2000001));
			}
			else {
				frequency[ores[i][j]] += 1;
				modify(frequency[ores[i][j]], 1);
				modify(frequency[ores[i][j]]-1, -1);
				ans[i] = max(ans[i], frequency[ores[i][j]]*query(frequency[ores[i][j]], 2000001));
			}
		}
	}
	
	for (int i = 0; i < n; i ++) {
		cout << ans[i] << "\n";
	}
	
	
	return 0;
}

