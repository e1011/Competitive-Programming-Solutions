#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, found=0;
	string s, alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	cin >> s >> n;

	vector <string> arr(n, "");
	vector <int> arr1(0);
	for (int i = 0; i < n; i ++) {
		cin >> arr[i];
	}
	for (int i = 0; i < (int)s.size()-8; i ++) {
		set <char> unique;
		for (int j = 0; j < 8; j ++) {
			unique.insert(s[i+j]);
		}
		if (s[i] == s[i+4] && s[i+1] == s[i+8] && unique.size() == 7) {
			arr1.push_back(i);
		}
	}
	
	for (int j = 0; j < arr1.size(); j ++) {
		for (int i = 0; i < n; i ++) {
			string s1 = "";
			if (alphabet[arr[i].find(s[arr1[j]])] == 'H') {
				if (alphabet[arr[i].find(s[arr1[j]+1])] == 'A') {
					if (alphabet[arr[i].find(s[arr1[j]+2])] == 'I') {
						if (alphabet[arr[i].find(s[arr1[j]+3])] == 'L') {
							if (alphabet[arr[i].find(s[arr1[j]+4])] == 'H') {
								if (alphabet[arr[i].find(s[arr1[j]+5])] == 'Y') {
									if (alphabet[arr[i].find(s[arr1[j]+6])] == 'D') {
										if (alphabet[arr[i].find(s[arr1[j]+7])] == 'R') {
											if (alphabet[arr[i].find(s[arr1[j]+8])] == 'A') {
												for (int k = 0; k < s.size(); k ++) {
													cout << alphabet[arr[i].find(s[k])];
												}
												cout << "\n";
												found = 1;
												break;
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	
	if (found == 0) {
		cout << "KeyNotFoundError\n";
	}
	
	
	return 0;
}
