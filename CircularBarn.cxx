#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	//freopen("cbarn.in", "r", stdin);
	//freopen("cbarn.out", "w", stdout);
	
	long long n, ans=0, maximum=0, maxindex=0;
	cin >> n;
	
	vector <int> cows(n, 0);
	for (int i = 0; i < n; i ++) {
		cin >> cows[i];
		if (cows[i] > maximum) {
		
		}
	}
	
	multiset <int> m;
	m.insert(n);
	for (int i = 0; i < n; i ++) {
		int x;
		cin >> x;
		for (int j = 0; j < x; j ++) {
			m.insert(n-i-1);
		}
	}
	
	for (int i = 0; i < n; i ++) {
		if (m.count(i) == 0) {
			if (*m.upper_bound(i) == n) {
				ans += (n-i+*m.upper_bound(-1))*(n-i+*m.upper_bound(-1));
				m.erase(m.upper_bound(-1));
			}
			else {
				ans += (*m.upper_bound(i)-i)*(*m.upper_bound(i)-i);
				m.erase(m.upper_bound(i));
			}
		}
		cout << m.size() << "\n";
	}
	
	cout << ans << "\n";
	
	return 0;
}

