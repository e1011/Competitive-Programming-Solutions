#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
	int n, counter=0;
	cin >> n;
	
	vector <vector <int>> arr(2*n, vector <int> (3, 0));
	vector <int> ans(n+1, 0);
	set <vector <int>> s;
	for (int i = 0; i < n; i ++) {
		cin >> arr[i][0];
		arr[i][1] = i;
		arr[i][2] = 0;
	}
	for (int i = 0; i < n; i ++) {
		cin >> arr[n+i][0];
		arr[n+i][1] = i;
		arr[n+i][2] = 1;
	}
	
	sort(arr.begin(), arr.end());
	ans[0] = arr[0][0];
	for (int i = 0; i < 2*n; i ++) {
		//cout << arr[i][0] << ", " << arr[i][1] << ", " << arr[i][2] << "\n"; 
		if (s.count({arr[i][1], !arr[i][2]})) {
			break;
		}
		else {
			if (s.size() == 0) {
				if (arr[i][2] == 0) {
					counter += 1;
				}
			}
			else if (s.upper_bound({arr[i][1], arr[i][2]}) == s.begin()) {
				// no element to the left
				if (arr[i][2] == 0) {
					counter += 1;
					if (arr[i][2] != (*s.upper_bound({arr[i][1], arr[i][2]}))[1]) {
						counter += 1;
					}
				}

			}
			else if (s.upper_bound({arr[i][1], arr[i][2]}) == s.end()) {
				// no element to the right
				if (arr[i][2] != (*--s.upper_bound({arr[i][1], arr[i][2]}))[1]) {
					counter += 1;
				}
			}
			else {
				if ((*--s.upper_bound({arr[i][1], arr[i][2]}))[1] == (*s.upper_bound({arr[i][1], arr[i][2]}))[1] &&
				(*--s.upper_bound({arr[i][1], arr[i][2]}))[1] != arr[i][2]) {
					counter += 2;
				}
			}
			
			s.insert({arr[i][1], arr[i][2]});
		}
		if (arr[i][0] != arr[i+1][0]) {
			ans[counter] = max(ans[counter], arr[i+1][0]);
			//cout << "yes, " << arr[i+1][0] << "\n";
		}
		//cout << counter << "\n";
	}
	
	cout << ans[0] << "\n";
	for (int i = 0; i < n; i ++) {
		ans[i+1] = max(ans[i+1], ans[i]);
		cout << ans[i+1] << "\n";
	}
	
	return 0;
}

// cannot find error
