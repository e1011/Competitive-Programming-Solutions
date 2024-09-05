#include <iostream>
#include <vector>

using namespace std;

vector <int> e(0);

int get(int node) {
	if (e[node] < 0) {
		return node;
	}
	else {
		e[node] = get(e[node]);
		return e[node];
	}
}

void unite(int node1, int node2) {
	int a = get(node1), b = get(node2);
	if (a == b) {
		return;
	}
	if (e[a] > e[b]) {
		swap(a, b);
	}
	
	e[b] += e[a];
	e[a] = b;
}

int main() {
	int n, q;
	cin >> n >> q;
	e = vector <int> (n, -1);
	
	for (int i = 0; i < q; i ++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 0) {
			unite(b, c);
		}
		else {
			cout << (get(b) == get(c)) << "\n"; 
		}
	}
	
	return 0;
}

