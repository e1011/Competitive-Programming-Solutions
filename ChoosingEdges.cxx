#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	int n, m, k, ans = 1000000;
	cin >> n >> m >> k;
	
	vector <vector <int>> allpairssp(n, vector <int> (n, 10000000));
	vector <vector <int>> edges(n, vector <int> (0));
	vector <vector <int>> newedges(k, vector <int> (3, 0));
	vector <int> spto1(n, 0), sptoN(n, 0), spto12(n, 0), sptoN2(n, 0), colorto1(n, 0), colortoN(n, 0), colorto12(n, 0), colortoN2(n, 0);
	
	for (int i = 0; i < m; i ++) {
		int a, b;
		cin >> a >> b;
		edges[a-1].push_back(b-1);
	}
	for (int i = 0; i < k; i ++) {
		cin >> newedges[i][0] >> newedges[i][1] >> newedges[i][2];
		newedges[i][0] -= 1;
		newedges[i][1] -= 1;
	}
	
	for (int i = 0; i < n; i ++) {
		queue <vector <int>> q;
		q.push({0, i});
		while (q.empty() == false) {
			int dist = q.front()[0], node = q.front()[1];
			q.pop();
			
			if (allpairssp[i][node] == 10000000) {
				allpairssp[i][node] = dist;
				for (int j = 0; j < edges[node].size(); j ++) {
					q.push({dist+1, edges[node][j]});
				}
			}
		}
	}
	
	for (int i = 0; i < n; i ++) {
		spto1[i] = allpairssp[0][i];
		spto12[i] = allpairssp[0][i];
		sptoN[i] = allpairssp[i][n-1];
		sptoN2[i] = allpairssp[i][n-1];
	}
	
	for (int i = 0; i < k; i ++) {
		if (spto1[newedges[i][1]] > allpairssp[0][newedges[i][0]]+1) {
			spto1[newedges[i][1]] = allpairssp[0][newedges[i][0]]+1;
			colorto1[newedges[i][1]] = newedges[i][2];
		}
		if (sptoN[newedges[i][0]] > allpairssp[newedges[i][1]][n-1]+1) {
			sptoN[newedges[i][0]] = allpairssp[newedges[i][1]][n-1]+1;
			colortoN[newedges[i][0]] = newedges[i][2];
		}
	}
	
	for (int i = 0; i < k; i ++) {
		if (newedges[i][2] != colorto1[newedges[i][1]] && spto12[newedges[i][1]] > allpairssp[0][newedges[i][0]]+1) {
			spto12[newedges[i][1]] = allpairssp[0][newedges[i][0]]+1;
			colorto12[newedges[i][1]] = newedges[i][2];
		}
		if (newedges[i][2] != colortoN[newedges[i][0]] && sptoN2[newedges[i][0]] > allpairssp[newedges[i][1]][n-1]+1) {
			sptoN2[newedges[i][0]] = allpairssp[newedges[i][1]][n-1]+1;
			colortoN2[newedges[i][0]] = newedges[i][2];
		}
	}
	
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < n; j ++) {
			if (colorto1[i] == colortoN[j] && colorto1[i] != 0) {
				ans = min(ans, spto1[i]+sptoN2[j]+allpairssp[i][j]);
				ans = min(ans, spto12[i]+sptoN[j]+allpairssp[i][j]);
			}
			else {
				ans = min(ans, spto1[i]+sptoN[j]+allpairssp[i][j]);
			}
		}
	}
	
	if (ans >= 10000000) {
		cout << "-1\n";
	}
	else {
		cout << ans << "\n";
	}
	
	return 0;
}

