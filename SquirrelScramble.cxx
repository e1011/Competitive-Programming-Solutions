#include <iostream>
#include <vector>

using namespace std;

vector <int> prefixsum;
int dist(int i, int j) {
	if (i > j) {
		swap(i, j);
	}
	return prefixsum[j]-prefixsum[i];
}

int main() {
	int n, m;
	cin >> n >> m;
	
	vector <int> portals(n, 0);
	for (int i = 0; i < m; i ++) {
		int x;
		cin >> x;
		portals[x] = 1;
	}
	
	vector <int> prefixsum(n, 0);
	for (int i = 0; i < n-1; i ++) {
		cin >> prefixsum[i+1];
		prefixsum[i+1] += prefixsum[i];
	}
	
	vector <int> dp(n, 0);
	
	int mostrecentportal = -1;
	if (portals[0] == 1) {
		mostrecentportal = 0;
	}
	
	for (int i = 1; i < n; i ++) {
		//if (portals[i]) {
			//if (mostrecentportal != -1) {
				//vector <int> sum1(n, 0);
				//for (int j = mostrecentportal; j <= i; j ++) {
					//sum1[j] = (min(dist(mostrecentportal, j), dist(j, i))+dist(mostrecentportal, mostrecentportal-1))*mostrecentportal + dp[mostrecentportal-1];
				//}
				//vector <int> sum2(n, 0);
				//int y = dist(mostrecentportal, i), x = 0, pointer = mostrecentportal;
				//for (int j = mostrecentportal; j <= i; j ++) {
					//sum2[j] = min(x, y);
					//while (x > y && pointer < j) {
						//y += dist(j, i)+dist(mostrecentportal, pointer+1);
						//x -= dist(pointer, i);
						//sum2[j] = min(sum2[j], min(x, y));
						//pointer += 1;
					//}
					//x += dist(j, j+1)*(j+1-pointer);
					//y -= dist(j, j+1)*(pointer+1-mostrecentportal);
				//}
				//for (int j = mostrecentportal; j <= i; j ++) {
					//dp[j] = sum1[j]+sum2[j];
				//}
			//}
			//mostrecentportal = i;
		//}
		else {
			dp[i] = dp[i-1]+dist(i-1, i)*i;
		}
	}
	
	int ans = 0;
	for (int i = 0; i < n; i ++) {
		ans += dp[i];
	}
	cout << ans << "\n";
	
	return 0;
}

