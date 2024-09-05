#include <iostream>
#include <vector>

using namespace std;

int main() {
	long long n, a, b, c;
	cin >> n >> a >> b >> c;
	
	vector <vector <long long>> dp(n, vector <long long> (101, 0));
	vector <long long> arr(n, 0);
	
	for (int i = 0; i < n; i ++) {
		cin >> arr[i];
	}
	
	for (int i = 0; i < 101; i ++) {
		dp[0][i] = c*(arr[0]-i)*(arr[0]-i) + i*b + i*a;
	}
	for (int i = 1; i < n; i ++) {
		vector <long long> minfromtop(101, 1000000000000000);
		vector <long long> minfrombottom(101, 1000000000000000);
		for (int j = 100; j >= 0; j --) {
			minfromtop[j] = dp[i-1][j];
			if (j != 100) {
				minfromtop[j] = min(minfromtop[j], minfromtop[j+1]);
			}
		}
		for (int j = 0; j < 101; j ++) {
			minfrombottom[j] = dp[i-1][j]+(b*(100-j));
			if (j != 0) {
				minfrombottom[j] = min(minfrombottom[j], minfrombottom[j-1]);
			}
		}
		
		for (int j = 0; j < 101; j ++) {
			dp[i][j] = minfromtop[j];
			if (j != 0) {
				dp[i][j] = min(minfromtop[j], minfrombottom[j-1]-(b*(100-j)));
			}
			dp[i][j] += c*(arr[i]-j)*(arr[i]-j);
			dp[i][j] += a*j;
		}
	}
	
	long long ans = 1000000000000000;
	for (int i = 0; i < 101; i ++) {
		ans = min(ans, dp[n-1][i]);
	}
	
	/*
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < 10; j ++) {
			cout << dp[i][j] << " ";
		}
		cout << "\n";
	}
	* */
	
	cout << ans << "\n";
	
	
	return 0;
}

