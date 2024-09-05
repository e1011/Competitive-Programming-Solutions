#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	long long n, m, ans=0;
	cin >> n >> m;
	
	vector <long long> visited(n, 0), arr(n, 0);
	for (int i = 0; i < n; i ++) {
		cin >> arr[i];
	}
	
	priority_queue <vector <long long>> pq;
	pq.push({0, 0});
	
	while (pq.empty() == false) {
		long long dist = pq.top()[0], node = pq.top()[1];
		pq.pop();
		
		if (!visited[node]) {
			ans += dist;
			visited[node] = 1;
			
			for (int i = 0; i < n; i ++) {
				if (!visited[i]) {
					long long maxval = max((arr[node]+arr[i]) % m, (arr[node]*arr[i]) % m);

					if (arr[i] > arr[node]) {
						maxval = max(maxval, (arr[i]-arr[node]) % m);
						if (arr[i] % arr[node] == 0) {
							maxval = max(maxval, (arr[i]/arr[node]) % m);
						}
					}
					else {
						maxval = max(maxval, (arr[node]-arr[i]) % m);
						if (arr[node] % arr[i] == 0) {
							maxval = max(maxval, (arr[node]/arr[i]) % m);
						}
					}
					
					pq.push({maxval, i});
				}
			}
		}
	}
	
	cout << ans << "\n";
	
	return 0;
}

