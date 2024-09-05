#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	long long n, m, ans=0;
	cin >> n >> m;
	
	vector <long long> a(n, 0), b(n, 0);
	for (int i =0 ; i < n; i ++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i ++) {
		cin >> b[i];
	}
	
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	for (int i = n-1; i >= 0; i --) {
		if (i == n-1) {
			if (a[i] > b[i]) {
				long long dif = a[i]-b[i];
				b[i] += min(m, dif);
				m -= min(m, dif);
			}
			else {
				long long dif = b[i]-a[i];
				a[i] += min(m, dif);
				m -= min(m, dif);
			}
			ans += ((a[i]+(m+1)/2) % 1000000007)*((b[i]+m/2)%1000000007);
			ans %= 1000000007;
			
		}
		else {
			ans += (a[i]%1000000007)*(b[i]%1000000007);
			ans %= 1000000007;
		}
	}
	cout << ans << "\n";
	
	return 0;
}

