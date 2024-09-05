#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, count=0;
	cin >> n;
	
	// i -> j in all vectors
	vector <vector <int>> ans(n, vector <int> (n, 0)), ideal(n, vector <int> (n, 0)), current(n, vector <int> (n, 0));
	for (int i = 0; i < n-1; i ++) {
		string s;
		cin >> s;
		for (int j = 0; j < n-i-1; j ++) {
			ideal[i][i+j+1] = s[j]-48;
		}
	}
	
	for (int i = 0; i < n; i ++) {
		for (int j = i-1; j >= 0; j --) {
			if (ideal[j][i] != current[j][i]) {
				ans[j][i] = 1;
				current[j][i] = ideal[j][i];
				for (int k = 0; k < j; k ++) {
					current[k][i] += current[k][j];
					current[k][i] %= 2;
				}
			}
			/*
			cout << i << ", " << j << "\n";
			for (int i = 0; i < n; i ++) {
				for (int j = 0; j < n; j ++) {
					cout << current[i][j];
				}
				cout << "\n";
			}
			*/
			
		}
	}
	
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < n; j ++) {
			count += ans[i][j];
		}
	}
	
	
	cout << count << "\n";
	
	return 0;
}

