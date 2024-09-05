#include <iostream>
#include <vector>

using namespace std;

long long gcd(long long a, long long b) {
	return b == 0 ? a : gcd(b, a % b);
}

long long lcm(long long a, long long b) {
	return (a/gcd(a, b))*b;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, q;
	cin >> n >> q;
	
	vector <long long> lcmarr(n, 1000000001);
	bool reachedlimit = 0;
	for (int i = 0; i < n; i ++) {
		cin >> lcmarr[i];
		if (i != 0 && reachedlimit == 0) {
			lcmarr[i] = lcm(lcmarr[i], lcmarr[i-1]);
		}
		if (lcmarr[i] > 1000000000) {
			reachedlimit = 1;
		}
		if (reachedlimit) {
			lcmarr[i] = 1000000001;
		}
	}
	
	for (int i = 0; i < q; i ++) {
		int t, l=0, r=n-1;
		cin >> t;
		
		while (l < r) {
			int mid = (l+r)/2;
			if (t % lcmarr[mid] == 0) {
				l = mid+1;
			}
			else {
				r = mid;
			}
		}
		
		if (t % lcmarr[l] == 0) {
			cout << "-1\n";
		}
		else {
			cout << l+1 << "\n";
		}
	}
	
	
	return 0;
}
