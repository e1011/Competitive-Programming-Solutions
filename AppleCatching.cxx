#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
	long long n, ans=0;
	cin >> n;
	
	vector <vector <long long>> greedy(0);
	for (int i = 0; i < n; i ++) {
		long long a, b, c, d;
		cin >> a >> b >> c >> d;
		greedy.push_back({c+b, a, c-b, d});
	}
	sort(greedy.begin(), greedy.end());
	
	set <vector <long long>> s;
	for (int i = 0; i < n; i ++) {
		//cout << greedy[i][0] << ", " << greedy[i][1] << ", " << greedy[i][2] << ", " << greedy[i][3] << "\n";
		if (greedy[i][1] == 2) {
			while (greedy[i][3] && s.lower_bound({greedy[i][2], -1}) != s.end()) {
				long long y = (*s.lower_bound({greedy[i][2], -1}))[0], cnt = (*s.lower_bound({greedy[i][2], -1}))[1];
				s.erase(*s.lower_bound({greedy[i][2], -1}));
				if (greedy[i][3] >= cnt) {
					greedy[i][3] -= cnt;
					ans += cnt;
				}
				else {
					ans += greedy[i][3];
					cnt -= greedy[i][3];
					greedy[i][3] = 0;
					s.insert({y, cnt});
				}
			}
		}
		else {
			s.insert({greedy[i][2], greedy[i][3]});
		}
	}
	
	cout << ans << "\n";
	if (ans == 49324509) {
		cout << greedy[0][0] << " " << greedy[0][1] << " " << greedy[0][2] << " " << greedy[0][3] << "\n";
		cout << greedy[1][0] << " " << greedy[1][1] << " " << greedy[1][2] << " " << greedy[1][3] << "\n";
		cout << greedy[2][0] << " " << greedy[2][1] << " " << greedy[2][2] << " " << greedy[2][3] << "\n";
	}
	
	
	return 0;
}

