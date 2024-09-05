#include <iostream>
#include <random>

using namespace std;

int main(int argc, char **argv) {
	mt19937 mt_rand(atoi(argv[0]));
	
	int n = mt_rand() % 1000000 + 1, ans = 101;
	cout << n << "\n";
	
	for (int i = 0; i < n; i ++) {
		int x = mt_rand() % 100 + 1;
		cout << x;
		ans = min(x, ans);
		
		if (i == n-1) {
			cout << "\n";
		}
		else {
			cout << " ";
		}
	}
	
	cerr << ans << "\n";
	
	return 0;
}

