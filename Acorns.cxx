#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, ans=0, counter=0;
	cin >> n;
	
	vector <int> frequency(1000000, 0);
	
	for (int i = 0; i < n; i ++) {
		int x;
		cin >> x;
		frequency[x-1] += 1;
	}
	
	for (int i = 999999; i >= 0; i --) {
		if (frequency[i] > counter) {
			ans += (i+1)*(frequency[i]-counter);
			counter = frequency[i];
		}
	}
	
	cout << ans << "\n";
	
	return 0;
}

