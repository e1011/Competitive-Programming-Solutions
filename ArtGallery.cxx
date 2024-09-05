#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
	int n;
	string s1, s2;
	cin >> n >> s1 >> s2;
	
	vector <int> arr1(0), arr2(0);
	set <int> a, b;
	
	for (int i = 0; i < n; i ++) {
		if (s1[i] == 'A') {
			arr1.push_back(i);
		}
		if (s2[i] == 'A') {
			arr2.push_back(i);
		}
	}
	
	reverse(arr1.begin(), arr1.end());
	reverse(arr2.begin(), arr2.end());
	for (int i = 0; i < arr1.size(); i ++) {
		int x = arr1[i];
		if (a.size() == 0) {
			x += 2*((n-x-1)/2);
		}
		else {
			x += 2*((*a.lower_bound(0)-x-1)/2);
		}
		
		if (a.count(x+1)) {
			a.erase(x+1);
		}
		else {
			a.insert(x);
		}
	}
	
	for (int i = 0; i < arr2.size(); i ++) {
		int x = arr2[i];
		if (b.size() == 0) {
			x += 2*((n-x-1)/2);
		}
		else {
			x += 2*((*b.lower_bound(0)-x-1)/2);
		}
		
		if (b.count(x+1)) {
			b.erase(x+1);
		}
		else {
			b.insert(x);
		}
	}
	
	if (a == b) {
		cout << "YES\n";
	}
	else {
		cout << "NO\n";
	}
		
	return 0;
}


// flip 2 adjacent ones of same color
// it is reversible because you can flip it back
// if both can be flipped to the same position, it should be similar
// combine 2 identical adjacents
// shift one two spaces right, if space is available
// iterate from largest to smallest
// shift it as right as possible
// add it to set. if there is another one with +1, erase both

