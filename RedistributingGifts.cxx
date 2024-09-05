#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, q;
	cin >> n;
	
	vector <vector <int>> graph (n, vector <int> (0));
	vector <vector <int>> dp ((1 << n), vector <int> (n, -1));
	for (int i = 0; i < n; i ++) {
		bool finished = 0;
		for (int j = 0; j < n; j ++) {
			int x;
			cin >> x;
			if (finished == 0) {
				graph[i].push_back(x);
			}
			if (x == i) {
				finished = 1;
			}
		}
	}
	
	dp[0][0] = 1;
	for (int i = 0; i < (1 << n); i ++) {
		for (int j = 0; j < n; j ++) {
			if (i & (1 << j) == 1) {
				for (int k = 0; k < n; k ++) {
					if (i & (1 << k) == 0) {
						dp[i | (1 << j)][k] += dp[i][j];
						break;
					}
				}
			}
			// finds the next unvisited node and attempts to start cycle from that node
			
			else {
				for (int k = 0; k < graph[j].size(); k ++) {
				
				}
			}
			
		}
	}
	
	
	return 0;
}

