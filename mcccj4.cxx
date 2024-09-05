#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
	string s, s2;
	int n, k, ans=0, counter=0, first1=0;
	cin >> n >> k >> s;
	s2 = s;
	
	for (int i = n-2; i >= 0; i --) {
		if (s[i+1] == '1') {
			s2[i] = '0';
		}
	}
	s = s2;
	
	for (int i = 0; i < n; i ++) {
		if (s[i] == '1') {
			if (i == 0 || s[i-1] == '0') {
				ans += 1;
			}
		}
	}
	if (ans == 0 && k > 0) {
		cout << 1 << "\n";
		return 0;
	}
	
	for (int i = 0; i < n; i ++) {
		if (s[i] == '1') {
			first1 = i;
			break;
		}
	}
	
	vector <int> gaps(0);
	for (int i = first1+1; i < n; i ++) {
		if (s[i] == '1') {
			gaps.push_back(counter);
			counter = 0;
		}
		else {
			counter += 1;
		}
	}
	
	sort(gaps.begin(), gaps.end());
	for (int i = 0; i < gaps.size(); i ++) {
		if (k >= gaps[i]) {
			k -= gaps[i];
			ans -= 1;
		}
	}
	
	cout << ans << "\n";
	
	return 0;
}
