#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
	int n;
	cin >> n;
	
	vector <vector <int>> arr(n, vector <int> (2, 0));
	for (int i = 0 ; i < n; i ++){
		cin >> arr[i][0] >> arr[i][1];
	}	
	sort(arr.begin(), arr.end());
	
	double ans=0;
	for (int i = 0; i < n-1; i ++) {
		if ((float)abs(arr[i+1][1]-arr[i][1])/(arr[i+1][0]-arr[i][0]) > ans) {
			ans = (float)abs(arr[i+1][1]-arr[i][1])/(arr[i+1][0]-arr[i][0]);
		}
	}
	
	cout << fixed << setprecision(5) << ans << "\n";
	
	return 0;
}

