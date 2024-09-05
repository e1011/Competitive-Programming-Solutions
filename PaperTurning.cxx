#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	
	vector <vector <int>> odd(0), even(0);
	for (int i = 0; i < n; i ++) {
		int x;
		cin >> x;
		if (x % 2 == 0) {
			even.push_back({x, i});
		}
		else {
			odd.push_back({x, i});
		}
	}
	
	if (odd.size() == 0) {
		long long sum = 0;
		for (int i = 0; i < n; i ++) {
			sum += even[i][0]/2;
		}
		
		cout << sum << "\n";
		for (int i = 0; i < n; i ++) {
			cout << i+1 << " ";
		}
		cout << "\n";
	}
	else {
		long long sum = 0;
		for (int i = 0; i < odd.size(); i ++) {
			sum += odd[i][0]/2;
		}
		for (int i = 0; i < even.size(); i ++) {
			sum += even[i][0]/2 - 1;
		}
		
		cout << sum << "\n";
		cout << odd[0][1]+1 << " ";
		for (int i = 0; i < even.size(); i ++) {
			cout << even[i][1] + 1 << " ";
		}
		for (int i = 1; i < odd.size(); i ++) {
			cout << odd[i][1]+1 << " ";
		}
		cout << "\n";
	}
	
	return 0;
}

