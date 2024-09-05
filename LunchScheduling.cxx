#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
	int t;
	cin >> t;
	
	for (int i = 0; i < t; i ++) {
		int j, w, l;
		cin >> j >> w >> l;
		
		vector <vector <int>> jmeetings(0), wmeetings(0);
		for (int k = 0; k < j; k ++) {
			int a, b;
			cin >> a >> b;
			
			jmeetings.push_back({a, 0});
			jmeetings.push_back({b, 1});
		}
		for (int k = 0; k < w; k ++) {
			int a, b;
			cin >> a >> b;
			
			wmeetings.push_back({a, 0});
			wmeetings.push_back({b, 1});
		}
		sort(jmeetings.begin(), jmeetings.end());
		sort(wmeetings.begin(), wmeetings.end());
		
		set <vector <int>> jcompressed, wcompressed;
		vector <vector <int>> totalcompressed;
		int counter=0, laststart=0;
		for (int k = 0; k < 2*j; k ++) {
			if (jmeetings[k][1] == 0) {
				counter += 1;
				if (counter == 1) {
					laststart = jmeetings[k][0];
				}
			}
			else {
				counter -= 1;
				if (counter == 0) {
					totalcompressed.push_back({laststart, jmeetings[k][0], 0});
				}
			}
		}
		for (int k = 0; k < 2*w; k ++) {
			if (wmeetings[k][1] == 0) {
				counter += 1;
				if (counter == 1) {
					laststart = wmeetings[k][0];
				}
			}
			else {
				counter -= 1;
				if (counter == 0) {
					totalcompressed.push_back({laststart, wmeetings[k][0], 1});
				}
			}
		}
		
		sort(totalcompressed.begin(), totalcompressed.end());
		for (int k = 0; k < totalcompressed.size(); k ++) {
			if (totalcompressed[k][2] == 0) {
				jcompressed.insert({totalcompressed[k][0], totalcompressed[k][1], k});
			}
			else {
				wcompressed.insert({totalcompressed[k][0], totalcompressed[k][1], k});
			}
		}
		
		vector <vector <int>> dp(totalcompressed.size(), vector <int> (j+1, 1000000000));
		if (jcompressed.upper_bound({l}) != jcompressed.begin()) {
			dp[(*--jcompressed.upper_bound({l}))[2]][1] = 0;
		}
		if (wcompressed.upper_bound({l}) != wcompressed.begin()) {
			dp[(*--wcompressed.upper_bound({l}))[2]][0] = 1;
		}
		for (int k = 0; k < totalcompressed.size(); k ++) {
			for (int z = 0; z <= j; z ++) {
				if (z != j) {
					dp[(*--jcompressed.upper_bound({totalcompressed[k][1]+l}))[2]][z+1] = min(dp[(*--jcompressed.upper_bound({totalcompressed[k][1]+l}))[2]][z+1], dp[k][z]);
				}
				dp[(*--wcompressed.upper_bound({totalcompressed[k][1]+l}))[2]][z] = min(dp[(*--wcompressed.upper_bound({totalcompressed[k][1]+l}))[2]][z], dp[k][z]+1);
			}
		}
		
		int ans = 1000000000;
		for (int k = 0; k < totalcompressed.size(); k ++) {
			for (int z = 0; z <= j; z ++) {
				cout << dp[k][z] << " ";
				if (totalcompressed[k][1]+l > 80000000) {
					ans = min(ans, max(z, dp[k][z]));
				}
			}
			cout << "\n";
		}
		
		if (ans == 1000000000) {
			cout << "Case #" << t << ": Lunchtime\n";
		}
		else {
			cout << "Case #" << t << ": " << ans << "\n";
		}
	}
	
	return 0;
}

