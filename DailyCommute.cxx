#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, w, d;
	cin >> n >> w >> d;
	
	vector <vector <int>> graph(n, vector <int> (0));
	vector <int> dist(n, -1);
	vector <int> route(n, -1);
	
	for (int i = 0; i < w; i ++) {
		int a, b;
		cin >> a >> b;
		graph[b-1].push_back(a-1);
	}
	
	queue <vector <int>> q;
	q.push({0, n-1});
	while (q.empty() == false) {
		int d = q.front()[0], node = q.front()[1];
		q.pop();
		if (dist[node] == -1) {
			dist[node] = d;
			for (int i = 0; i < graph[node].size(); i ++) {
				q.push({d+1, graph[node][i]});
			}
		}
	}
	
	multiset <int> s;
	for (int i = 0; i < n; i ++) {
		int a;
		cin >> a;
		if (dist[a-1] != -1) {
			s.insert(dist[a-1]+i);
		}
		route[i] = a-1;
	}
	
	for (int i = 0; i < d; i ++) {
		int a, b;
		cin >> a >> b;
		
		if (dist[route[a-1]] != -1) {
			s.erase(s.find(dist[route[a-1]]+a-1));
		}
		if (dist[route[b-1]] != -1) {
			s.erase(s.find(dist[route[b-1]]+b-1));
		}
		
		swap(route[a-1], route[b-1]);
		if (dist[route[a-1]] != -1) {
			s.insert(dist[route[a-1]]+a-1);
		}
		if (dist[route[b-1]] != -1) {
			s.insert(dist[route[b-1]]+b-1);
		}
		
		
		cout << *s.lower_bound(0) << "\n";
	}
	
	return 0;
}

// every path requires starting on the train, then getting off and walking to end
// this is cuz if you get back on the train, could have just stayed on the way in between
// do bfs from end, find distance to every node
// find time it takes for train to reach every station
// use multiset and array. when switching two stations, the times get switched
// remove original times from multiset, add new times
