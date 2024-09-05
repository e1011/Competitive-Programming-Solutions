#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, ans=0;
	cin >> n;
	
	vector <int> arr(n, 0);
	for (int i = 0; i < n; i ++) {
		cin >> arr[i];
		arr[i] -= 1;
	}
	
	for (int i = 2; i*i <= n; i ++) {
		int matches=0, mismatches=0;
		vector <int> frequency(n, 0);
		
		for (int j = 0; j < i*i; j ++) {
			frequency[arr[j]] += 1;
			if (frequency[arr[j]] == i) {
				matches += 1;
				mismatches -= 1;
			}
			else if (frequency[arr[j]] == 1) {
				mismatches += 1;
			}
			else if (frequency[arr[j]] == i+1) {
				matches -= 1;
				mismatches += 1;
			}
		}			
		if (matches == i && mismatches == 0) {
			ans += 1;
		}
		
		for (int j = i*i; j < n; j ++) {
			frequency[arr[j]] += 1;
			if (frequency[arr[j]] == i) {
				matches += 1;
				mismatches -= 1;
			}
			else if (frequency[arr[j]] == 1) {
				mismatches += 1;
			}
			else if (frequency[arr[j]] == i+1) {
				matches -= 1;
				mismatches += 1;
			}
			
			frequency[arr[j-i*i]] -= 1;
			if (frequency[arr[j-i*i]] == i) {
				matches += 1;
				mismatches -= 1;
			}
			else if (frequency[arr[j-i*i]] == 0) {
				mismatches -= 1;
			}
			else if (frequency[arr[j-i*i]] == i-1) {
				matches -= 1;
				mismatches += 1;
			}
			
			if (matches == i && mismatches == 0) {
				ans += 1;
			}
		}
	}
	
	cout << ans+n << "\n";
	
	return 0;
}

