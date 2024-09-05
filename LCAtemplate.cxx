#include <iostream>
#include <vector>

using namespace std;

int n, q, counter=0, depth=0;
vector <vector <int>> segtree, graph(0);
vector <int> start, etour(0), depths(0);

// {depth of node, index of node}
// this will get the index of the node with the minimum depth, which is lowest common ancester
vector <int> comb(vector <int> a, vector <int> b) {
	if (a[0] < b[0]) {
		return a;
	}
	return b;
}

void modify(int index, vector <int> val) {
	segtree[index+etour.size()] = val;
	for (int i = (index+etour.size())/2; i > 0; i /= 2) {
		segtree[i] = comb(segtree[2*i], segtree[2*i+1]);
	}
}

vector <int> query(int l, int r) {
	vector <int> lsum = {1000000000, -1}, rsum = {1000000000, -1};
	for (l += etour.size(), r += etour.size(); l < r; l /= 2, r /= 2) {
		if (l % 2 == 1) {
			lsum = comb(lsum, segtree[l++]); 
		}
		if (r % 2 == 1) {
			rsum = comb(rsum, segtree[--r]);
		}
	}
	return comb(lsum, rsum);
}


void dfs(int node, int parent) {
	counter += 1;
	depth += 1;
	start[node] = counter;
	etour.push_back(node);
	depths.push_back(depth);
	for (int i = 0; i < graph[node].size(); i ++) {
		if (graph[node][i] != parent) {
			dfs(graph[node][i], node);
			etour.push_back(node);
			depths.push_back(depth);
		}
	}
	counter += 1;
	depth -= 1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> q;
	
	graph = vector <vector <int>> (n, vector <int> (0));
	start = vector <int> (n, 0);
	
	// input the graph
	for (int i = 1; i < n; i ++) {
		int x;
		cin >> x;
		graph[i].push_back(x-1);
		graph[x-1].push_back(i);
	}
	
	// get euler tour
	dfs(0, -1);
	
	// initialize segtree with euler tour
	segtree = vector <vector <int>> (2*etour.size(), vector <int> (2, 0));
	for (int i = 0; i < etour.size(); i ++) {
		modify(i, {depths[i], etour[i]});
	}
 	
	// make lca queries
	for (int i = 0; i < q; i ++) {
		int a, b;
		cin >> a >> b;
		cout << query(min(start[a-1], start[b-1])-1, max(start[a-1], start[b-1]))[1]+1 << "\n";
	}
	
	
	return 0;
}

// https://cses.fi/problemset/task/1688
