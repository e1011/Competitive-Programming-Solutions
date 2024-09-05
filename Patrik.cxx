#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	
	long long ans = 0;
	
	stack <vector <int>> s;
	for (int i = 0; i < n; i ++) {
		int x, maximum=0;
		cin >> x;
		
		while (!s.empty() && x > s.top()[0]) {
			if (s.top()[0] >= maximum) {
				ans += s.top()[1];
				maximum = s.top()[0];			
			}
			s.pop();
		}
		if (!s.empty() && s.top()[0] == x) {
			ans += s.top()[1];
			ans += min(1, (int)s.size()-1);
			s.top()[1] += 1;
		}
		else {
			ans += min(1, (int)s.size());
			s.push({x, 1});
		}
	}
	
	cout << ans << "\n";
	
	return 0;
}

