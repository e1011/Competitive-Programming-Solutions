#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	
	vector <int> a(n, 0), b(n, 0);
	vector <vector <int>> r(0), l(0);
	
	for (int i = 0; i < n; i ++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i ++) {
		cin >> b[i];
	}
	
	
	int pointer = n-1;
	for (int i = n-1; i >= 0; i --) {
		if (b[pointer] == a[i] && i < pointer) {
			r.push_back({i, pointer});
		}
		while (b[pointer] == a[i] && pointer >= 0) {
			if (pointer >= i) {
				a[pointer] = a[i];
			}
			pointer -= 1;
		}
	}
	
	for (int i = 0; i < n; i ++) {
		cout << a[i] << " ";
	}
	cout << "\n";
	pointer = 0;
	for (int i = 0; i < n; i ++) {
		if (b[pointer] == a[i] && i > pointer) {
			l.push_back({pointer, i});
		}
		while (b[pointer] == a[i] && pointer < n) {
			if (pointer <= i) {
				a[pointer] = a[i];
			}
			pointer += 1;
		}
	}
	
	
	for (int i = 0; i < n; i ++) {
		cout << a[i] << " ";
	}
	cout << "\n";
	
	
	bool works = 1;
	for (int i = 0; i < n; i ++) {
		if (a[i] != b[i]) {
			works = 0;
		}
	}
	
	if (works) {
		cout << "YES\n";
		cout << r.size()+l.size() << "\n";
		for (int i = 0; i < r.size(); i ++) {
			cout << "R " << r[i][0] << " " << r[i][1] << "\n";
		}
		for (int i = 0; i < l.size(); i ++) {
			cout << "L " << l[i][0] << " " << l[i][1] << "\n";
		}
	}
	else {
		cout << "NO\n";
	}
	
	return 0;
}

