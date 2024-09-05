#include <iostream>

using namespace std;

int main() {
	int k;
	cin >> k;
	
	vector <int> arr(k, 0);
	vector <int> arr2(0);
	vector <int> dp(k+1, 0);
	int length=0, start=arr[0];
	
	for (int i = 0; i < k; i ++) {
		cin >> arr[i];
		if (i != 0 && arr[i] != arr[i-1]) {
			length = 0;
			arr2.push_back(length);
		}
		length += 1;
	}
	
	
	
	
	
	return 0;
}

