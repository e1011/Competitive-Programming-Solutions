#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
	long long n, ans=0;
	cin >> n;
	
	vector <long long> arr(n, 0);
	
	for (int i = 0; i < n; i ++) {
		cin >> arr[i];
	}
	
	set <long long> s;
	vector <long long> costs(100001, 0);
	vector <long long> values(100001, 0);
	for (int i = n-1; i >= 0; i --) {
		// if there is element w/ smaller or equal val
		if (s.upper_bound(arr[i]) != s.begin()) {
			ans += costs[*--s.upper_bound(arr[i])];
			// if there is an element with greater or equal val
			if (s.lower_bound(arr[i]) != s.end()) {
				ans += (arr[i]-(*--s.upper_bound(arr[i])))*(values[*s.upper_bound(arr[i])]);
			}
			// if this is the greatest element
			else {
				ans += (arr[i]-(*--s.upper_bound(arr[i])))*(i+1);
				values[arr[i]] = i+1;
				costs[arr[i]] = costs[*--s.upper_bound(arr[i])] + (arr[i]-(*--s.upper_bound(arr[i])))*(i+1);
				s.insert(arr[i]);
			}
		}
		// this is the smallest element
		else {
			// there is an element with greater or equal val
			if (s.lower_bound(arr[i]) != s.end()) {
				ans += arr[i]*(values[*s.upper_bound(arr[i])]);
			}
			// this is the greatest element
			else {
				ans += (arr[i])*(i+1);
				values[arr[i]] = i+1;
				costs[arr[i]] = arr[i]*(i+1);
				s.insert(arr[i]);
			}
		}
		
		/*
		cout << ans << "\n";
		for (int i = 0; i < n+1; i ++) {
			cout << costs[i] << " ";
		}
		cout << "\n";
		* */
	}
	
	cout << ans << "\n";
	
	
	return 0;
}

// upper bound and lower bound causing erroneous edits of val array when elements are equal
