#include <iostream>
#include <vector>
#include <stack>

using namespace std;

long long n, k;
// initialize this to 2*n length
vector <long long> segtree(0);

long long comb(long long a, long long b) {
	return a+b;
}

void modify(long long index, long long val) {
	segtree[index+n] = val;
	for (int i = (index+n)/2; i > 0; i /= 2) {
		segtree[i] = comb(segtree[2*i], segtree[2*i+1]);
	}
}

long long query(long long l, long long r) {
	long long lsum = 0, rsum = 0;
	for (l += n, r += n; l < r; l /= 2, r /= 2) {
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
	cin >> n >> k;
	
	segtree = vector <long long> (2*n, 0);
	vector <vector <long long>> queries(k, vector <long long> (0));
	vector <long long> x(k, 0), ans(k, 0);
	
	for (int i = 0; i < n; i ++) {
		long long x;
		cin >> x;
		modify(i, x);
		if (x <= k) {
			queries[x-1].push_back(i);
		}
	}
	
	for (int i = 0; i < k; i ++) {
		cin >> x[i];
	}
	
	for (int i = 0; i < k; i ++) {
		ans[i] = query(0, n);
		stack <vector <long long>> s;
		s.push({-1, -1});
		for (int j = 0; j < queries[i].size(); j ++) {
			long long counter = x[i]+1, pointer = queries[i][j];
			while (counter && pointer >= 0) {
				if (pointer - counter >= s.top()[1]) {
					ans[i] -= query(pointer-counter+1, pointer+1);
					pointer -= counter;
					counter = 0;
				}
				else {
					counter -= (pointer-s.top()[1]);
					ans[i] -= query(s.top()[1]+1, pointer+1);
					pointer = s.top()[0]-1;
					s.pop();
				}
			}
			if (pointer >= 0) {
				s.push({pointer+1, queries[i][j]});
			}
			else {
				s.push({0, queries[i][j]});
			}
		}
	}
	
	for (int i = 0; i < k; i ++) {
		cout << ans[i] << "\n";
	}
	
	return 0;
}

