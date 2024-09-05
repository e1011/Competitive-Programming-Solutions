#include <iostream>
#include <vector>

using namespace std;

vector <long long> memo(10000000);

long long balancedtrees(long long n) {
	if (n == 1) {
		return 1;
	}
	else {
		long long sum = 0, divisor=2;
		while (divisor <= n) {
			if (n/divisor >= 10000000 || memo[n/divisor] == 0) {
				sum += (n/(n/divisor)-divisor+1)*balancedtrees(n/divisor);
			}
			else {
				sum += (n/(n/divisor)-divisor+1)*memo[n/divisor];
			}
			divisor = n/(n/divisor)+1;
		}
		if (n < 10000000) {
			memo[n] = sum;
		}
		return sum;
	}
}

int main() {
	long long n;
	cin >> n;
	
	cout << balancedtrees(n) << "\n";
	
	return 0;
}

// let f(n) denote number of pts of weight n
// f(n) = sum(k=2 -> n, f(floor(n/k)))
// f(1) = 1
