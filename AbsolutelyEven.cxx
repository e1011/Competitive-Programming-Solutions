#include <iostream>
#include <vector>

using namespace std;

int main() {
	long long n, nprime;
	cin >> n;
	nprime = n*(n+1)/4;
	//cout << nprime << "\n";
	
	vector <int> negatives(n, 0);
	
	for (int i = n; i > 0; i --) {
		if (nprime >= i) {
			negatives[i-1] = 1;
			nprime -= i;
			//cout << i << "\n";
		}
	}
	
	long long sum = 0;
	for (int i = 0; i < n; i ++) {
		// positive
		if (negatives[i] == 0) {
			if (sum < 0) {
				// last one is a negative
				cout << -1*sum;
				sum = 0;
			}
			else {
				// last one is a positive
				cout << 0;
			}
		}
		//negative
		else {
			if (sum == 0) {
				// meaning that the last one is a positive
				cout << min(-i, -1);
				sum = min(-i, -1);
			}
			else {
				// meaning that the last one is a negative
				cout << -1;
				sum -= 1;
			}
		}
		
		if (i == n-1) {
			cout << "\n";
		}
		else {
			cout << " ";
		}
	}
	
	
	return 0;
}

