#include <iostream>
#include <set>

using namespace std;

int main() {
	int g, p, ans=0;
	cin >> g >> p;
	
	set <int> s;
	for (int i = 0; i <= g; i ++) {
		s.insert(i);
	}
	
	for (int i = 0; i < p; i ++) {
		int x;
		cin >> x;
		if (*(--s.upper_bound(x)) == 0) {
			break;
		}
		else {
			s.erase(*(--s.upper_bound(x)));
			ans += 1;
		}
	}
	
	cout << ans << "\n";
	
	return 0;
}

