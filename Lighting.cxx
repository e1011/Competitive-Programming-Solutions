#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, k, ans=0;
	cin >> n >> k;
	
	string s;
	cin >> s;
	reverse(s.begin(), s.end());
	
	vector <vector <long long>> dp1(k+2, vector <long long> (2, 0));
	vector <vector <long long>> dp2(k+2, vector <long long> (2, 0));
	dp1[0][0] = 1;
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < k+1; j ++) {
			if (s[i] == '0') {
				dp2[j][0] += dp1[j][0];
				dp2[j+1][0] += dp1[j][1];
				dp2[j+1][0] += dp1[j][0];
				dp2[j][1] += dp1[j][1];
				dp2[j][0] %= 1000000007;
				dp2[j+1][0] %= 1000000007;
				dp2[j][1] %= 1000000007;
			}
			else {
				dp2[j+1][0] += dp1[j][0];
				dp2[j][1] += dp1[j][1];
				dp2[j][1] += dp1[j][0];
				dp2[j+1][1] += dp1[j][1];
				dp2[j+1][0] %= 1000000007;
				dp2[j][1] %= 1000000007;
				dp2[j+1][1] %= 1000000007;
			}
		}
		dp1 = dp2;
		dp2 = vector <vector <long long>> (k+2, vector <long long> (2, 0));
	}
	
	
	ans = dp1[k][0];
	if (k > 0) {
		ans += dp1[k-1][1];
	}
	cout << ans % 1000000007 << "\n";
	
	return 0;
}


