#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
	int t;
	cin >> t;
	
	for (int _ = 0; _ < t; _ ++) {
		long long n, m, d, ans=0, sum=0;
		cin >> n >> m >> d;
		
		vector <long long> arr(n, 0);
		priority_queue <long long, vector <long long>, greater <long long>> pq;
		
		for (int i = 0; i < n; i ++) {
			cin >> arr[i];
		}
		
		for (int i = 0; i < n; i ++) {
			if (arr[i] > 0) {
				if (pq.size() < m) {
					pq.push(arr[i]);
					sum += arr[i];
					ans = max(ans, sum-(d*(i+1)));
				}
				else if (pq.top() < arr[i]) {
					sum -= pq.top();
					sum += arr[i];
					pq.pop();
					pq.push(arr[i]);
					ans = max(ans, sum-(d*(i+1)));
				}
			}
		}
		
		cout << ans << "\n";
	}
	
	
	return 0;
}

