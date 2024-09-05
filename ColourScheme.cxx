#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
	int n, recent=1, counter=2;
	cin >> n;
	
	vector <int> ans(n, 0);
	ans[0] = 1;
	
	for (int i = 1; i < n; i ++) {
		int distinct;
		cout << "? 1 " << i+1 << "\n";
		cin >> distinct;
		
		if (distinct == recent) {
			// index i has been seen before. we update it
			// now binary search left index to find greatest index such that [l, i] = [l, i-1]
			// this element will be the same as the lth element
			
			vector <int> ltoiminus1(i, 0);
			set <int> s;
			for (int j = i-1; j >= 0; j --) {
				s.insert(ans[j]);
				ltoiminus1[j] = s.size();
			}
			
			vector <int> goodindices(0);
			set <int> s2;
			for (int j = i-1; j >= 0; j --) {
				if (s2.count(ans[j]) == 0) {
					goodindices.push_back(j);
					s2.insert(ans[j]);
				}
			}
			reverse(goodindices.begin(), goodindices.end());
			
			
			int l = 0, r = (int)goodindices.size() - 1;
			while (l < r) {
				int mid = (l+r+1)/2, distinct2;
				if (mid == i) {
					distinct2 = 1;
				}
				else {
					cout << "? " << goodindices[mid]+1 << " " << i+1 << "\n";
					cin >> distinct2;
				}
				
				if (distinct2 == ltoiminus1[goodindices[mid]]) {
					l = mid;
				}
				else {
					r = mid-1;
				}
			}
			ans[i] = ans[goodindices[l]];
		}
		else {
			ans[i] = counter;
			counter += 1;
		}
		recent = distinct;
	}
	
	cout << "! ";
	for (int i = 0; i < n; i ++) {
		cout << ans[i];
		if (i == n-1) {
			cout << "\n";
		}
		else {
			cout << " ";
		}
	}
	
	return 0;
}

