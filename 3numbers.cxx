#include <iostream>

using namespace std;

int main() {
	int a, b, c, ans;
	cin >> a >> b >> c;
	
	ans = max(a+b+c, a*b*c);
	ans = max(ans, (a+b)*c);
	ans = max(ans, (a+c)*b);
	ans = max(ans, (b+c)*a);
	ans = max(ans, (a*b)+c);
	ans = max(ans, (a*c)+b);
	ans = max(ans, (b*c)+a);
	
	cout << ans << "\n";
	
	return 0;
}

