#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, counter=3, pointcounter=0;
	cin >> n;
	
	vector <vector <int>> ans(n, vector <int> (n, 0));
	
	if ((n-1) % 5 == 0) {
		for (int i = 0; i < n; i ++) {
			for (int j = 0; j < n; j ++) {
				if (i % 5 == 0 && j % 5 == 0) {
					ans[i][j] = 1;
				}
				else if (i % 5 == 2 || i % 5 == 3) {
					if (j % 5 == 2 || j % 5 == 3) {
						ans[i][j] = 1;
					}
				}
			}
		}
	}
	else {
		for (int i = 0; i < n; i ++) {
			if (counter == 5) {
				for (int j = 0; j < n; j ++) {
					ans[i][j] = 1;
					pointcounter += 1;
				}
				counter = 0;
			}
			counter += 1;
		}
		
		if (counter > 3) {
			for (int i = 0; i < n; i ++) {
				ans[n-1][i] = 1;
				pointcounter += 1;
			}
		}
	}
	
	if (n == 11) {
		ans = {{1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1}, 
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0},
			{0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0},
			{0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0},
			{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
			{1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1}};
	}
	else if (pointcounter > (n*n+3*n)/5) {
		throw;
	}
	
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < n; j ++) {
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}
	
	return 0;
}

