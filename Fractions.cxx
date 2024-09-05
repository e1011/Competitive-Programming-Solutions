#include <iostream>

using namespace std;

long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }

int main() {
	int t;
	cin >> t;
	
	for (int _  = 0; _ < t; _ ++) {
		long long a, b;
		cin >> a >> b;
		
		long long c = gcd(a, b);
		a /= c;
		b /= c;
		
		long long count2=0, count5=0;
		while (b % 2 == 0) {
			b /= 2;
			count2 += 1;
		}
		while (b % 5 == 0) {
			b /= 5;
			count5 += 1;
		}
		
		if (b == 1) {
			cout << max(count2, count5) << "\n";
		}
		else {
			cout << "-1\n";
		}
	}
	
	return 0;
}

