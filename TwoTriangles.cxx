#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, count=0;
	long long sum=0;
	cin >> n;
	
	vector <long long> arr(n, 0);
	for (int i = 0; i < n; i ++) {
		cin >> arr[i];
	}
	
	sort(arr.begin(), arr.end());
	reverse(arr.begin(), arr.end());
	for (int i = 0; i < n-2; i ++) {
		if (arr[i] < (arr[i+1] + arr[i+2])) {
			sum += arr[i]+arr[i+1]+arr[i+2];
			count += 1;
			i += 2;
		}
		if (count == 2) {
			break;
		}
	}
	
	if (count == 2) {
		cout << sum << "\n";
	}
	else {
		cout << "0\n";
	}
	
	return 0;
}

