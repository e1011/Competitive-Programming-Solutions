#include <iostream>
#include <vector>

using namespace std;


long long f(long long n) {
	long long ret = 0;
	for (int i = 1; i*i <= n; i ++) {
		if (n % i == 0) {
			ret += i*i;
			if (i*i != n) {
				ret += (n/i)*(n/i);
			}
		}
	}
	
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	
	vector <long long> storage(100001, -1);
	
	for (int i = 0; i < n; i ++) {
		long long x;
		cin >> x;
		if (storage[x] == -1) {
			storage[x] = f(x);
		}
		cout << storage[x] << "\n";
	}
	
	return 0;
}

