#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
	int n, x;
	cin >> n >> x;
	
	vector <int> arr(n, 0);
	set <int> s;
	for (int i = 0; i < n; i ++) {
		cin >> arr[i];
	}
	
	for (int i = 0; i < n; i ++) {
		if (s.count(arr[i])) {
			cout << "YES\n";
			return 0;
		}
		s.insert(arr[i]^x);
	}
	
	cout << "NO\n";
	
	return 0;
}

