#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, t;
	cin >> n >> t;
	
	for (int i = 0; i < t; i ++) {
		if (n % 2 == 0) {
			cout << "2\n";
		}
		else {
			cout << "1\n";
			cout << (n+1)/2 << " " << (n+1)/2 << "\n";
		}
		while (true) {
			int a, b;
			cin >> a >> b;
			if (a == 0 && b == 0) {
				break;
			}
			else if (a == -1 && b == -1) {
				return 0;
			}
			else {
				cout << (n-a+1) << " " << (n-b+1) << "\n";
			}
		}
	}
	
	
	return 0;
}

