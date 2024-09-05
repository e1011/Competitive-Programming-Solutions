#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("threesum.in", "r", stdin);
	freopen("threesum.out", "w", stdout);
	
	int n, q;
	cin >> n >> q;
	
	vector <int> arr(n, 0);
	for (int i = 0; i < n; i ++) {
		cin >> arr[i];
	}
	
	vector <vector <long long>> dp(n, vector <long long> (n, 0));
	vector <int> count(2000001, 0);
	vector <int> mostrecent(2000001, 0);
	for (int i = 0; i < n-2; i ++) {
		for (int j = i+2; j < n; j ++) {
			if (mostrecent[arr[j-1]+1000000] != i) { 
				mostrecent[arr[j-1]+1000000] = i;
				count[arr[j-1]+1000000] = 0;
			}
			count[arr[j-1]+1000000] += 1;
			if (abs(arr[i]+arr[j]) <= 1000000 && mostrecent[-arr[i]-arr[j]+1000000] == i) {
				dp[i][j] = count[-arr[i]-arr[j]+1000000];
			}
		}
	}
	
	for (int i = 0; i < n; i ++) {
		long long sum=0;
		for (int j = i+2; j < n; j ++) {
			sum += dp[i][j];
			dp[i][j] = sum;
		}
	}
	for (int i = n-1; i >= 2; i --) {
		long long sum = 0;
		for (int j = i-2; j >= 0; j --) {
			sum += dp[j][i];
			dp[j][i] = sum;
		}
	}
	
	for (int i = 0; i < q; i ++) {
		int a, b;
		cin >> a >> b;
		cout << dp[a-1][b-1] << "\n";
	}
	
	
	
	return 0;
}

