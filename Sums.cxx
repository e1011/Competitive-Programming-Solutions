#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, k;
	cin >> n;
	
	vector <int> arr(n, 0);
	for (int i = 0; i < n; i ++) {
		cin >> arr[i];
	}
	
	vector <int> dp(arr[0], -1);
	dp[0] = 0;
	set <int> pq;
	pq.insert(0);
	while (pq.empty() == false) {
		int dist = *pq.begin();
		pq.erase(dist);
		for (int i = 1; i < n; i++) {
			if (dp[(dist+arr[i])%arr[0]] == -1 || dist+arr[i] < dp[(dist+arr[i])%arr[0]]) {
				if (dp[(dist+arr[i])%arr[0]] != -1) {
					pq.erase(dp[(dist+arr[i])%arr[0]]);
				}
				pq.insert(dist+arr[i]);
				dp[(dist+arr[i])%arr[0]] = dist+arr[i];
			}
		}
	}
	
	cin >> k;
	for (int i = 0; i < k; i ++) {
		int x;
		cin >> x;
		if (dp[x%arr[0]] == -1 || dp[x%arr[0]] > x) {
			cout << "NIE\n";
		}
		else {
			cout << "TAK\n";
		}
	}
}





