#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class T> using Tree = tree<
	T, null_type, less_equal<T>,
	rb_tree_tag, tree_order_statistics_node_update
>;

int main() {
	long long n, m, ans=-1000000000000000000;
	cin >> n >> m;
	
	vector <vector <long long>> execs(n, vector <long long> (2, 0));
	for (int i = 0; i < n; i ++) {
		cin >> execs[i][1] >> execs[i][0];
	}
	
	Tree <long long> tree;
	sort(execs.begin(), execs.end());
	for (int i = 0; i < n; i ++) {
		tree.insert(execs[i][1]);
		if (i+1 >= m) {
			ans = max(ans, *tree.find_by_order(m-1)-execs[i][0]);
		}
	}
	
	cout << ans << "\n";
}

