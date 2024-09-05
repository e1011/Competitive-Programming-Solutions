#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	long long n, ans=0;
	cin >> n;
	
	set <int> days;
	days.insert(0);
	vector <vector <int>> tasks(n, vector <int> (2, 0));
	for (int i = 0; i < n; i ++) {
		days.insert(i+1);
		cin >> tasks[i][1] >> tasks[i][0];
	}
	
	sort(tasks.begin(), tasks.end());
	reverse(tasks.begin(), tasks.end());
	for (int i = 0; i < n; i ++) {
		if (*--days.upper_bound(tasks[i][1]) != 0) {
			ans += tasks[i][0];
			days.erase(--days.upper_bound(tasks[i][1]));
		}
	}
	
	cout << ans << "\n";
	
	return 0;
}

// for o(n^2), dp[i][j] is knapsack with i as current day, j is deadline
// sort from greatest to least. it is always optimal to choose the biggest ones, if possible
// this is because can replace one with smaller value with one of higher value at no opportunity cost, if both can go in same place
// maintain set of days. for each task, find biggest day smaller than deadline and remove if exists

