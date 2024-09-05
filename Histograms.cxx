#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	long long n, x;
	cin >> n >> x;
	
	vector <int> used(0);
	vector <int> usedornot(n-2, 0);
	long long sum = ((n-2)*(n-1))/2;
	
	if (x > sum) {
		cout << "-1\n";
		return 0;
	}
	
	for (int i = 0; i < n-2; i ++) {
		if (sum - (n-2-i) >= x) {
			used.push_back(i+1);
			usedornot[i] = 1;
			sum -= (n-2-i);
		}
	}
	
	cout << n << " ";
	for (int i = 0; i < n-2; i ++) {
		if (usedornot[i] == 0) {
			cout << i+1 << " ";
		}
	}
	
	cout << n-1 << " ";
	sort(used.begin(), used.end());
	reverse(used.begin(), used.end());
	for (int i = 0; i < used.size(); i ++) {
		cout << used[i];
		if (i+1 == used.size()) {
			cout << "\n";
		}
		else {
			cout << " ";
		}
	}
	
	return 0;
}

