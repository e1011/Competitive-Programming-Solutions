#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	
	for (int _ = 0; _ < t; _ ++) {
		long long n, m, player=0;
		cin >> n >> m;
		while (true) {
			if (n < m) {
				swap(n, m);
			}
			if (n >= m*2 || n-m == 0) {
				break;
			}
			n %= m;
			player = !player;
		}
		if (player) {
			cout << "Bob Win\n";
		}
		else {
			cout << "Alice Win\n";
		}
	}
	
	return 0;
}

// if n % m = 0, can take all of n and they win
// want to find a situation where n is divisible by m
// its always optimal to take either all possible, or all thats possible -1
	// this is because if you dont do it e.g take all -2, other person can choose optimal
	// if optimal for them, can take 1 and same situation
	// or can take all of it if that is optimal
// therefore, first able to make choice is able to win


