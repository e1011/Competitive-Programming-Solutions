#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> segtree1, segtree2;

int comb(int a, int b) {
	return a+b;
}

void modify1(int index, int val) {
	segtree1[index+1000000] += val;
	for (int i = (index+1000000)/2; i > 0; i /= 2) {
		segtree1[i] = comb(segtree1[2*i], segtree1[2*i+1]);
	}
}

int query1(int l, int r) {
	int lsum = 0, rsum = 0;
	for (l += 1000000, r += 1000000; l < r; l /= 2, r /= 2) {
		if (l % 2 == 1) {
			lsum = comb(lsum, segtree1[l++]); 
		}
		if (r % 2 == 1) {
			rsum = comb(rsum, segtree1[--r]);
		}
	}
	return comb(lsum, rsum);
}

void modify2(int index, int val) {
	segtree2[index+1000000] += val;
	for (int i = (index+1000000)/2; i > 0; i /= 2) {
		segtree2[i] = comb(segtree2[2*i], segtree2[2*i+1]);
	}
}

int query2(int l, int r) {
	int lsum = 0, rsum = 0;
	for (l += 1000000, r += 1000000; l < r; l /= 2, r /= 2) {
		if (l % 2 == 1) {
			lsum = comb(lsum, segtree2[l++]); 
		}
		if (r % 2 == 1) {
			rsum = comb(rsum, segtree2[--r]);
		}
	}
	return comb(lsum, rsum);
}

int main() {
	int n;
	cin >> n;
	
	segtree1 = vector <int>(2000000, 0);
	segtree2 = vector <int>(2000000, 0);
	vector <vector <int>> points(n, vector <int> (2, 0));
	for (int i = 0; i < n; i ++) {
		cin >> points[i][0] >> points[i][1];
	}
	
	sort(points.begin, points.end());
	for (int i = 0; i < n; i ++) {
		modify2(points[i][1], 1);
	}
	
	int pointer=0;
	while (pointer < n) {
		while (pointer < n && points[pointer][0] == points[pointer][0]) {
			
			pointer += 1;
		}
		pointer += 1;
	}

	
	return 0;
}

