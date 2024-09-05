#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t;
	cin >> t;
	
	for (int i = 0; i < t; i ++) {
		long long a, b, r;
		cin >> a >> b >> r;
		if (a > b) {
			swap(a, b);
		}
		
		// dp[current bit][positive or negative difference][used less than r]
		vector <vector <vector <long long>>> dp(65, vector <vector <long long>> (2, vector <long long> (2, 2000000000000000000)));
		dp[64][0][0] = b-a;
		for (long long j = 64; j >= 1; j --) {
			// if bit shows up in a but not b. switching a bit will decrease a, increase b
			if ((a & ((long long)1 << (j-1))) && !(b & ((long long)1 << (j-1)))) {
				// negative turn positive
				if (dp[j][1][1] - (1 << j) < 0) {
					dp[j-1][0][1] = min(dp[j-1][0][1], -(dp[j][1][1] - ((long long)1 << j)));
				}
				// negative stay negative
				else {
					dp[j-1][1][1] = min(dp[j-1][1][1], dp[j][1][1]-((long long)1 << j));
				}
				if (r & ((long long)1 << j)) {
					dp[j-1][0][1] = min(dp[j-1][0][1], dp[j][0][0]);
					dp[j-1][1][1] = min(dp[j-1][1][1], dp[j][1][0]);
					// negative turn positive
					if (dp[j][1][0] - ((long long)1 << j) < 0) {
						dp[j-1][0][0] = min(dp[j-1][0][0], -(dp[j][1][0] - ((long long)1 << j)));
					}
					// negative stay negative
					else {
						dp[j-1][1][0] = min(dp[j-1][1][0], dp[j][1][0]-((long long)1 << j));
					}
				}
			}
			// if bit shows up in b but not a. switching a bit will decrease b, increase a
			else if (!(a & ((long long)1 << (j-1))) && (b & ((long long)1 << (j-1)))) {
				// positive turn negative
				if (dp[j][0][1] - (1 << j) < 0) {
					dp[j-1][1][1] = min(dp[j-1][1][1], -(dp[j][0][1] - ((long long)1 << j)));
				}
				// positive stay positive
				else {
					dp[j-1][0][1] = min(dp[j-1][0][1], dp[j][0][1]-((long long)1 << j));
				}
				if (r & ((long long)1 << j)) {
					// do nothing, make r smaller
					dp[j-1][0][1] = min(dp[j-1][0][1], dp[j][0][0]);
					dp[j-1][1][1] = min(dp[j-1][1][1], dp[j][1][0]);
					// positive turn negative
					if (dp[j][0][0] - ((long long)1 << j) < 0) {
						dp[j-1][1][0] = min(dp[j-1][1][0], -(dp[j][0][0] - ((long long)1 << j)));
					}
					// positive stay positive
					else {
						dp[j-1][0][0] = min(dp[j-1][0][0], dp[j][0][0]-((long long)1 << j));
					}
				}
			}
			dp[j-1][0][1] = min(dp[j-1][0][1], dp[j][0][1]);
			dp[j-1][1][1] = min(dp[j-1][1][1], dp[j][1][1]);
			dp[j-1][0][0] = min(dp[j-1][0][0], dp[j][0][0]);
			dp[j-1][1][0] = min(dp[j-1][1][0], dp[j][1][0]);
		}
		for (int j = 64; j >= 0; j --) {
			cout << j << ", " << dp[j][0][0] << ", " << dp[j][0][1] << ", " << dp[j][1][0] << ", " << dp[j][1][1] << "\n";
		}
		
		cout << min(dp[0][0][0], min(dp[0][0][1], min(dp[0][1][0], dp[0][1][1]))) << "\n";
	}
	
	
	return 0;
}

