#include <iostream>
#include <vector>

using namespace std;

// answers q queries, shortest path from u to v of length exactly k
// multiplies by vector, fake starting node to answer queries fast
// https://dmoj.ca/problem/ray

const long long maximum = 1000000000000000001;

vector <vector <long long>> matrix;
vector <vector <vector <long long>>> matrices(31, vector <vector <long long>> (0));

vector <vector <long long>> multiply(vector <vector <long long>> a, vector <vector <long long>> b) {
	// a*n, n*b -> a*b
	vector <vector <long long>> ans(a.size(), vector <long long> (b[0].size(), maximum));
	for (int i = 0; i < a.size(); i ++) {
		for (int j = 0; j < b[0].size(); j ++) {
			for (int k = 0; k < a[0].size(); k ++) {
				ans[i][j] = min(ans[i][j], a[i][k]+b[k][j]);
			}
		}
	}
	return ans;
}



int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m, q;
	cin >> n >> m >> q;

	matrix = vector <vector <long long>> (n, vector <long long> (n, maximum));
	for (int i = 0; i < m; i ++) {
		long long a, b, c;
		cin >> a >> b >> c;
		matrix[a-1][b-1] = min(matrix[a-1][b-1], c);
	}
	
	matrices[0] = matrix;
	for (int i = 1; i < 31; i ++) {
		matrices[i] = multiply(matrices[i-1], matrices[i-1]);
	}

	for (int i = 0; i < q; i ++) {
		long long u, v, k;
		cin >> u >> v >> k;
		
		vector <vector <long long>> start(1, vector <long long> (n, maximum));
		start[0][u-1] = 0;
		for (int j = 0; (1 << j) <= k; j ++) {
			if (k & (1 << j)) {
				start = multiply(start, matrices[j]);
			}
		}
		if (start[0][v-1] == maximum) {
			cout << "-1\n";
		}
		else {
			cout << start[0][v-1] << "\n";
		}
	}
}

