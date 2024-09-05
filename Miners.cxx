#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	string s;
	cin >> n >> s;
	
	vector <vector <vector <int>>> dp(n+1, vector <vector <int>> (9, vector <int> (9, -1)));
	dp[0][0][0] = 0;
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < 9; j ++) {
			for (int k = 0; k < 9; k ++) {
				if (dp[i][j][k] == 0) {
					if (i == 0) {
						if (s[i] == 'M') {
							dp[i+1][0][0] = dp[i][j][k]+1;
						}
						if (s[i] == 'F') {
							dp[i+1][5][0] = dp[i][j][k]+1;
							dp[i+1][0][5] = dp[i][j][k]+1;
						}
						if (s[i] == 'F') {
							dp[i+1][9][0] = dp[i][j][k]+1;
							dp[i+1][0][9] = dp[i][j][k]+1;
						}
					}
					else if (i == 1) {
						if (s[i] == 'M') {
							dp[i+1][0][0] = dp[i][j][k]+1;
						}
						if (s[i] == 'F') {
							dp[i+1][5][0] = dp[i][j][k]+1;
							dp[i+1][0][5] = dp[i][j][k]+1;
						}
						if (s[i] == 'F') {
							dp[i+1][9][0] = dp[i][j][k]+1;
							dp[i+1][0][9] = dp[i][j][k]+1;
						}
					}
					else {
						if (s[i] == 'M') {
							dp[i+1][0][0] = dp[i][j][k]+1;
						}
						if (s[i] == 'F') {
							dp[i+1][5][0] = dp[i][j][k]+1;
							dp[i+1][0][5] = dp[i][j][k]+1;
						}
						if (s[i] == 'F') {
							dp[i+1][9][0] = dp[i][j][k]+1;
							dp[i+1][0][9] = dp[i][j][k]+1;
						}
					}
				}
			}
		}
	}
	
	
	return 0;
}

// dp[index][i][j] = number of coal
// i is the last shipment for mine 1
// j is the last shipment for mine 2
// 0 = MM or M or nothing
// 1 = MF
// 2 = MB
// 3 = FM
// 4 = FF or F
// 5 = FB
// 6 = BM
// 7 = BF
// 8 = BB or B
