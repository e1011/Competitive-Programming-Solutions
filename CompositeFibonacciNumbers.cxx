#include <iostream>
#include <vector>

using namespace std;

bool checkifprime(int n) {
	for (int i = 2; i*i <= n; i ++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

int main() {
	int t;
	cin >> t;
	
	vector <int> prime(100001, 0);
	vector <int> fibonacci(100001, 0);
	
	int sum1=1, sum2=2, sum3;
	while (sum1 < 100001) {
		fibonacci[sum1] = 1;
		sum3 = sum1;
		sum1 = sum2;
		sum2 += sum3;
	}
	
	for (int i = 0; i < 100001; i ++) {
		if (checkifprime(i) == 1) {
			prime[i] = 1;
		}
	}
	
	for (int i = 0; i < t; i ++) {
		int n;
		cin >> n;
		if (prime[n] == 0 && fibonacci[n] == 1) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}
	
	
	return 0;
}

