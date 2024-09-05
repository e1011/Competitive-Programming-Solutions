#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t;
	cin >> t;
	string vika = "vika";
	
	for (int _ = 0; _ < t; _ ++) {
		int n, m;
		cin >> n >> m;
		vector <string> carpet(n, "");
		
		for (int i = 0; i < n; i ++) {
			cin >> carpet[i];
		}
		
		int counter = 0;
		for (int i = 0; i < m; i ++) {
			for (int j = 0; j < n; j ++) {
				if (carpet[j][i] == vika[counter]) {
					counter += 1;
					break;
				}
			}
			if (counter > 3) {
				cout << "yes\n";
				break;
			}
		}
		if (counter < 4) {
			cout << "no\n";
		}
	}
	
	return 0;
}

