#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t;
	cin >> t;
	
	for (int i = 0; i < t; i ++) {
		long long c, sum=1;
		cin >> c;
		for (int j = 2; j*j <= c; j ++) {
			int k = 1;
			while (c % j == 0) {
				c /= j;
				k += 2;
			}
			sum *= k;
		}
		if (c != 1) {
			sum *= 3;
		}
		
		cout << sum << "\n";
	}
	
	return 0;
}

