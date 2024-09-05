#include <iostream>
#include <vector>

using namespace std;

vector <vector <long long>> tensorproduct(vector <vector <long long>> a, vector <vector <long long>> b) {
	vector <vector <long long>> result(a.size()*b.size(), vector <long long> (a[0].size()*b[0].size(), 0));
	for (int i = 0; i < a.size()*b.size(); i ++) {
		for (int j = 0; j < a[0].size()*b[0].size(); j ++) {
			result[i][j] = a[i/b.size()][j/b[0].size()]*b[i % b.size()][j % b[0].size()];
		}
	}
	return result;
}

int main(){
	int n;
	cin >> n;
	
	vector <vector <long long>> ans = {{1}};
	for (int i = 0; i < n; i ++) {
		int x, y;
		cin >> x >> y;
		vector <vector <long long>> multiplier(x, vector <long long> (y, 0));
		for (int j = 0; j < x; j ++) {
			for (int k = 0; k < y; k ++) {
				cin >> multiplier[j][k];
			}
		}
		ans = tensorproduct(ans, multiplier);
	}
	
	long long maximum=0, minimum=1000000000000000000, maxcsum=0, mincsum=1000000000000000000, maxrowsum=0, minrowsum=1000000000000000000;
	vector <long long> columns(ans[0].size(), 0);
	for (int i = 0; i < ans.size(); i ++) {
		long long rowsum = 0;
		for (int j = 0; j < ans[0].size(); j ++) {
			maximum = max(maximum, ans[i][j]);
			minimum = min(minimum, ans[i][j]);
			rowsum += ans[i][j];
			columns[j] += ans[i][j];
		}
		maxrowsum = max(rowsum, maxrowsum);
		minrowsum = min(rowsum, minrowsum);
	}
	for (int i = 0; i < ans[0].size(); i ++) {
		maxcsum = max(columns[i], maxcsum);
		mincsum = min(columns[i], mincsum);
	}
	
	cout << "\n" << maximum << "\n" << minimum << "\n" << maxrowsum << "\n" << minrowsum << "\n" << maxcsum << "\n" << mincsum << "\n"; 
	
	return 0;
}

