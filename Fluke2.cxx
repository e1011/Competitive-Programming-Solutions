#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, m, t;
	cin >> n >> m >> t;
	
	for (int i = 0; i < t; i ++) {
		char c;
		int a, b;
		if (m == 2) {
			cout << "2\n";
			cin >> a >> b >> c;
			if (b == 1) {
				while (true) {
					cout << "1 2\n";
					cin >> c;
					if (c == 'W') {
						break;
					}
					else if (c == 'I') {
						throw;
					}
					else if (c == 'L') {
						return 0;
					}
					cin >> a >> b >> c;
					if (c == 'W') {
						break;
					}
					else if (c == 'I') {
						throw;
					}
					else if (c == 'L') {
						return 0;
					}
				}
			}
			else {
				while (true) {
					cout << "1 1\n";
					cin >> c;
					if (c == 'W') {
						break;
					}
					else if (c == 'I') {
						throw;
					}
					else if (c == 'L') {
						return 0;
					}
					cin >> a >> b >> c;
					if (c == 'W') {
						break;
					}
					else if (c == 'I') {
						throw;
					}
					else if (c == 'L') {
						return 0;
					}
				}
			}
		}
		else {
			cout << "1\n";
			vector <int> k(n+1, 0);
			for (int j = 1; j < m; j ++) {
				if (k[j]) {
					cout << "1 " << j+1 << "\n";
				}
				else {
					cout << "1 " << j << "\n";
				}
				cin >> c;
				if (c == 'W') {
					break;
				}
				else if (c == 'I') {
					throw;
				}
				else if (c == 'L') {
					return 0;
				}
				cin >> a >> b >> c;
				k[b] ^= 1;
				if (c == 'W') {
					break;
				}
				else if (c == 'I') {
					throw;
				}
				else if (c == 'L') {
					return 0;
				}
			}
		}
	}
	
	return 0;
}
