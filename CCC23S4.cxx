#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> e(0);

int get(int node) {
	if (e[node] < 0) {
		return node;
	}
	else {
		e[node] = get(e[node]);
		return e[node];
	}
}

bool unite(int node1, int node2) {
	int a = get(node1), b = get(node2);
	if (a == b) {
		return false;
	}
	if (e[a] > e[b]) {
		swap(a, b);
	}
	
	e[b] += e[a];
	e[a] = b;
	return true;
}

int main() {
	int n, m;
	long long ans = 0;
	cin >> n >> m;
	
	e = vector <int> (n+1, -1);
	vector <vector <int>> arr(m, vector <int> (4, 0));
	for (int i = 0; i < m; i ++) {
		cin >> arr[i][2] >> arr[i][3] >> arr[i][0];
	}
	
	sort(arr.begin(), arr.end());
	
	for (int i = 0; i < m; i ++) {
		if (unite(arr[i][2], arr[i][3])) {
			ans += arr[i][0];
		}
	}
	
	cout << ans << "\n";
	
	return 0;
}

