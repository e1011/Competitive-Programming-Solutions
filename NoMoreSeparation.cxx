#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	
	m -= n-1;
	vector <vector <int>> connections(n, vector <int> (n, 0));
	for (int i = 1; i < n; i ++) {
		cout << "1 " << i+1 << "\n";
	}
	
	for (int i = 2; i < n; i ++) {
		for (int j = i+1; j <= n; j ++) {
			if (m > 0) {
				cout << i << " " << j << "\n";
				m -= 1;
			}
		}
	}
	
	return 0;
}

