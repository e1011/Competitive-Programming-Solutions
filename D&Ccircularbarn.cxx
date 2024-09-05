#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

vector <long long> arr, ps;
vector <vector <long long>> dp;

void dc(int l, int r, int optl, int optr, int k) {
	if (l > r) {
		return;
	}
	
	long long optval=1000000000000000000;
	int optindex, mid=(l+r)/2;
	for (int i = optl; i <= min(mid, optr); i ++) {
		if (dp[k-1][i-1]+dp[0][mid]-dp[0][i-1]-(i*(ps[mid]-ps[i-1])) < optval) {
			optval = dp[k-1][i-1]+dp[0][mid]-dp[0][i-1]-(i*(ps[mid]-ps[i-1]));
			optindex = i;
		}
	}
	
	dp[k][mid] = optval;
	dc(l, mid-1, optl, optindex, k);
	dc(mid+1, r, optindex, optr, k);
}

int main() {
	freopen("cbarn.in", "r", stdin);
	freopen("cbarn.out", "w", stdout);
	int n, k;
	cin >> n >> k;
	
	long long ans=1000000000000000000;
	arr = vector <long long> (n, 0);
	for (int i = 0; i < n; i ++) {
		cin >> arr[i];
	}
	
	for (int _ = 0; _ < n; _ ++) {
		ps = vector <long long> (n, 0);
		dp = vector <vector <long long>> (k, vector <long long> (n, 0));
		
		ps[0] = arr[0];
		for (int i = 1; i < n; i ++) {
			ps[i] = arr[i]+ps[i-1];
			dp[0][i] = i*arr[i]+dp[0][i-1];
		}
		
		for (int i = 1; i < k; i ++) {
			dc(0, n-1, 1, n-1, i);
		}
		ans = min(ans, dp[k-1][n-1]);
		
		int x = arr[0];
		for (int i = 0; i < n; i ++) {
			arr[i] = arr[i+1];
		}
		arr[n-1] = x;
	}
	
	cout << ans << "\n";
}


