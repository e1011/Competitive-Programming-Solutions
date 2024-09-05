#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, d;
	cin >> n >> d;
	
	vector <int> prefixsum(n, 0);
	for (int i = 0; i < n; i ++) {
		cin >> prefixsum[i];
		if (i != 0) {
			prefixsum[i] += prefixsum[i-1];
		}
	}
	
	int l=0, r=n-1;
	for (int i = 0; i < d; i ++) {
		int x;
		cin >> x;
		x += l-1;
		
		int lsum = prefixsum[x], rsum = prefixsum[r]-prefixsum[x];
		if (l != 0) {
			lsum -= prefixsum[l-1];
		}
		if (lsum >= rsum) {
			cout << lsum << "\n";
			l = x+1;
		}
		else {
			cout << rsum << "\n";
			r = x;
		}
	}
	
	
	return 0;
}

