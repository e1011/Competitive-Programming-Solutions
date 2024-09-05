#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
	int n, r, q;
	cin >> n >> r >> q;
	
	vector <vector <int>> ans(r, vector <int> (r, 0));
	vector <vector <int>> members(n, vector <int> (2, n-1));
	
	cin >> members[0][1];
	for (int i = 1; i < n; i ++) {
		cin >> members[i][0] >> members[i][1];
		members[i][0] -= 1;
		members[i][1] -= 1;
	}
	
	cout << "\n\n";
	for (int i = 0; i < r; i ++) {
		vector <int> dp(n, 0);
		for (int j = n-1; j >= 0; j --) {
			if (members[j][1] == i) {
				dp[j] += 1;
			}
			dp[members[j][0]] += dp[j];
			ans[members[j][1]][i] += dp[j];
			cout << dp[j] << " ";
		}
		cout << "\n";
	}
	
	for (int i = 0; i < q; i ++) {
		int a, b;
		cin >> a >> b;
		cout << ans[a-1][b-1] << "\n";
	}
	
	return 0;
	
	
	
}

// either regions < 500, or the average number per region is < 500
// must be online
// if regions < 500
	// have a tree with size 500 array per node to show the regions
	// for each transition, add up the arrays
	// use the sum of arrays to find for each the ans for each node
	// store in 500x500 array, answer queries after
	// o(nsqrtr + q)
// if average per region is < 500
	// have euler tour with sum segtree
	// before each query, reset the segtree by modifying all 500 nodes
	// then, loop through 500 nodes and get sum
	// o(qsqrtrlogn)

// something wrong with ans array
