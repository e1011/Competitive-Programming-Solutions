#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

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

int main(int argc, char **argv) {
	mt19937 mt_rand(atoi(argv[1]));
	int n = mt_rand() % 1000000 + 1, m = n-1, q = mt_rand() % 1000000 + 1;
	cout << n << " " << m << " " << q << "\n";
	
	e = vector <int> (n, -1);
	vector <int> ans(q, 0);
	vector <vector <int>> events(0);
	
	for (int i = 1; i < n; i ++) {
		int u_i = mt_rand() % i + 1, v_i = i+1, l_i = mt_rand() % 1000000000 + 1;
		cout << u_i << " " << v_i << " " << l_i << "\n";
		events.push_back({l_i, 0, u_i-1, v_i-1});
	}
	
	/*
	for (int i = 0; i < m-n+1; i ++) {
		int u_i = mt_rand() % n + 1, v_i = mt_rand() % n + 1, l_i = mt_rand() % 1000000000 + 1;
		cout << u_i << " " << v_i << " " << l_i << "\n";
		graph[u_i-1].push_back(v_i-1);
		graph[v_i-1].push_back(u_i-1);
		costs[u_i-1].push_back(l_i);
		costs[v_i-1].push_back(l_i);
	}
	* */
	
	for (int i = 0; i < q; i ++) {
		int q_i = mt_rand() % 1000000000 + 1;
		cout << q_i << "\n";
		events.push_back({q_i, 1, i});
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
		cerr << ans[i] << "\n";
	}
	
	return 0;
}

