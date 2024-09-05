#include <iostream>
#include <vector>

using namespace std;

int main() {
	long long n, ans=0;
	cin >> n;
	
	vector <vector <int>> bits(30, vector <int> (n, 0));
	for (int i = 0; i < n; i ++) {
		int x;
		cin >> x;
		for (int j = 0; j < 30; j ++) {
			bits[j][i] = (1 & (x >> j));
		}
	}
	

	for (int i = 0; i < 30; i ++) {
		long long s0=0, s1=0;
		for (int j = 0; j < n; j ++) {
			s0 += (long long)(j+1)*(n-j)*(1 & (bits[i][j]));
			s1 += (long long)(j+1)*(n-j)*(1 ^ (bits[i][j]));
		}
		if (s1 < s0) {
			ans += (1 << i);
		}
	}
	
	cout << ans << "\n";
	
	
	return 0;
}

