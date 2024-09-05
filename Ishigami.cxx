#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, k, ans=0;
	cin >> n >> k;
	
	vector <string> students(n, "");
	for (int i = 0; i < n; i ++) {
		cin >> students[i];
	}
	
	for (int i = 0; i < (1 << k); i ++) {
		int ans2 = 1000000000;
		for (int j = 0; j < n; j ++) {
			int ans3 = 0;
			for (int l = 0; l < k; l ++) {
				if (students[j][l] == 'F' && !((1 << l) & i)) {
					ans3 += 1;
				}
				if (students[j][l] == 'T' && ((1 << l) & i)) {
					ans3 += 1;
				}
			}
			ans2 = min(ans2, ans3);
		}
		ans = max(ans, ans2);
	}
	
	cout << ans << "\n";
	
	return 0;
}

