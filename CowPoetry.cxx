#include <iostream>
#include <vector>

// x^y mod p
long long exp(long long x, long long y, long long p) {
	long long res = 1; x %= p;
	while (y) {
		if (y & 1) {
			res *= x; res %= p; 
		}
		x *= x; x %= p;
		y >>= 1;
	}
	return res;
}

using namespace std;

int main() {
	freopen("poetry.in", "r", stdin);
	freopen("poetry.out", "w", stdout);
	
	int n, m, k;
	cin >> n >> m >> k;
	
	vector <int> waystoend(n, 0);
	vector <int> dp(k, 0);
	vector <vector <int>> words(n, vector <int> (2, 0));
	
	for (int i = 0; i < n; i ++) {
		cin >> words[i][0] >> words[i][1];
	}
	
	dp[0] = 1;
	for (int i = 0; i < k; i ++) {
		for (int j = 0; j < n; j ++) {
			if (i+words[j][0] < k) {
				dp[i+words[j][0]] += dp[i];
				dp[i+words[j][0]] %= 1000000007;
			}
			else if (i+words[j][0] == k) {
				waystoend[words[j][1]-1] += dp[i];
				waystoend[words[j][1]-1] %= 1000000007;
			}
		}
	}
	
	string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	vector <int> appearances(26, 0);
	for (int i = 0; i < m; i ++) {
		char c;
		cin >> c;
		
		appearances[alphabet.find(c)] += 1;
	}
	
	long long ans2=1;
	for (int i = 0; i < 26; i ++) {
		int ans1=0;
		if (appearances[i]) {
			for (int j = 0; j < n; j ++) {
				ans1 += exp(waystoend[j], appearances[i], 1000000007);
				ans1 %= 1000000007;
			}
			ans2 *= ans1;
			ans2 %= 1000000007;		
		}
	}
	
	cout << ans2 << "\n";
	
	return 0;
}

