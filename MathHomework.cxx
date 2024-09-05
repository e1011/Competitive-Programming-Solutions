#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	
	vector <long long> arr(100000, 1);
	for (int i = 1; i < 100000; i ++) {
		arr[i] = arr[i-1]*(i+1);
		arr[i] %= 1000000007;
		cout << arr[i] << "\n";
	}
	
	return 0;
}

