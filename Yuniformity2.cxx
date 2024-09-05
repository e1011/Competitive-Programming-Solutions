#include <iostream>
#include <vector>

using namespace std;

int n, q;
// initialize this to 2*n length
vector <int> segtree1(0);

int comb1(int a, int b) {
	return min(a, b);
}

void modify1(int index, int val) {
	segtree1[index+n] = val;
	for (int i = (index+n)/2; i > 0; i /= 2) {
		segtree1[i] = comb1(segtree1[2*i], segtree1[2*i+1]);
	}
}

int query1(int l, int r) {
	int lsum = 1000000000, rsum = 1000000000;
	for (l += n, r += n; l < r; l /= 2, r /= 2) {
		if (l % 2 == 1) {
			lsum = comb1(lsum, segtree1[l++]); 
		}
		if (r % 2 == 1) {
			rsum = comb1(rsum, segtree1[--r]);
		}
	}
	return comb1(lsum, rsum);
}

vector <int> segtree2(0);

int comb2(int a, int b) {
	return max(a, b);
}

void modify2(int index, int val) {
	segtree2[index+n] = val;
	for (int i = (index+n)/2; i > 0; i /= 2) {
		segtree2[i] = comb2(segtree2[2*i], segtree2[2*i+1]);
	}
}

int query2(int l, int r) {
	int lsum = -1000000000, rsum = -1000000000;
	for (l += n, r += n; l < r; l /= 2, r /= 2) {
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
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> q;
	segtree1 = vector <int> (2*n, 0);
	segtree2 = vector <int> (2*n, 0);
	vector <int> arr(n, 0), latestp(1000001, -1), latestn(1000001, -1), firstpossible(n, -1);
	int latest0=-1;
	
	for (int i = 0; i < n; i ++) {
		cin >> arr[i];
		modify1(i, arr[i]);
		modify2(i, arr[i]);
	}
	for (int i = n-1; i >= 0; i --) {
		if (arr[i] == 0) {
			firstpossible[i] = i;
			latest0=i;
		}
		else if (arr[i] > 0) {
			latestp[arr[i]] = i;
			if (latest0 != -1) {
				firstpossible[i] = latest0;
			}
			if (latestn[arr[i]] != -1) {
				if (firstpossible[i] == -1) {
					firstpossible[i] = latestn[arr[i]];
				}
				else {
					firstpossible[i] = min(firstpossible[i], latestn[arr[i]]);
				}
			}
		}
		else if (arr[i] < 0) {
			latestn[-arr[i]] = i;
			if (latest0 != -1) {
				firstpossible[i] = latest0;
			}
			if (latestp[-arr[i]] != -1) {
				if (firstpossible[i] == -1) {
					firstpossible[i] = latestp[-arr[i]];
				}
				else {
					firstpossible[i] = min(firstpossible[i], latestp[-arr[i]]);
				}
			}
		}
	}
	
	for (int i = n-2; i >= 0; i --) {
		if (firstpossible[i] == -1) {
			firstpossible[i] = firstpossible[i+1];
		}
		else if (firstpossible[i+1] != -1){
			firstpossible[i] = min(firstpossible[i], firstpossible[i+1]);
		}
	}
	
	for (int i = 0; i < q; i ++) {
		int l, r;
		cin >> l >> r;
		
		//cout << query1(l-1, r) << ", " << query2(l-1, r) << "\n";
		if (query1(l-1, r) == query2(l-1, r)) {
			cout << "YES\n";
		}
		else {
			if (firstpossible[l-1] != -1 && r-1 >= firstpossible[l-1]) {
				cout << "YES\n";
			}
			else {
				cout << "NO\n";
			}
		}
	}
	
	
	return 0;
}

