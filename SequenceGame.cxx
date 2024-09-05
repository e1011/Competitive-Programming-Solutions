#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t;
	cin >> t;
	
	for (int _ = 0; _ < t; _ ++) {
		int n;
		cin >> n;
		
		vector <int> arr(n, 0), ans(0);
		for (int i = 0; i < n; i ++) {
			cin >> arr[i];
		}
		ans.push_back(arr[0]);
		for (int i = 1; i < n; i ++) {
			if (arr[i] < arr[i-1]) {
				ans.push_back(1);
			}
			ans.push_back(arr[i]);
		}
		
		cout << ans.size() << "\n";
		
		for (int i = 0; i < ans.size(); i ++) {
			cout << ans[i] << " ";
		}
		cout << "\n";
	}
	
	return 0;
}

