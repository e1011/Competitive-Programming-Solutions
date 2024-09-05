#include <iostream>
#include <vector>

using namespace std;

int main() {
	string s, alphabet1 = "abcfghjknopqstuvwxyz", alphabet2 = "mildrebs", alphabet = "mildrebs";
	cin >> s;
	
	int type = 8;
	for (int i = 0; i < s.size(); i ++) {
		if (alphabet2.find(s[i]) == s.npos) {
			type = 20;
			alphabet = "abcfghjknopqstuvwxyz";
			break;
		}
	}
	
	vector <vector <int>> before(type, vector <int> (type, 0));
	char c = s[0];
	for (int i = 1; i < s.size(); i ++) {
		before[alphabet.find(s[i])][alphabet.find(s[i-1])] += 1;
	}
	
	vector <int> dp((1 << type), 1000000000);
	
	dp[0] = 0;
	for (int i = 0; i < (1 << type); i ++) {
		for (int j = 0; j < type; j ++) {
			if ((i & (1 << j)) == 0) {
				int sum = 0;
				sum += (c == alphabet[j]);
				for (int k = 0; k < type; k ++) {
					if ((i & (1 << k)) == 0) {
						sum += before[j][k];
					}
				}
				dp[(i | (1 << j))] = min(dp[(i | (1 << j))], dp[i] + sum);
			}
		}
	}
	
	
	cout << dp[(1 << type)-1] << "\n";
	
	
	return 0;
}

