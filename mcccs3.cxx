#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
	long long n, minresult=2000000000, index, shift;
	cin >> n;
	
	vector <int> arr(n, 0);
	vector <long long> ps(n, 0);
	
	for (int i = 0; i < n; i ++) {
		cin >> arr[i];
		ps[i] = arr[i];
	}
	
	for (int i = 1; i < n; i ++) {
		ps[i] += ps[i-1];
	}
	
	multiset <vector <int>> s1, s2, s3, s4;
	for (int i = 0; i < n; i ++) {
		s1.insert({2*arr[i], -i});
		s2.insert({2*arr[i], i});
	}
	
	for (int i = 0; i < n; i ++) {
		long long rawdifference = ps[n-1] - ps[i], bigger = 1;
		if (i > 0) {
			rawdifference -= ps[i-1];
		}
		if (rawdifference < 0) {
			bigger = 0;
		}
		rawdifference = abs(rawdifference);
		
		s1.erase({2*arr[i], -i});
		s2.erase({2*arr[i], i});
		
		//cout << rawdifference << ", " << bigger << ", " << minresult << ", " << shift <<  "\n";
		// dont use any shift
		vector <vector <int>> candidates(0);
		candidates.push_back({rawdifference, -2, 0});
		// try smaller right
		if (bigger == 1 && s1.lower_bound({rawdifference, 0}) != s1.begin()) {
			candidates.push_back({abs(rawdifference-(*--s1.lower_bound({rawdifference, 0}))[0]), -(*--s1.lower_bound({rawdifference, 0}))[1], 34});
		}
		// try bigger right
		if (bigger == 1 && s2.lower_bound({rawdifference, 0}) != s2.end()) {
			candidates.push_back({abs(rawdifference-(*s2.lower_bound({rawdifference, 0}))[0]), (*s2.lower_bound({rawdifference, 0}))[1], 33});
		}
		// try smaller left
		if (bigger == 0 && s3.lower_bound({rawdifference, 0}) != s3.begin()) {
			candidates.push_back({abs(rawdifference-(*--s3.lower_bound({rawdifference, 0}))[0]), -(*--s3.lower_bound({rawdifference, 0}))[1], 32});
		}
		// try bigger left
		if (bigger == 0 && s4.lower_bound({rawdifference, 0}) != s4.end()) {
			candidates.push_back({abs(rawdifference-(*s4.lower_bound({rawdifference, 0}))[0]), (*s4.lower_bound({rawdifference, 0}))[1], 31});
		}
		sort(candidates.begin(), candidates.end());
		
		if (minresult > candidates[0][0]) {
			minresult = candidates[0][0];
			index = i;
			shift = candidates[0][1];
		}
		
		s3.insert({2*arr[i], -i});
		s4.insert({2*arr[i], i});
	}
	
	cout << index+1 << " " << shift+1 << "\n";
	
	return 0;
}

