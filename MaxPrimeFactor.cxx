#include <iostream>
#include <vector>

using namespace std;

bool isprime(int n) {
	for (int i = 2; i*i <= n; i ++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

int composite(int n) {
	int ret = 0;
	for (int i = 1; i*i <= n; i ++) {
		if (n % i == 0) {
			ret = max(ret, max(isprime(i)*i, isprime(n/i)*(n/i)));
		}
	}
	
	return ret;
} 

int main() {
	int n, ans=0, index;
	cin >> n;
	vector <int> arr(n, 0);
	
	for (int i = 0; i < n; i ++) {
		cin >> arr[i];
	}

	for (int i = 0; i < arr.size(); i ++) {
		int comp = composite(arr[i]);
		if (comp > ans) {
			ans = comp;
			index = i;
		}
	}
	
	cout << arr[index] << "\n";
	
	return 0;
}


