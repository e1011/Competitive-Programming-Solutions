#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, ammo1=0, ammo2=0, score=0;
	string s;
	cin >> n >> s;
	
	for (int i = 0; i < n; i ++) {
		// reload if they block
		if (s[i] == 'B') {
			ammo1 += 1;
		}
		// block if they fire
		else if (s[i] == 'F' && ammo2 > 0) {
			ammo2 -= 1;
		}
		// reload or fire if they do nothing
		else if (s[i] == 'R' || (s[i] == 'F' && ammo2 == 0)) {
			if (s[i] == 'R') {
				ammo2 += 1;
			}
			if (ammo1 > 0) {
				score += 1;
				ammo1 -= 1;
			}
			else {
				ammo1 += 1;
			}
		}
	}
	
	cout << score << "\n";
	
	return 0;
}

