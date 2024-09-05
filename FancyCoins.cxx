#include <iostream>

using namespace std;

int main() {
	int t;
	cin >> t;
	
	for (int _ = 0; _ < t; _ ++) {
		long long m, k, a1, ak, x;
		cin >> m >> k >> a1 >> ak;
		
		m -= k*min(m/k, ak);
		
		x = m/k;
		m -= x*k;
		
		if (a1 > m) {
			a1 -= m;
			x -= a1/k;
		}
		else {
			x += (m-a1);
		}
		
		cout << max((long long)0, x) << "\n";
	}
	
	return 0;
}

