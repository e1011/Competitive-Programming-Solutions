#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, uniquecolors=0;
	cin >> n;
	
	vector <int> arr(n, 0), leftmost(n, -1), rightmost(n, 0);
	// dp[l][r] is max points gainable by M in l and r inclusive
	vector <vector <int>> dp(n, vector <int> (n, 0));
	
	for (int i = 0; i < n; i ++) {
		cin >> arr[i];
		if (leftmost[arr[i]-1] == -1) {
			leftmost[arr[i]-1] = i;
			uniquecolors += 1;
		}
		rightmost[arr[i]-1] = i;
	}
	/*
	for (int i = 0; i < n; i ++) {
		if (rightmost[i] != -1) {
			dp[rightmost[i]][rightmost[i]] = 1;
		}
		if (leftmost[i] != -1) {
			dp[leftmost[i]][leftmost[i]] = 1;
		}
	}
	* */
	for (int i = n-1; i >= 0; i --) {
		for (int j = i; j < n; j ++) {
			int leftpoint = (i == leftmost[arr[i]-1] && j >= rightmost[arr[i]-1]);
			int rightpoint = (j == rightmost[arr[j]-1] && i <= leftmost[arr[j]-1]);

			if (j == i+1 || j == i) {
				dp[i][j] = max(leftpoint, rightpoint);
			}
			else {
				//cout << leftpoint << ", " << rightpoint << "\n";
				dp[i][j] = max(min(dp[i+2][j], dp[i+1][j-1])+leftpoint, min(dp[i][j-2], dp[i+1][j-1])+rightpoint);
			}
		}
	}
	/*
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < n; j ++) {
			cout << dp[i][j] << " ";
		}
		cout << "\n";
	}
	* */
	
	cout << dp[0][n-1] << ":" << uniquecolors-dp[0][n-1] << "\n";
	
	return 0;
}

