#include <iostream>
#include <vector>
#include <set>
#include <queue>

int main() {
	int n, d;
	cin >> n >> d;
	
	multiset <vector <int>> ms1;
	multiset <vector <int>> ms2;
	queue <vector <int>> q;
	for (int i = 0; i < n; i ++) {
		int a, b;
		cin >> a >> b;
		ms1.insert({a, b});
		if (b == 0) {
			q.push({a, b, 1});
		}
	}
	for (int i = 0; i < n; i ++) {
		int a, b;
		cin >> a >> b;
		ms2.insert({b, a});
		if (a == 0) {
			q.push({a, b, 2});
		}
	}
	
	queue <vector <int>> q;
	while (q.empty() == false) {
		int b=q.top()[0], e=q.top()[1], type=q.top()[2];
		q.pop();
		if (type == 1) {
			while (*--ms2.lower_bound({b+1, 0, 0})[1] < e-d) {
				q.push({*--ms2.lower_bound({b+1, 0, 0})[0], *--ms2.lower_bound({b+1, 0, 0})[1], 2});
				ms2.erase(*--ms2.lower_bound({b+1, 0, 0}));
			}
		}
		if (type == 2) {
			while (*--ms1.lower_bound({e+1, 0, 0}))
		}
	}
	
	
	return 0;
}

