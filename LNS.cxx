#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector <int> segtree(0);

int comb(int a, int b) {
	return max(a, b);
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
	cin >> n;
	segtree = vector <int> (2*n, 0);
	vector <vector <int>> arr(0);
	vector <int> arr1(n, 0);
	
	for (int i = 0; i < n; i ++) {
		int x;
		cin >> x;
		arr.push_back({x, i});
	}
	
	sort(arr.begin(), arr.end());
	int counter = 0;
	for (int i = 1; i < n; i ++) {
		if (arr[i][0] > arr[i-1][0]) {
			counter += 1;
		}
		arr1[arr[i][1]] = counter;
	}
	arr1[arr[0][1]] = 0;
	
	for (int i = 0; i < n; i ++) {
		modify(arr1[i], query(arr1[i], n)+1);
	}
	
	cout << query(0, n) << "\n";
	
	return 0;
}

