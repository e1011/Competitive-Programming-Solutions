#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	long long ans=0;
	int oddcount=0;
	cin >> n;
	
	for (int i = 0; i < n-1; i ++) {
		int a, b, c;
		cin >> a >> b >> c;
		
		if (c % 2 == 0) {
			ans += c;
		}
		else {
			ans += c-1;
			oddcount += 1;
		}
	}
	cout << ans + min(oddcount, 2) << "\n";
	
	return 0;
}

