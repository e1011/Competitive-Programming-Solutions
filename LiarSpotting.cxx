#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool possible = 1;

vector <vector <int>> same, dif;
vector <int> color;

bool comp(vector <int> a, vector <int> b) {
	return (a[1] < b[1]);
}

void dfs(int node) {
	for (int i = 0; i < same[node].size(); i ++) {
		if (color[same[node][i]] == -1) {
			color[same[node][i]] = color[node];
			dfs(same[node][i]);
		}
		else if (color[same[node][i]] != color[node]) {
			possible = 0;
		}
	}
	for (int i = 0; i < dif[node].size(); i ++) {
		if (color[dif[node][i]] == -1) {
			color[dif[node][i]] = !color[node];
			dfs(dif[node][i]);
		}
		else if (color[dif[node][i]] == color[node]) {
			possible = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	
	if (m == 0) {
		cout << "0\n";
		return 0;
	}
	
	vector <vector <int>> queries(0), edges(0);
	// take input in the form of connected points
	for (int i = 0; i < m; i ++) {
		int a, b;
		string s;
		cin >> a >> b >> s;
		
		if (s == "even") {
			queries.push_back({a-1, i, 0, 0});
			queries.push_back({b, i, 0, 0});
		}
		else {
			queries.push_back({a-1, i, 1, 0});
			queries.push_back({b, i, 1, 0});
		}
	}
	
	// compress coords
	int counter = 0;
	sort(queries.begin(), queries.end());
	for (int i = 1; i < 2*m; i ++) {
		if (queries[i][0] > queries[i-1][0]) {
			counter += 1;
		}
		queries[i][3] = counter;
	}
	queries[0][3] = 0;
	
	
	// convert to edges
	sort(queries.begin(), queries.end(), comp);
	for (int i = 0; i < m; i ++) {
		edges.push_back({queries[2*i][3], queries[2*i + 1][3], queries[2*i][2]});
	}
	
	
	int l=0, r=m-1;
	while (l < r) {
		int mid = (l+r+1)/2;
		possible = 1;
		color = vector <int> (counter+1, -1);
		same = vector <vector <int>>(counter+1, vector <int> (0));
		dif = vector <vector <int>>(counter+1, vector <int> (0));
		for (int i = 0; i <= mid; i ++) {
			if (edges[i][2] == 0) {
				same[edges[i][0]].push_back(edges[i][1]);
				same[edges[i][1]].push_back(edges[i][0]);
			}
			else {
				dif[edges[i][0]].push_back(edges[i][1]);
				dif[edges[i][1]].push_back(edges[i][0]);
			}
		}
		
		for (int i = 0; i <= counter; i ++) {
			if (color[i] == -1) {
				color[i] = 0;
				dfs(i);
			}
		}
		
		if (possible) {
			l = mid;
		}
		else {
			r = mid-1;
		}
	}
	
	
	cout << l+1 << "\n";
	
	
	return 0;
}

