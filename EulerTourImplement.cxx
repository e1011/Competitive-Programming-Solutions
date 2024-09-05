#include <iostream>
#include <vector>

using namespace std;

// euler tour
vector <int> nodes, st, en;
vector <vector <int>> graph;
int timer = 0;

void dfs(int node, int parent) {
	st[node] = timer++;
	for (int i = 0; i < graph[node].size(); i ++) {
		if (graph[node][i] != parent) {
			dfs(graph[node][i], node);
		}
	}
	en[node] = timer-1;
}

// segment tree
int n, q;
vector <long long> segtree(0);

long long comb(long long a, long long b) {
	return a+b;
}

void modify(int index, long long val) {
	segtree[index+n] = val;
	for (int i = (index+n)/2; i > 0; i /= 2) {
		segtree[i] = comb(segtree[2*i], segtree[2*i+1]);
	}
}

long long query(int l, int r) {
	long long lsum = 0, rsum = 0;
	for (l += n, r += n; l < r; l /= 2, r /= 2) {
		if (l % 2 == 1) {
			lsum = comb(lsum, segtree[l++]); 
		}
		if (r % 2 == 1) {
			rsum = comb(segtree[--r], rsum);
		}
	}
	return comb(lsum, rsum);
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> q;
	nodes = vector <int> (n, 0);
	st = vector <int> (n, 0);
	en = vector <int> (n, 0);
	graph = vector <vector <int>> (n, vector <int> (0));
	segtree = vector <long long> (2*n, 0);
	
	vector <int> startvalues(n, 0);
	for (int i = 0; i < n; i ++) {
		cin >> startvalues[i];
	}
	
	for (int i = 0; i < n-1; i ++) {
		int a, b;
		cin >> a >> b;
		graph[a-1].push_back(b-1);
		graph[b-1].push_back(a-1);
	}
	dfs(0, -1);
	
	for (int i = 0; i < n; i ++) {
		modify(st[i], startvalues[i]);
	}
	
	for (int i = 0; i < q; i ++) {
		int a, b, c;
		cin >> a;
		if (a == 1) {
			cin >> b >> c;
			modify(st[b-1], c);
		}
		else {
			cin >> b;
			cout << query(st[b-1], en[b-1]+1) << "\n";
		}
	}
	
	
	return 0;
}

