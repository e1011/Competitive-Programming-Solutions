#include <iostream>
#include <random>

using namespace std;

int main(int argc, char **argv) {
	mt19937 mt_rand(atoi(argv[1]));
	
	int a = mt_rand() % 201 - 100, b = mt_rand() % 201 - 100, c = mt_rand() % 201 - 100, ans;
	if (atoi(argv[1]) == 26) {
		a = 1;
		b = 1;
		c = 1;
	}
	cout << a << " " << b << " " << c << "\n";
	
	ans = max(a+b+c, a*b*c);
	ans = max(ans, (a+b)*c);
	ans = max(ans, (a+c)*b);
	ans = max(ans, (b+c)*a);
	ans = max(ans, (a*b)+c);
	ans = max(ans, (a*c)+b);
	ans = max(ans, (b*c)+a);
	
	cerr << ans << "\n";
	
	return 0;
}

