#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t;
	cin >> t;
	
	for (int _ = 0; _ < t; _ ++) {
		int n, works = 1;
		cin >> n;
		
		vector <int> a(n, 0);
		for (int i = 0; i < n; i ++) {
			cin >> a[i];
		}
		
		for (int i = 0; i < n; i ++) {
			if (a[i] > n) {
				works = 0;
			}
			else if (a[a[i]-1] < i+1) {
				works = 0;
			}
			else if (a[i] != n && a[a[i]] == a[a[i]-1]) {
				works = 0;
			}
		}
		
		if (works) {
			cout << "yes\n";
		}
		else {
			cout << "no\n";
		}
	}
	
	return 0;
}

