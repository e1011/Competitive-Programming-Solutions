#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	freopen("dining.in", "r", stdin);
	freopen("dining.out", "w", stdout);
	
	int n, m, k;
	cin >> n >> m >> k;
	
	vector <vector <int>> graph(n, vector <int> (0));
	vector <vector <int>> costs(n, vector <int> (0));
	vector <int> haybales(n, 0);
	
	for (int i = 0; i < m; i ++) {
		int a, b, c;
		cin >> a >> b >> c;
		
		graph[a-1].push_back(b-1);
		graph[b-1].push_back(a-1);
		costs[a-1].push_back(c);
		costs[b-1].push_back(c);
	}
	
	for (int i = 0; i < k; i ++) {
		int a, b;
		cin >> a >> b;
		haybales[a-1] = max(haybales[a-1], b);
	}
	
	vector <long long> distancetobarn(n, -1);
	priority_queue <vector <long long>, vector <vector <long long>>, greater<vector <long long>>> pq;
	pq.push({0, n-1});
	while (pq.empty() == false) {
		long long dist = pq.top()[0], node = pq.top()[1];
		pq.pop();
		if (distancetobarn[node] == -1) {
			distancetobarn[node] = dist;
			for (int i = 0; i < graph[node].size(); i ++) {
				pq.push({dist+costs[node][i], graph[node][i]});
			}
		}
	}
	
	vector <long long> distancewithhaybales(n, -1000000000000000000);
	for (int i = 0; i < n; i ++) {
		if (haybales[i]) {
			pq.push({distancetobarn[i]-haybales[i], i});
		}
	}
	while (pq.empty() == false) {
		long long dist = pq.top()[0], node = pq.top()[1];
		pq.pop();
		if (distancewithhaybales[node] == -1000000000000000000) {
			distancewithhaybales[node] = dist;
			for (int i = 0; i < graph[node].size(); i ++) {
				pq.push({dist+costs[node][i], graph[node][i]});
			}
		}
	}
	
	for (int i = 0; i < n-1; i ++) {
		cout << (distancetobarn[i] >= distancewithhaybales[i]) << "\n";
	}
	
	
	return 0;
}

