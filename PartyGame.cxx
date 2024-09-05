#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	
	vector <int> arr(1000001, 0);
	vector <int> arr1(n, 0);
	for (int i = 0; i < n; i ++) {
		cin >> arr1[i];
		arr[arr1[i]] += 1;
	}
	
	
	for (int i = 0; i < n; i ++) {
		int sum = -1;
		for (int j = 1; j*j <= arr1[i]; j ++) {
			if (arr1[i] % j == 0) {
				sum += arr[j];
				if (j*j != arr1[i]) {
					sum += arr[arr1[i]/j];
				}
			}
		}
		cout << sum << "\n";
	}
	
	
	return 0;
}

