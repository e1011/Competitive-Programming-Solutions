#include <iostream>
#include <vector>

using namespace std;


// edgeplacements, euler2 and segtree2 handle edges
vector <vector <long long>> graph, costs, ind, edgeplacements;
vector <long long> euler(0), euler2(1, 0), st, segtree, segtree2;

void dfs(long long node, long long parent) {
	st[node] = euler.size();
	euler.push_back(node);
	for (int i = 0; i < graph[node].size(); i ++) {
		if (graph[node][i] != parent) {
			euler2.push_back(costs[node][i]);
			edgeplacements[ind[node][i]+1].push_back((int)euler2.size() - 1);
			dfs(graph[node][i], node);
			euler2.push_back(-costs[node][i]);
			edgeplacements[ind[node][i]+1].push_back((int)euler2.size() - 1);
			euler.push_back(node);
		}
	}
}

long long comb(long long a, long long b) {
	if (a == -1) {
		return b;
	}
	if (b == -1) {
		return a;
	}
	if (st[a] < st[b]) {
		return a;
	}
	return b;
}

void modify(long long index, long long val) {
	segtree[index+euler.size()] = val;
	for (int i = (index+euler.size())/2; i > 0; i /= 2) {
		segtree[i] = comb(segtree[2*i], segtree[2*i+1]);
	}
}

long long query(long long l, long long r) {
	long long lsum = -1, rsum = -1;
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


long long comb2(long long a, long long b) {
	return a+b;
}

void modify2(long long index, long long val) {
	segtree2[index+euler2.size()] = val;
	for (int i = (index+euler2.size())/2; i > 0; i /= 2) {
		segtree2[i] = comb2(segtree2[2*i], segtree2[2*i+1]);
	}
}

long long query2(long long l, long long r) {
	long long lsum = 0, rsum = 0;
	for (l += euler2.size(), r += euler2.size(); l < r; l /= 2, r /= 2) {
		if (l % 2 == 1) {
			lsum = comb2(lsum, segtree2[l++]); 
		}
		if (r % 2 == 1) {
			rsum = comb2(rsum, segtree2[--r]);
		}
	}
	return comb2(lsum, rsum);
}

int main() {
	long long n, q;
	cin >> n;
	
	graph = vector <vector <long long>> (n, vector <long long> (0));
	costs = graph;
	ind = graph;
	edgeplacements = graph;
	st = vector <long long> (n, 0);
	for (int i = 0; i < n-1; i ++) {
		long long a, b, c;
		cin >> a >> b >> c;
		graph[a-1].push_back(b-1);
		graph[b-1].push_back(a-1);
		costs[a-1].push_back(c);
		costs[b-1].push_back(c);
		ind[a-1].push_back(i);
		ind[b-1].push_back(i);
	}
	dfs(0, -1);
	
	segtree = vector <long long> (2*euler.size(), 0);
	segtree2 = vector <long long> (2*euler2.size(), 0);
	for (int i = 0; i < euler.size(); i ++) {
		modify(i, euler[i]);
	}
	
	for (int i = 0; i < euler2.size(); i ++) {
		modify2(i, euler2[i]);
	}
	
	cin >> q;
	for (int i = 0; i < q; i ++) {
		long long a, b, c;
		cin >> a >> b >> c;
		if (a == 1) {
			modify2(edgeplacements[b][0], c);
			modify2(edgeplacements[b][1], -c);
		}
		else {
			long long lca = query(min(st[b-1], st[c-1]), max(st[b-1], st[c-1])+1);
			cout << 2*query2(st[lca]+1, min(st[b-1], st[c-1])+1) + query2(min(st[b-1], st[c-1])+1, max(st[b-1], st[c-1])+1) << "\n";
		}
	}
	
	
	return 0;
}
// https://atcoder.jp/contests/abc294/tasks/abc294_g

