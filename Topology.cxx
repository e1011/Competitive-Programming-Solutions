#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	
	if (n == 1) {
		cout << "1\n";
		return 0;
	}
	
	vector <int> up(n+1, 0), down(n+1, 0), ans(n, 1), bases(n, 0);
	for (int i = 0; i < m; i ++) {
		int a, b, c;
		cin >> a >> b >> c;
		
		if (a == 1) {
			up[b] += 1;
			up[c] -= 1;
		}
		else {
			down[b-1] += 1;
			down[c-1] -= 1;
		}
	}
	
	// compress all queries
	for (int i = 1; i < n; i ++) {
		up[i] += up[i-1];
		down[i] += down[i-1];
		
		if (up[i] && down[i-1]) {
			cout << "-1\n";
			return 0;
		}
	}
	
	// find max length sequence
	int maxlen=0, counter=0;
	for (int i = 0; i < n; i ++) {
		if (up[i]) {
			counter += 1;
		}
		else {
			counter = 0;
		}
		maxlen = max(maxlen, counter);
	}
	counter = 0;
	for (int i = 0; i < n; i ++) {
		if (down[i]) {
			counter += 1;
		}
		else {
			counter = 0;
		}
		maxlen = max(maxlen, counter);
	}
	
	// find all bases
	if (maxlen != 0) {
		counter = 0;
		for (int i = n-1; i > 0; i --) {
			if (up[i]) {
				counter += 1;
			}
			else {
				counter = 0;
			}
			if (counter == maxlen) {
				bases[i-1] += 1;
			}
		}
		counter = 0;
		for (int i = 0; i < n-1; i ++) {
			if (down[i]) {
				counter += 1;
			}
			else {
				counter = 0;
			}
			if (counter == maxlen) {
				bases[i+1] += 1;
			}
		}
	}
	
	// fill in 1s and 2s based on bases
	for (int i = 0; i < n-1; i ++) {
		if (bases[i] && bases[i+1]) {
			ans[i] = 2;
		}
	}
	for (int i = 0; i < n-1; i ++) {
		if (bases[i+1] && ans[i+1] != 2) {
			ans[i] = 2;
		}
	}
	for (int i = 0; i < n; i ++) {
		if ((i == n-1 || ans[i+1] == 1) && (i == 0 || ans[i-1] == 1) && !bases[i]) {
			ans[i] = 2;
		}
	}

	
	// extend bases
	for (int i = 1; i < n; i ++) {
		if (up[i]) {
			ans[i] = max(ans[i-1]+1, ans[i]);
		}
	}
	for (int i = n-2; i >= 0; i --) {
		if (down[i]) {
			ans[i] = max(ans[i], ans[i+1]+1);
		}
	}
	
	// fix edge cases
	for (int i = 1; i < n; i ++) {
		if (ans[i] == ans[i-1]) {
			ans[i] = ans[i-1]+1;
		}
	}
	
	for (int i = 0; i < n; i ++) {
		if (ans[i] >= 3 && ans[i] > maxlen + 1) {
			throw;
		}
		cout << ans[i] << " ";
	}
	cout << "\n";
	
	return 0;
}

