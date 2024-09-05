#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, q;
	cin >> n;
	
	vector <long long> arr(n, 0), psa(n, 0);
	for (int i = 0; i < n; i ++) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	
	for (int i = 0; i < n; i ++) {
		psa[i] = arr[i];
		if (i > 0) {
			psa[i] += psa[i-1];
		}
	}
	
	cin >> q;
	for (int i = 0; i < q; i ++) {
		long long a, b, ans=1000000000000000000, l=0, r=n-2;
		cin >> a >> b;
		
		while (l < r) {
			int mid = (l+r)/2;
			long long current1, current2;
			if (mid == 0) {
				current1 = (psa[n-1]-psa[0]-(n-1)*arr[0])*b;
			}
			else {
				current1 = (arr[mid]*mid-psa[mid-1])*a;
				current1 += (psa[n-1]-psa[mid]-(n-1-mid)*arr[mid])*b;
			}
			
			if (mid+1 == n-1) {
				current2 = (arr[n-1]*(n-1)-psa[n-2])*a;
			}
			else {
				current2 = (arr[mid+1]*(mid+1)-psa[mid])*a;
				current2 += (psa[n-1]-psa[mid+1]-(n-2-mid)*arr[mid+1])*b;
			}
			
			ans = min(current1, current2);
			
			if (current2 > current1) {
				r = mid;
			}
			else {
				l = mid+1;
			}
		}
//			long long current = (arr[j]*j-psa[j-1])*a;
//			current += (psa[n-1]-psa[j]-(n-1-j)*arr[j])*b;
		
		cout << ans << "\n";
	}
	
	return 0;
}

