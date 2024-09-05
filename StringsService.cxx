#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t;
	cin >> t;
	
	for (int i = 0; i < t; i ++) {
		vector <int> ans(0);
		int k;
		cin >> k;
		
		for (int j = 500; j >= 1; j --) {
			while (j*(j+1)/2 <= k) {
				k -= j*(j+1)/2;
				ans.push_back(j);
			}
		}
		
		cout << "Case #" << i+1 << ": ";
		for (int j = 0; j < ans.size(); j ++) {
			for (int k = 0; k < ans[j]; k ++) {
				if (j % 3 == 0) {
					cout << "A";
				}
				else if (j % 3 == 1) {
					cout << "B";
				}
				else {
					cout << "C";
				}
			}
		}
		cout << "\n";
	}
	
	return 0;
}

