#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, ans=0;
	cin >> n;
	
	for (int i  =1; i <= n; i ++) {
		if (i % 4 == 0) {
			ans += 25;
		}
		else if (i % 3 == 0) {
			ans += 10;
		}
		else if (i % 2 == 0) {
			ans += 5;
		}
		else {
			ans += 1;
		}
	}
	
	cout << ans << "\n";
	
	return 0;
}

