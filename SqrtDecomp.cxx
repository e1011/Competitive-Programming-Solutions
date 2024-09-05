#include <vector>
#include <iostream>
#include <cmath>
 
using namespace std;
 
int n, sq, q;
vector <long long> blocks, arr;
 
void modify(int index, int val) {
	blocks[index/sq] -= arr[index];
	arr[index] = val;
	blocks[index/sq] += arr[index];
}
 
// [l, r]
long long query(int l, int r) {
	long long res = 0;
	for (; l <= r; l ++) {
		if (l % sq == 0 && l + sq - 1 <= r) {
			res += blocks[l/sq];
			l += sq-1;
		}
		else {
			res += arr[l];
		}
	}
	return res;
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> q;
	sq = sqrt(n);
	
	blocks = vector <long long> (100000, 0);
	arr = vector <long long> (n, 0);
	for (int i = 0; i < n; i ++) {
		cin >> arr[i];
		blocks[i/sq] += arr[i];
	}
	
	for (int i = 0; i < q; i ++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 1) {
			modify(b-1, c);
		}
		else {
			cout << query(b-1, c-1) << "\n";
		}
	}
	
	
	return 0;
}

