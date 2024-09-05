#include <iostream>
#include <vector>

using namespace std;


// euler tour. this one actually works
// https://cses.fi/problemset/result/8372970/
int timer = 0;
vector <int> euler(0), st, segtree;
vector <vector <int>> graph;

void dfs(int node, int parent) {
	st[node] = timer;
	euler.push_back(node);
	timer += 1;
	
	for (int i = 0; i < graph[node].size(); i ++) {
		if (graph[node][i] != parent) {
			dfs(graph[node][i], node);
			euler.push_back(node);
			timer += 1;
		}
	}
}

// if appears first compared to subtree, it will have lower depth
int comb(int a, int b) {
	if (a == -1) {
		return b;
	}
	if (b == -1 || st[a] < st[b]) {
		return a;
	}
	return b;
}

void modify(int index, int val) {
	segtree[index+euler.size()] = val;
	for (int i = (index+euler.size())/2; i > 0; i /= 2) {
		segtree[i] = comb(segtree[2*i], segtree[2*i+1]);
	}
}

int query(int l, int r) {
	int lsum = -1, rsum = -1;
	for (l += euler.size(), r += euler.size(); l < r; l /= 2, r /= 2) {
		if (l % 2 == 1) {
			lsum = comb(lsum, segtree[l++]); 
		}
		if (r % 2 == 1) {
			rsum = comb(rsum, segtree[--r]);
		}
	}
	return comb(lsum, rsum);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, q;
	cin >> n >> q;
	
	graph = vector <vector <int>> (n, vector <int> (0));
	st = vector <int> (n, 0);
	for (int i = 0; i < n-1; i ++) {
		int x;
		cin >> x;
		graph[x-1].push_back(i+1);
		graph[i+1].push_back(x-1);
	}
	
	dfs(0, -1);
	segtree = vector <int> (2*euler.size(), 0);
	for (int i = 0; i < euler.size(); i ++) {
		modify(i, euler[i]);
	}
	
	
	for (int i = 0; i < q; i ++) {
		int a, b;
		cin >> a >> b;
		cout << query(min(st[a-1], st[b-1]), max(st[a-1], st[b-1])+1)+1 << "\n";
	}
	
	return 0;
}

