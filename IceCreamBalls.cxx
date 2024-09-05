#include <iostream>

using namespace std;

int main() {
	int t;
	cin >> t;
	
	for (int _ = 0; _ < t; _ ++) {
		long long n, l=1, r=3000000000, mid;
		cin >> n;
		
		while (l < r) {
			mid = (l+r+1)/2;
			
			if ((mid*(mid+1))/2 <= n) {
				l = mid;
			}
			else {
				r = mid-1;
			}
		}
		
		cout << r+1+n-(r*(r+1))/2 << "\n";
	}
	
	return 0;
}

