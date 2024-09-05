#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	
	string s;
	cin >> s;
	
	int index=0, maxval=0;
	vector <int> arr(m, 0);
	for (int i = 0; i < m; i ++) {
		cin >> arr[i];
		if (arr[i] >= maxval) {
			maxval = arr[i];
			index = i+1;
		}
	}
	
	int zerocounter=0;
	for (int i = 0; i < n; i ++) {
		if (s[i] == '0') {
			zerocounter += 1;
		}
		if (zerocounter == index) {
			for (int j = i; j < n; j ++) {
				if (s[j] != '0') {
					cout << s[j];
				}
			}
			for (int j = 0; j < i; j ++) {
				if (s[j] != '0') {
					cout << s[j];
				}
			}
			cout << "\n";
			break;
		}
	}
	
	
	return 0;
}

