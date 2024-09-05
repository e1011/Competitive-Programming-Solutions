#include <iostream>
#include <vector>

using namespace std;

bool type(char c) {
	if (c == '+') {
		return true;
	}
	return false;
}

int main() {
	int t;
	cin >> t;
	
	for (int _ = 0; _ < t; _ ++) {
		int n;
		string s1 = "", s2 = "", s3, s4;
		cin >> n >> s3 >> s4;
		
		for (int i = 0; i < n; i ++) {
			if (s3[i] != '1') {
				s1.push_back(s3[i]);
			}
			if (s3[i] == '0') {
				s1 = "0";
			}
			if (s4[i] != '1') {
				s2.push_back(s4[i]);
			}
			if (s4[i] == '0') {
				s2 = "0";
			}
		}
		
		// k == 0, last chosen is arr1
		vector <vector <vector <long long>>> dp(s1.size()+1, vector <vector <long long>> (s2.size()+1, vector <long long> (2, 0)));
		dp[0][0][0] = 1;
		
		for (int i = 0; i <= s1.size(); i ++) {
			for (int j = 0; j <= s2.size(); j ++) {
				if (i != s1.size()) {
					if (j == 0 || type(s1[i]) != type(s2[j-1])) {
						dp[i+1][j][0] += dp[i][j][1];
						dp[i+1][j][0] %= 1000000007;
					}
					dp[i+1][j][0] += dp[i][j][0];
					dp[i+1][j][0] %= 1000000007;
				}
				if (j != s2.size()) {
					dp[i][j+1][1] += dp[i][j][0];
					dp[i][j+1][1] += dp[i][j][1];
					dp[i][j+1][1] %= 1000000007;
				}
			}
		}
		cout << (dp[s1.size()][s2.size()][0]+dp[s1.size()][s2.size()][1]) % 1000000007 << "\n";
	}
	
	
	
	return 0;
}

