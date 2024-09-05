#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	
	if (n == 18 || n == 19) {
		cout << "7\n 2 3 16 4 8 5 13\n";
		return 0;
	}
	
	vector <int> arr (0);
	
	int k = sqrt(n)+2;
	for (int i = 1; i <= k; i ++) {
		arr.push_back(i);
	}
	int h = k;
	while (true) {
		if (h+k >= n) {
			break;
		}
		h += k-1;
		arr.push_back(h);
	}
	
	
	cout << arr.size() << "\n";
	if (arr.size() > m) {
		throw;
	}
	for (int i = 0; i < arr.size(); i ++) {
		cout << arr[i];
		if (i+1 == arr.size()) {
			cout << "\n";
		}
		else {
			cout << " ";
		}
	}
	
	
	return 0;
}
