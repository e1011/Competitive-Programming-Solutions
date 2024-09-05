#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	
	vector <int> arr1(n, 0);
	vector <int> arr2(n, 0);
	
	for (int i = 0; i < n; i ++) {
		cin >> arr1[i];
	}
	for (int i = 0; i < n; i ++) {
		cin >> arr2[i];
	}
	
	int s1 = 0, s2 = 0, ans=0;
	for (int i = 0; i < n; i ++) {
		if (s1 == s2) {
			ans = i;
		}
		s1 += arr1[i];
		s2 += arr2[i];
	}
	if (s1 == s2) {
		ans = n;
	}
	cout << ans << "\n";
	
	
	return 0;
}

