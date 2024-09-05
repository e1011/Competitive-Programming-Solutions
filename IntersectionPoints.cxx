#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> segtree(0);

int comb(int a, int b) {
	return a+b;
}

void modify(int index, int val) {
	segtree[index+2000001] += val;
	for (int i = (index+2000001)/2; i > 0; i /= 2) {
		segtree[i] = comb(segtree[2*i], segtree[2*i+1]);
	}
}

int query(int l, int r) {
	int lsum = 0, rsum = 0;
	for (l += 2000001, r += 2000001; l < r; l /= 2, r /= 2) {
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
	long long n, ans=0;
	cin >> n;
	
	vector <vector <int>> lines(n, vector <int> (4, 0));
	for (int i = 0; i < n; i ++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		y1 += 1000000;
		y2 += 1000000;
		if (y1 == y2) {
			lines.push_back({x1, y1, 0});
			lines.push_back({x2, y2, 1});
		}
		else {
			lines.push_back({x1, y1, x2, y2});
		}
	}
	
	sort(lines.begin(), lines.end());
	segtree = vector <int> (4000002, 0);
	for (int i = 0; i < lines.size(); i ++) {
		if (lines[i].size() == 3) {
			if (lines[i][2] == 0) {
				modify(lines[i][1], 1);
			}
			else {
				modify(lines[i][1], -1);
			}
		}
		else {
			ans += query(lines[i][1], lines[i][3]+1);
		}
	}
	
	cout << ans << "\n";
	
	return 0;
}

