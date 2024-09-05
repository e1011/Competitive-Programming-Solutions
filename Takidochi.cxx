#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, ans=-1, evencount=0, oddcount=0, maximum = 0;
	cin >> n;
	
	vector <int> arr(n, 0), even(n, 0), odd(n, 0), psuml(n, 0), psumr(n, 0);
	for (int i = 0; i < n; i ++) {
		cin >> arr[i];
		maximum = max(maximum, arr[i]);
	}
	
	for (int i = n-1; i >= 0; i --) {
		if (arr[i] % 2 == 0) {
			evencount += 1;
		}
		else {
			oddcount += 1;
		}
		
		if (i != n-1) {
			even[i] = evencount;
			odd[i] = oddcount;
		}
		
		psumr[i] = arr[i];
		if (i != n-1) {
			psumr[i] += psumr[i+1];
		}
	}
	
	for (int i = 0; i < n; i ++) {
		psuml[i] = arr[i];
		if (i != 0) {
			psuml[i] += psuml[i-1];
		}
		
		if (i > 0 && 2*i != n-i) {
			int k1 = (-psuml[i-1]+2*psumr[i]+3*even[i])/(2*i - (n-i));
			int k2 = (-psuml[i-1]+2*psumr[i]+3*odd[i])/(2*i - (n-i));
			cout << k1 << ", " << k2 << "\n";
			
			if ((-psuml[i-1]+2*psumr[i]+3*even[i]) % (2*i - (n-i)) == 0) {
				ans = max(ans, k1);
			}
			if ((-psuml[i-1]+2*psumr[i]+3*odd[i]) % (2*i - (n-i)) == 0) {
				ans = max(ans, k2);
			}
		}
		else if (i > 0 && (2*i == n-i) && psuml[i-1] == psumr[i]) {
			ans = max(ans, maximum);
		}
	}
	
	for (int i = 0; i < n; i ++) {
		cout << even[i] << " " << odd[i] << " " << psuml[i] << " " << psumr[i] << "\n"; 
	}
	
	cout << ans << "\n";
	
	return 0;
}

