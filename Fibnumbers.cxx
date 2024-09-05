#include <iostream>
#include <vector>

using namespace std;

vector <int> fnumbers = {0, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765, 10946, 17711, 28657, 46368, 75025};
vector <int> fnumbers2 = {10, 10, 10, 10, 10, 10, 100, 100, 100, 100, 100, 1000, 1000, 1000, 1000, 1000, 10000, 10000, 10000, 10000, 100000, 100000, 100000, 100000, 100000};
bool works = false;

void dfs(int n, int dist) {
	if (n == 0) {
		if (dist > 1) {
			works = true;
		}
		return;
	}
	else {
		for (int i = 0; i < fnumbers.size(); i ++) {
			if ((n-fnumbers[i]) % fnumbers2[i] == 0) {
				dfs((n-fnumbers[i])/fnumbers2[i], dist+1);
			}
		}
	}
}

int main() {
	int q;
	cin >> q;
	
	for (int i = 0; i < q; i ++) {
		int n;
		cin >> n;
		
		works = false;
		dfs(n, 0);
		if (works) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
}
	
	return 0;
}

