#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// static range inversions

// sum segtree for inversions
int n, q;
vector <int> segtree(0);

void modify(int index, int val) {
	segtree[index+n] += val;
	for (int i = (index+n)/2; i > 0; i /= 2) {
		segtree[i] = segtree[2*i] + segtree[2*i+1];
	}
}

int query(int l, int r) {
	int lsum = 0, rsum = 0;
	for (l += n, r += n; l < r; l /= 2, r /= 2) {
		if (l % 2 == 1) {
			lsum = lsum + segtree[l++]; 
		}
		if (r % 2 == 1) {
			rsum = rsum + segtree[--r];
		}
	}
	return lsum + rsum;
}

// custom comparator for mo algorithm
bool comp(vector <int> a, vector <int> b) {
	if (a[0]/316 == b[0]/316) {
		return a[1] < b[1];
	}
	return a[0] < b[0];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> q;
	
	vector <int> arr(n, 0);
	vector <vector <int>> arr2(n, vector <int> (2, 0));
	vector <vector <int>> queries(q, vector <int> (3, 0));
	vector <long long> ans(q, 0);
	segtree = vector <int> (2*n, 0);
	
	// coord compress
	for (int i = 0; i < n; i ++) {
		cin >> arr2[i][0];
		arr2[i][1] = i;
	}
	sort(arr2.begin(), arr2.end());
	for (int i = 1; i < n; i ++) {
		if (arr2[i][0] > arr2[i-1][0]) {
			arr[arr2[i][1]] = arr[arr2[i-1][1]] + 1;
		}
		else {
			arr[arr2[i][1]] = arr[arr2[i-1][1]];
		}
	}
	
	// answer queries
	for (int i = 0; i < q; i ++) {
		cin >> queries[i][0] >> queries[i][1];
		queries[i][1] -= 1;
		queries[i][2] = i;
	}
	sort(queries.begin(), queries.end(), comp);
	
	
	long long inversions = 0, p1=0, p2=-1;
	for (int i = 0; i < q; i ++) {
		while (p2 < queries[i][1]) {
			p2 += 1;
			modify(arr[p2], 1);
			inversions += query(arr[p2]+1, n);
		}
		while (p2 > queries[i][1]) {
			modify(arr[p2], -1);
			inversions -= query(arr[p2]+1, n);
			p2 -= 1;
		}
		while (p1 < queries[i][0]) {
			modify(arr[p1], -1);
			inversions -= query(0, arr[p1]);
			p1 += 1;
		}
		while (p1 > queries[i][0]) {
			p1 -= 1;
			modify(arr[p1], 1);
			inversions += query(0, arr[p1]);
		}
		ans[queries[i][2]] = inversions;
	}
	
	for (int i = 0; i < q; i ++) {
		cout << ans[i] << "\n";
	}
	
	return 0;
}

