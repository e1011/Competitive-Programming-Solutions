#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// initialize this to 2*n length
int n;
vector <int> segtree(0);

int comb(int a, int b) {
	return (a+b) % 998244353;
}

void modify(int index, int val) {
	segtree[index+n] += val;
	segtree[index+n] %= 998244353;
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
	int t;
	cin >> t;
	
	for (int i = 0; i < t; i ++) {
		long long ans=0;
		cin >> n;
		
		vector <int> arr(n, 0), dpl(n, 0), dpr(n, 0);
		vector <pair <int, int>> arr2(n, pair <int, int> (2, 0));
		for (int j = 0; j < n; j ++) {
			cin >> arr2[j].first;
			arr2[j].second = j;
		}
		sort(arr2.begin(), arr2.end());
		
		for (int j = 0; j < n; j ++) {
			if (j != 0 && arr2[j].first == arr2[j-1].first) {
				arr[arr2[j].second] = arr[arr2[j-1].second];
			}
			else {
				arr[arr2[j].second] = j;
			}
		}
		
		segtree = vector <int> (2*n, 0);
		for (int j = 0; j < n; j ++) {
			dpl[j] = query(0, arr[j])+1;
			dpl[j] %= 998244353;
			modify(arr[j], dpl[j]);
		}
		segtree = vector <int> (2*n, 0);
		for (int j = n-1; j >= 0; j --) {
			dpr[j] = query(0, arr[j])+1;
			dpr[j] %= 998244353;
			modify(arr[j], dpr[j]);
		}
		
		for (int j = 0; j < n; j ++) {
			ans += (long long)dpl[j]*(long long)dpr[j];
			ans %= 998244353;
		}
		
		cout << ans << "\n";
	}
	
	return 0;
}

