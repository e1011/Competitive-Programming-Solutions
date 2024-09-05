#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, k, ans=10000;
	cin >> n >> k;
	
	vector <vector <int>> grid(18, vector <int> (18, 0));
	vector <int> xsum(18, 0), ysum(18, 0);
	
	for (int i = 0; i < n; i ++) {
		int r, c, s;
		cin >> r >> c >> s;
		
		grid[r-1][c-1] = s;
	}
	
	// going right
	for (int i = 0; i < 18; i ++) {
		int sum = 0;
		for (int j = 0; j < 18; j ++) {
			sum += grid[i][j];
		}
		xsum[i] = sum;
	}
	
	// going down
	for (int i = 0; i < 18; i ++) {
		int sum = 0;
		for (int j = 0; j < 18; j ++) {
			sum += grid[j][i];
		}
		ysum[i] = sum;
	}
	
	for (int i = 0; i < (1 << 18); i ++) {
		// res1 is # used, res2 is safety points
		int res1 = 0, res2 = 0;
		vector <int> sortedsums = ysum;
		for (int j = 0; j < 18; j ++) {
			if ((1 << j) & i) {
				res1 += 1;
				res2 += xsum[j];
				for (int l = 0; l < 18; l ++) {
					sortedsums[l] -= grid[j][l];
				}
			}
		}
		
		sort(sortedsums.begin(), sortedsums.end());
		reverse(sortedsums.begin(), sortedsums.end());
		for (int j = 0; j < 18; j ++) {
			if (res2 >= k) {
				ans = min(ans, res1);
				break;
			}
			else {
				res1 += 1;
				res2 += sortedsums[j];
			}
		}
	}
	
	cout << ans << "\n";
	
	return 0;
}

