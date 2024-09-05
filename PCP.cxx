#include <iostream>
#include <vector>

using namespace std;


int main() {
	int n, m;
	cin >> m >> n;
	vector <string> a(n, "");
	vector <string> b(n, "");
	vector <vector <int>> comb(1, vector <int> (0));
	
	for (int i = 0; i < n; i ++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i ++) {
		cin >> b[i];
	}
	
	for (int i = 0; i < m-1; i ++) {
		for (int j = 0; j < comb.size(); j ++) {
			if (comb[j].size() == i) {
				
				for (int k = 0; k < n; k ++) {
					vector <int> k1 = comb[j];
					k1.push_back(k);
					comb.push_back(k1);
				}
			}
		}
	}
	
	bool completed = 0;
	for (int i = 0; i < comb.size(); i ++) {
		string s1="", s2="";
		for (int j = 0; j < comb[i].size(); j ++) {
			s1 += a[comb[i][j]];
			s2 += b[comb[i][j]];
		}
		if (s1 == s2 && i != 0) {
			completed = 1;
			cout << comb[i].size() << "\n";
			for (int j = 0; j < comb[i].size(); j ++) {
				cout << comb[i][j]+1 << "\n";
			}
			break;
		}
	}
	if (completed == 0) {
		cout << "No Solution.\n";
	}
	
	return 0;
}

