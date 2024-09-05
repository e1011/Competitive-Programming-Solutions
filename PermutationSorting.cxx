#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, ans=0;
	cin >> n;
	
	vector <int> arr(n, 0);
	for (int i = 0; i < n; i ++) {
		cin >> arr[i];
	}
	
	int pointer=0, minindex=0, l;
	while (pointer < n) {
		if (arr[pointer] != pointer+1) {
			l = pointer;
			minindex = arr[pointer]-1;
			while (pointer < minindex) {
				//cout << pointer << ", " << minindex << "\n";
				pointer += 1;
				minindex = max(minindex, arr[pointer]-1);
			}
			ans += (pointer-l+1);
		}
		pointer += 1;
	}
	
	cout << ans << "\n";
	
	return 0;
}

