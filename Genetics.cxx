#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	
	vector <string> clones(n, "");
	vector <vector <long long>> hash(m, vector <long long> (4, 0));
	vector <int> rvalues(n, 0);
	long long rsum = 0;
	
	for (int i = 0; i < n; i ++) {
		cin >> clones[i];
		rvalues[i] = rand();
		rsum += rvalues[i];
	}
	
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < m; j ++) {
			if (clones[i][j] == 'A') {
				hash[j][0] += rvalues[i];
			}
			if (clones[i][j] == 'C') {
				hash[j][1] += rvalues[i];
			}
			if (clones[i][j] == 'G') {
				hash[j][2] += rvalues[i];
			}
			if (clones[i][j] == 'T') {
				hash[j][3] += rvalues[i];
			}
		}
	}
	
	for (int i = 0; i < n; i ++) {
		long long hashsum = 0;
		for (int j = 0; j < m; j ++) {
			if (clones[i][j] == 'A') {
				hashsum += hash[j][1]+hash[j][2]+hash[j][3];
			}
			if (clones[i][j] == 'C') {
				hashsum += hash[j][0]+hash[j][2]+hash[j][3];
			}
			if (clones[i][j] == 'G') {
				hashsum += hash[j][0]+hash[j][1]+hash[j][3];
			}
			if (clones[i][j] == 'T') {
				hashsum += hash[j][0]+hash[j][1]+hash[j][2];
			}
		}
		if (hashsum == (long long)(rsum-rvalues[i])*k) {
			cout << i+1 << "\n";
			break;
		}
	}
	
	return 0;
}

