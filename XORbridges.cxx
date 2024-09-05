#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, q, bit;

vector <pair <int, int>> arr2(0);

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

void unite(int node1, int node2) {
	int a = get(node1), b = get(node2);
	if (a == b) {
		return;
	}
	if (e[a] > e[b]) {
		swap(a, b);
	}
	
	e[b] += e[a];
	e[a] = b;
}


bool comp(pair <int, int> a, pair <int, int> b) {
	return (a.first & (1 << bit)) < (b.first & (1 << bit));
}

void solve(vector <pair <int, int>> arr, int k) {
	if (k < 0 || arr.size() == 0) {
		return;
	}
	else if (k == 0) {
		bit = k;
		sort(arr.begin(), arr.end(), comp);
		for (int i = 1; i < arr.size(); i ++) {
			if ((arr[i-1].first & (1 << k)) == (arr[i].first & (1 << k)) || (m & (1 << k)) == 1) {
				unite(arr[i-1].second, arr[i].second);
			}
		}
	}
	else if (m & (1 << k)) {
		// unite the ones with same bit
		bit = k;
		sort(arr.begin(), arr.end(), comp);
		for (int i = 1; i < arr.size(); i ++) {
			if ((arr[i-1].first & (1 << k)) == (arr[i].first & (1 << k))) {
				unite(arr[i-1].second, arr[i].second);
			}
		}
		solve(arr, k-1);
	}
	else {
		arr2 = vector <pair <int, int>>(0);
		// disconnect ones with different bits
		for (int i = 0; i < arr.size(); i ++) {
			if (arr[i].first & (1 << k)) {
				arr2.push_back(arr[i]);
			}
		}
		solve(arr2, k-1);
		
		arr2 = vector <pair <int, int>>(0);
		for (int i = 0; i < arr.size(); i ++) {
			if (!(arr[i].first & (1 << k))) {
				arr2.push_back(arr[i]);
			}
		}
		solve(arr2, k-1);
	}
	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m >> q;
	
	vector <pair <int, int>> arr(n, pair <int, int> {2, 0});
	e = vector <int> (n, -1);
	for (int i = 0; i < n; i ++) {
		cin >> arr[i].first;
		arr[i].second = i;
	}
	solve(arr, 30);
	for (int i = 0; i < q; i ++) {
		int a, b;
		cin >> a >> b;
		
		if (get(a-1) == get(b-1)) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}

	return 0;
}
