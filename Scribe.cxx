#include <vector>
#include <iostream>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	
	// dp[index][# occurrences][under][started]
	vector <vector <vector <vector <int>>>> dp(10, vector <vector <vector <int>>> (10, vector <vector <int>> (2, vector <int> (2, 0))));
	vector <int> ans(10, 0);
	
	for (int _ = 0; _ < t; _ ++) {
		string x1="000000000", y1="000000000", x2, y2;
		int x;
		cin >> x >> y2;
		x -= 1;
		x2 = to_string(x);
		for (int i = 0; i < x2.size(); i ++) {
			x1[i+9-(int)x2.size()] = x2[i];
		}
		
		if (y2 == "1000000000") {
			ans = {788888898, 900000001, 900000000, 900000000, 900000000, 900000000, 900000000, 900000000, 900000000, 900000000};
		}
		else {
			for (int i = 0; i < y2.size(); i ++) {
				y1[i+9-(int)y2.size()] = y2[i];
			}
			
			ans = vector <int> (10, 0);
			for (int x = 0; x < 10; x ++) {
				dp[0][0][0][0] = 1;
				for (int i = 0; i < 9; i ++) {
					for (int j = 0; j <= i; j ++) {
						for (int k = 0; k < 10; k ++) {
							bool occurrence = (x == k), same = (k == (y1[i]-'0')), zero = (k == 0);
							if (k <= (y1[i]-'0')) {
								dp[i+1][j+(occurrence && x != 0)][!same][!zero] += dp[i][j][0][0];
								dp[i+1][j+occurrence][!same][1] += dp[i][j][0][1];
							}
							dp[i+1][j+(occurrence && x != 0)][1][!zero] += dp[i][j][1][0];
							dp[i+1][j+occurrence][1][1] += dp[i][j][1][1];
						}
						dp[i][j][0][0] = 0;
						dp[i][j][0][1] = 0;
						dp[i][j][1][0] = 0;
						dp[i][j][1][1] = 0;
					}
				}
				for (int i = 0; i < 10; i ++) {
					ans[x] += i*(dp[9][i][0][1]+dp[9][i][1][1]);
					dp[9][i][0][0] = 0;
					dp[9][i][0][1] = 0;
					dp[9][i][1][0] = 0;
					dp[9][i][1][1] = 0;
				}
			}
		}
		
		
		for (int x = 0; x < 10; x ++) {
			dp[0][0][0][0] = 1;
			for (int i = 0; i < 9; i ++) {
				for (int j = 0; j <= i; j ++) {
					for (int k = 0; k < 10; k ++) {
						bool occurrence = (x == k), same = (k == (x1[i]-'0')), zero = (k == 0);
						if (k <= (x1[i]-'0')) {
							dp[i+1][j+(occurrence && x != 0)][!same][!zero] += dp[i][j][0][0];
							dp[i+1][j+occurrence][!same][1] += dp[i][j][0][1];
						}
						dp[i+1][j+(occurrence && x != 0)][1][!zero] += dp[i][j][1][0];
						dp[i+1][j+occurrence][1][1] += dp[i][j][1][1];
					}
					dp[i][j][0][0] = 0;
					dp[i][j][0][1] = 0;
					dp[i][j][1][0] = 0;
					dp[i][j][1][1] = 0;
				}
			}
			for (int i = 0; i < 10; i ++) {
				ans[x] -= i*(dp[9][i][0][1]+dp[9][i][1][1]);
				dp[9][i][0][0] = 0;
				dp[9][i][0][1] = 0;
				dp[9][i][1][0] = 0;
				dp[9][i][1][1] = 0;
			}
		}
		
		
		for (int i = 0; i < 10; i ++) {
			cout << ans[i] << " ";
		}
		cout << "\n";
		
	}
	
	
	return 0;
}
