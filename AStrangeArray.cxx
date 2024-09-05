#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, q;
	cin >> n >> q;
	
	vector <int> arr(n, 0);
	set <int> ones;
	for (int i = 0; i < n; i ++) {
		cin >> arr[i];
		if (arr[i] == 1) {
			ones.insert(i);
		}
		
		if (i != 0) {
			arr[i] += arr[i-1];
		}
	}
	
	for (int i = 0; i < q; i ++) {
		int l, r, x, works=0;
		cin >> l >> r >> x;
		
		//[l, mid]
		int lb = l-1, rb = r-1;
		while (lb < rb) {
			int mid = (lb+rb+1)/2;
			int sum = arr[mid];
			if (l != 1) {
				sum -= arr[l-2];
			}
			if (sum > x) {
				rb = mid-1;
			}
			else {
				lb = mid;
			}
		}
		
		int sum = arr[lb];
		if (l != 1) {
			sum -= arr[l-2];
		}
		if (sum == x) {
			works = 1;
		}
		
		if (ones.upper_bound(lb) != ones.end() && *ones.upper_bound(lb) < r) {
			works = 1;
		}

		// [mid, r]
		lb = l-1;
		rb = r-1;
		while (lb < rb) {
			int mid = (lb+rb)/2;
			int sum = arr[r-1];
			if (mid != 0) {
				sum -= arr[mid-1];
			}
			
			if (sum > x) {
				lb = mid+1;
			}
			else {
				rb = mid;
			}
		}
		sum = arr[r-1];
		if (lb != 0) {
			sum -= arr[lb-1];
		}
		if (sum == x) {
			works = 1;
		}
		
		if (ones.lower_bound(lb) != ones.begin() && *--ones.lower_bound(lb)+1 >= l) {
			works = 1;
		}
		
		if (works) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}
	
	
	return 0;
}

