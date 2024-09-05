#include <iostream>
#include <vector>
#include <random>
#include <queue>

using namespace std;

int main(int argc, char **argv) {
	mt19937 mt_rand(atoi(argv[1]));
	int n = 5000, m = 5000, k = 1000000, ans=10000000;
	if (atoi(argv[1]) % 2 == 0) {
		k = 10000;
	}
	cout << n << " " << m << " " << k << "\n";
	
	vector <vector <int>> allpairssp(n, vector <int> (n, 10000000));
	vector <vector <int>> edges(n, vector <int> (0));
	vector <vector <int>> newedges(k, vector <int> (3, 0));
	vector <int> spto1(n, 0), sptoN(n, 0), spto12(n, 0), sptoN2(n, 0), colorto1(n, 0), colortoN(n, 0), colorto12(n, 0), colortoN2(n, 0);
	
	for (int i = 0; i < m; i ++) {
		int u_i = mt_rand() % n + 1, v_i = mt_rand() % n + 1;
		cout << u_i << " " << v_i << "\n";
		edges[u_i-1].push_back(v_i-1);
	}
	
	if (atoi(argv[1]) == 24 || atoi(argv[1]) == 48) {
		for (int i = 0; i < k-2; i ++) {
			int howmanycolors = 1000000000;
			if (atoi(argv[1]) % 3 == 0) {
				howmanycolors = 1;
			}
			if (atoi(argv[1]) % 2 == 0) {
				howmanycolors = 2;
				if (atoi(argv[1]) % 3 == 0) {
					howmanycolors = 1000000000;
				}
			}
			int a = mt_rand() % n + 1, b = mt_rand() % n + 1, c = mt_rand() % howmanycolors + 1;
			cout << a << " " << b << " " << c << "\n";
			newedges[i][2] = c;
			newedges[i][0] = a-1;
			newedges[i][1] = b-1;
		}
		cout << 1 << " " << 7 << " " << 14 << "\n";
		newedges[k-2][2] = 14;
		newedges[k-2][0] = 0;
		newedges[k-2][1] = 6;
		cout << 7 << " " << n << " " << 14 << "\n";
		newedges[k-1][2] = 14;
		newedges[k-1][0] = 6;
		newedges[k-1][1] = n-1;
	}
	else {
		for (int i = 0; i < k; i ++) {
			int howmanycolors = 1000000000;
			if (atoi(argv[1]) % 3 == 0) {
				howmanycolors = 1;
			}
			if (atoi(argv[1]) % 2 == 0) {
				howmanycolors = 2;
				if (atoi(argv[1]) % 3 == 0) {
					howmanycolors = 1000000000;
				}
			}
			int a = mt_rand() % n + 1, b = mt_rand() % n + 1, c = mt_rand() % howmanycolors + 1;
			cout << a << " " << b << " " << c << "\n";
			newedges[i][2] = c;
			newedges[i][0] = a-1;
			newedges[i][1] = b-1;
		}
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
		cerr << "-1\n";
	}
	else {
		cerr << ans << "\n";
	}
	
	return 0;
}
