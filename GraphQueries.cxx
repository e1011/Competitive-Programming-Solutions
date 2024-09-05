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

int unite(int node1, int node2) {
	int a = get(node1), b = get(node2);
	if (a == b) {
		return 0;
	}
	if (e[a] > e[b]) {
		swap(a, b);
	}
	
	e[b] += e[a];
	e[a] = b;
	return 1;
}

int main() {
	int n, m, q;
	cin >> n >> m >> q;
	
	e = vector <int> (n, -1);
	vector <int> ans(q, 0);
	vector <vector <int>> events(0);
	
	for (int i = 0; i < m; i ++) {
		int a, b, c;
		cin >> a >> b >> c;
		events.push_back({c, 0, a-1, b-1});
	}
	for (int i = 0; i < q; i ++) {
		int a;
		cin >> a;
		events.push_back({a, 1, i});
	}
	
	sort(events.begin(), events.end());
	long long currentanswer = n;
	for (int i = 0; i < events.size(); i ++) {
		if (events[i].size() == 4) {
			int a = -e[get(events[i][2])], b = -e[get(events[i][3])];
			currentanswer += unite(events[i][2], events[i][3])*a*b;
		}
		else {
			ans[events[i][2]] = currentanswer;
		}
	}
	
	for (int i = 0; i < q; i ++) {
		cout << ans[i] << "\n";
	}
	
	return 0;
}

