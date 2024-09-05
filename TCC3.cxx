#include <iostream>
#include <vector>

using namespace std;

// initialize this to 2*n length
vector <int> segtree(0);

int comb(int a, int b) {
	return a+b;
}

void modify(int index, int val) {
	segtree[index+2000000] = val;
	for (int i = (index+n)/2; i > 0; i /= 2) {
		segtree[i] = comb(segtree[2*i], segtree[2*i+1]);
	}
}

int query(int l, int r) {
	int lsum = 1000000000, rsum = 1000000000;
	for (l += 2000000, r += 2000000; l < r; l /= 2, r /= 2) {
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
	int n;
	cin >> n;
	
	segtree = vector <int> (4000000, 0);
	vector <vector <int>> constraints(4, vector <int> (n, 0));
	for (int i = 0; i < 4; i ++) {
		for (int j = 0; j < n; j ++) {
			cin >> constraints[i][j];
		}
	}
	
	for (int i = 0; i < n; i ++) {
		int l = 0, r = 4000001;
		while (l < r) {
			int mid = (l+r+1)/2;
			if (query(0, mid) <= constraints[0][i]) {
				l = mid;
			}
			else {
				r = mid-1;
			}
		}
		if (query(l, 4000001) == constraints[0][i]) {
		}
		else if (query(l+1, 4000001) == constraints[0][i]) {
		
		}
		else {
			
		}
	}
	
	
	return 0;
}

