#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector <int> segtree(200002, 0);

int comb(int a, int b) {
	return max(a, b);
}

void modify(int index, int val) {
	segtree[index+n] = max(segtree[index+n], val);
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

bool comp(vector <int> a, vector <int> b) {
	if (a[1] == b[1]) {
		return a[0] < b[0];
	}
	return a[1] < b[1];
}

int main() {
	cin >> n;
	
	vector <vector <int>> arr(n, vector <int> (2, 0));
	
	for (int i = 0; i < n; i ++) {
		cin >> arr[i][0] >> arr[i][1];
	}
	sort(arr.begin(), arr.end(), comp);
	for (int i = 0; i < n; i ++) {
		arr[i][1] = i;
	}
	sort(arr.begin(), arr.end());
	for (int i = 0; i < n; i ++) {
		arr[i][0] = i;
	}
	reverse(arr.begin(), arr.end());
	
	for (int i = 0; i < n; i ++) {
		modify(arr[i][1], query(0, arr[i][1]) + 1);
	}
	
	cout << query(0, 100001) << "\n";
	
	return 0;
}

