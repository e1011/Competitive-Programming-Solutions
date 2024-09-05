#include <iostream>
#include <vector>

using namespace std;

int main() {
	int a, b, c, d, e, ans=1;
	cin >> a >> b >> c >> d >> e;
	
	if (b+c == d+e) {
		ans = max(ans, 2);
	}
	if (b+d == c+e) {
		ans = max(ans, 2);
	}
	if (b == c && c == d && d == e) {
		ans = 4;
	}
	if (b+c+d == 3*e) {
		ans = max(ans, 2);
	}
	if (e+c+d == 3*b) {
		ans = max(ans, 2);
	}
	if (b+e+d == 3*c) {
		ans = max(ans, 2);
	}
	if (b+c+e == 3*d) {
		ans = max(ans, 2);
	}
	if (b+c == 2*d && 2*d == 2*e) {
		ans = max(ans, 3);
	}
	if (e+d == 2*b && 2*b == 2*c) {
		ans = max(ans, 3);
	}
	if (b+d == 2*e && 2*e == 2*c) {
		ans = max(ans, 3);
	}
	if (e+c == 2*b && 2*b == 2*d) {
		ans = max(ans, 3);
	}
	
	cout << ans << "\n";
	
	return 0;
}

