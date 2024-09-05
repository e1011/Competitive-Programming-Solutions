#include <iostream>
#include <vector>

using namespace std;

int main() {
	long long n, k, x, sum=0;
	cin >> n >> k >> x;
	
	for (int i = 1; i < n; i ++) {
		cout << k-1 << " ";
		sum += (2*i-1)*(k-1);
		sum %= k;
	}
	
	cout << sum << "\n";
	if (x >= sum) {
		cout << x-sum << "\n";
	}
	else {
		cout << k+x-sum << "\n";
	}
	
	return 0;
}

