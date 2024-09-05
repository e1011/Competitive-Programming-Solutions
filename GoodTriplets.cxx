#include <iostream>
#include <vector>

using namespace std;

int main() {
	long long n, c;
	cin >> n >> c;
	
	vector <long long> prefixsum(2*c, 0);
	vector <long long> circle(c, 0);
	for (int i = 0; i < n; i ++) {
		long long x;
		cin >> x;
		circle[x] += 1;
		prefixsum[x] += 1;
		prefixsum[x+c] += 1;
	}
	for (int i = 1; i < 2*c; i ++) {
		prefixsum[i] += prefixsum[i-1];
	}
	
	long long ans = (n*(n-1)*(n-2))/6;
	for (int i = 0; i < c; i ++) {
		for (int j = 1; j <= circle[i%c]; j ++) {
			//cout << i << ", " << j << ", " << ((j+prefixsum[i+c/2]-prefixsum[i]-1)*(j+prefixsum[i+c/2]-prefixsum[i]-2))/2 << "\n";
			ans -= ((j+prefixsum[i+c/2]-prefixsum[i]-1)*(j+prefixsum[i+c/2]-prefixsum[i]-2))/2;
		}
	}
	
	cout << ans << "\n";
	
	return 0;
}

