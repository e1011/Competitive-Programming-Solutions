#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m, q, ans=0;
	cin >> n >> m >> q;
	
	vector <int> students(n, 0);
	vector <vector <int>> edges(0);
	
	for (int i = 0; i < m; i ++) {
		int a, b;
		cin >> a >> b;
		students[a-1] += 1;
		students[b-1] += 1;
		edges.push_back({min(a-1, b-1), max(a-1, b-1)});
	}
	
	for (int i = 0; i < edges.size(); i ++) {
		if (students[edges[i][0]] > 1 && students[edges[i][1]] > 1) {
			ans = 1;
		}
	}
	if (ans) {
		cout << "YES\n";
	}
	else {
		cout << "NO\n";
	}
	
	for (int i = 0; i < q; i ++) {
		int a, b, found=0, foundindex;
		cin >> a >> b;
		for (int j = 0; j < edges.size(); j ++) {
			vector <int> k = {min(a-1, b-1), max(a-1, b-1)};
			if (edges[j] == k) {
				found = 1;
				foundindex = j;
				break;
			}
		}
		
		if (found) {
			students[a-1] -= 1;
			students[b-1] -= 1;
			edges.erase(edges.begin()+foundindex);
		}
		else {
			students[a-1] += 1;
			students[b-1] += 1;
			edges.push_back({min(a-1, b-1), max(a-1, b-1)});
		}
		
		ans = 0;
		for (int j = 0; j < edges.size(); j ++) {
			if (students[edges[j][0]] > 1 && students[edges[j][1]] > 1) {
				ans = 1;
			}
		}
		if (ans) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}
	
	return 0;
}

