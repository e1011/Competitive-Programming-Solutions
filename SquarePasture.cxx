#include <iostream>
#include <vector>

using namespace std;

int compx, compy;
bool comp(vector <int> a, vector <int> b) {
	return max(a[0]-compx, a[1]-compy) < max(b[0]-compx, b[1]-compy);
}

int main() {
	int n, ans=1;
	cin >> n;
	
	vector <vector <int>> arr(n, vector <int> (2, 0));
	vector <vector <int>> arr2 = arr;
	for (int i = 0; i < n; i ++) {
		compx=arr[i][0], compy=arr[i][1];
		int dif=-1;
		for (int j = 0; j < n; j ++) {
			if (arr2[j][0] >= compx && arr2[j][1] >= compy) {
				ans += (max(arr2[j][0]-compx, arr2[j][1]-compy) > dif);
				dif = max(arr2[j][0]-compx, arr2[j][1]-compy);
			}
		}
	}
	
	cout << ans << "\n";
	
	return 0;
}

