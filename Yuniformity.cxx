#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int SQRT = 700;

bool comp(vector <int> a, vector <int> b) {
	if (a[0]/SQRT != b[0]/SQRT) {
		return a[0]/SQRT < b[0]/SQRT;
	}
	if (a[0]/SQRT % 2 == 0) {
		return a[1] > b[1];
	}
	else {
		return a[1] < b[1];
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, q;
	cin >> n >> q;
	
	// queries are l-1, r-1, index
	// feed into ans after doing sqrt sort
	vector <int> arr(n, 0), ans(q, 0);
	vector <vector <int>> queries(q, vector <int> (3, 0));
	for (int i = 0; i < n; i ++) {
		cin >> arr[i];
	}
	for (int i = 0; i < q; i ++) {
		cin >> queries[i][0] >> queries[i][1];
		queries[i][0] -= 1;
		queries[i][1] -= 1;
		queries[i][2] = i;
	}
	sort(queries.begin(), queries.end(), comp);
	
	/*
	for (int i = 0; i < q; i ++) {
		cout << queries[i][0] << ", " << queries[i][1] << ", " << queries[i][2] << "\n";
	}
	* */
	
	int l=0, r=-1, uniquecount=0, mirrorcount=0, zerocount=0;
	vector <int> positives(1000001, 0), negatives(1000001, 0);
	for (int i = 0; i < q; i ++) {
		// expand left boundary
		if (l > queries[i][0]) {
			for (int j = l-1; j >= queries[i][0]; j --) {
				if (arr[j] > 0) {
					positives[arr[j]] += 1;
					if (positives[arr[j]] == 1) {
						uniquecount += 1;
						if (negatives[arr[j]]) {
							mirrorcount += 1;
						}
					}
				}
				else if (arr[j] == 0) {
					zerocount += 1;
				}
				else {
					negatives[-arr[j]] += 1;
					if (negatives[-arr[j]] == 1) {
						uniquecount += 1;
						if (positives[-arr[j]]) {
							mirrorcount += 1;
						}
					}
				}
			}
		}
		// expand right boundary
		if (r < queries[i][1]) {
			for (int j = r+1; j <= queries[i][1]; j ++) {
				if (arr[j] > 0) {
					positives[arr[j]] += 1;
					if (positives[arr[j]] == 1) {
						uniquecount += 1;
						if (negatives[arr[j]]) {
							mirrorcount += 1;
						}
					}
				}
				else if (arr[j] == 0) {
					zerocount += 1;
				}
				else {
					negatives[-arr[j]] += 1;
					if (negatives[-arr[j]] == 1) {
						uniquecount += 1;
						if (positives[-arr[j]]) {
							mirrorcount += 1;
						}
					}
				}
			}
		}
		// reduce left boundary
		if (l < queries[i][0]) {
			for (int j = l; j < queries[i][0]; j ++) {
				if (arr[j] > 0) {
					positives[arr[j]] -= 1;
					if (positives[arr[j]] == 0) {
						uniquecount -= 1;
						if (negatives[arr[j]]) {
							mirrorcount -= 1;
						}
					}
				}
				else if (arr[j] == 0) {
					zerocount -= 1;
				}
				else {
					negatives[-arr[j]] -= 1;
					if (negatives[-arr[j]] == 0) {
						uniquecount -= 1;
						if (positives[-arr[j]]) {
							mirrorcount -= 1;
						}
					}
				}
			}
		}
		// reduce right boundary
		if (r > queries[i][1]) {
			for (int j = r; j > queries[i][1]; j --) {
				if (arr[j] > 0) {
					positives[arr[j]] -= 1;
					if (positives[arr[j]] == 0) {
						uniquecount -= 1;
						if (negatives[arr[j]]) {
							mirrorcount -= 1;
						}
					}
				}
				else if (arr[j] == 0) {
					zerocount -= 1;
				}
				else {
					negatives[-arr[j]] -= 1;
					if (negatives[-arr[j]] == 0) {
						uniquecount -= 1;
						if (positives[-arr[j]]) {
							mirrorcount -= 1;
						}
					}
				}
			}
		}
		l = queries[i][0];
		r = queries[i][1];
		
		/*
		cout << l << ", " << r << ", " << uniquecount << ", " << mirrorcount << ", " << zerocount << "\n";
		
		for (int j = 0; j < 10; j ++) {
			cout << positives[j] << " ";
		}
		cout << "\n";
		for (int j = 0; j < 10; j ++) {
			cout << negatives[j] << " ";
		}
		cout << "\n";
		*/
		
		if (uniquecount == 1 || zerocount > 0 || mirrorcount > 0) {
			ans[queries[i][2]] = 1;
		}
		else {
			ans[queries[i][2]] = 0;
		}
	}
	
	
	for (int i = 0; i < q; i ++) {
		if (ans[i] == 1) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}
	
	return 0;
}

