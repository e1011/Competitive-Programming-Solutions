#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(vector <int> a, vector <int> b) {
	return a[2] < b[2];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	
	vector <vector <vector <int>>> arr(256, vector <vector <int>> (256, vector <int> (256, 0)));
	vector <vector <vector <int>>> arr2(256, vector <vector <int>> (256, vector <int> (256, 0)));
	for (int i = 0; i < n; i ++) {
		int a, b, c;
		cin >> a >> b >> c;
		
		arr[a][b][c] = 1;
		arr2[a][b][c] = 1;
	}
	
	for (int i = 0; i < 256; i ++) {
		for (int j = 0; j < 256; j ++) {
			for (int k = 0; k < 256; k ++) {
				if (i > 0) {
					arr[i][j][k] += arr[i-1][j][k];
				}
				if (j > 0) {
					arr[i][j][k] += arr[i][j-1][k];
				}
				if (k > 0) {
					arr[i][j][k] += arr[i][j][k-1];
				}
				if (i > 0 && j > 0) {
					arr[i][j][k] -= arr[i-1][j-1][k];
				}
				if (i > 0 && k > 0) {
					arr[i][j][k] -= arr[i-1][j][k-1];
				}
				if (j > 0 && k > 0) {
					arr[i][j][k] -= arr[i][j-1][k-1];
				}
				if (i > 0 && j > 0 && k > 0) {
					arr[i][j][k] += arr[i-1][j-1][k-1];
				}
			}
		}
	}
	
	int l=1, r=256, indexi, indexj, indexk;
	while (l < r) {
		int mid = (l+r)/2, works=0;
		
		for (int i = mid; i < 256; i ++) {
			for (int j = mid; j < 256; j ++) {
				for (int k = mid; k < 256; k ++) {
					int sum = arr[i][j][k];
					if (i-mid > 0) {
						sum -= arr[i-mid-1][j][k];
					}
					if (j-mid > 0) {
						sum -= arr[i][j-mid-1][k];
					}
					if (k-mid > 0) {
						sum -= arr[i][j][k-mid-1];
					}
					if (i-mid > 0 && j-mid > 0) {
						sum += arr[i-mid-1][j-mid-1][k];
					}
					if (i-mid > 0 && k-mid > 0) {
						sum += arr[i-mid-1][j][k-mid-1];
					}
					if (j-mid > 0 && k-mid > 0) {
						sum += arr[i][j-mid-1][k-mid-1];
					}
					if (i-mid > 0 && j-mid > 0 && k-mid > 0) {
						sum -= arr[i-mid-1][j-mid-1][k-mid-1];
					}
					if (sum >= m) {
						works = 1;
						indexi = i;
						indexj = j;
						indexk = k;
						break;
					}
				}
			}
		}
		
		if (works) {
			r = mid;
		}
		else {
			l = mid+1;
		}
	}
	
	cout << l << "\n";
	for (int i = indexi-l; i <= indexi; i ++) {
		for (int j = indexj-l; j <= indexj; j ++) {
			for (int k = indexk-l; k <= indexk; k ++) {
				if (arr2[i][j][k] && m > 0) {
					cout << i << " " << j << " " << k << "\n";
					m -= 1;
				}
			}
		}
	}
	
	return 0;
}

// convert to array of size 255, find longest consecutive sequence of 1s
// for 2d, use 2d psa to find squares that work
// let arr[i][j] be whether there exists a crayon with r=i, g=j. 1 if true, 0 if not
// o(n^2) loop through all indices, check if sum of size k works
// for 3d, use 3d psa
// arr[i][j][k] is whether a crayon exists
// arr[i][j][k] += arr[i][j][k-1]+arr[i][j-1][k]+arr[i-1][j][k]
// psum at (i, j, k), (i2, j2, k2) is: 
// arr[i][j][k] - arr[i][j][k1] - arr[i][j1][k] - arr[i1][j][k] +
// arr[i][j1][k1] + arr[i1][j][k1] + arr[i][j1][k1] - arr[i1][j1][k1]
// o(n^3) loop through all indices to check if sum of size k works
// binary search largest size of cube
