#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int n;
	long long ans=0;
	cin >> n;
	
	vector <int> arr(n, 0);
	
	for (int i = 0; i < n; i ++) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	
	reverse(arr.begin(), arr.end());
	for (int i = 1; i < n; i ++) {
		ans += arr[i];
	}
	
	cout << ans << "\n";
	
	return 0;
}

