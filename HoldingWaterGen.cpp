#include <fstream>
#include <string>
#include <math.h>
#include <set>
#include <iostream>
#include <random>
#include <vector>
#include <queue>
#include <sstream>
#include <algorithm>

using namespace std;

vector<long long> bars; 

long long solution(int n) {
    long long l=-1, r=-1;
	
	vector <vector <long long>> arr(n, vector <long long> (2, 0));
	for (long long i = 0; i < n; i ++) {
		arr[i][0] = bars[i];
		arr[i][1] = i;
	}
	
	sort(arr.begin(), arr.end());
	reverse(arr.begin(), arr.end());
	
	long long ans=0;
	for (long long i = 0; i < n; i ++) {
		if (l == -1) {
			l = arr[i][1];
			r = arr[i][1];
		}
		else if (arr[i][1] < l) {
			ans += arr[i][0]*(l-arr[i][1]-1);
			l = arr[i][1];
		}
		else if (arr[i][1] > r) {
			ans += arr[i][0]*(arr[i][1]-r-1);
			r = arr[i][1];
		}
		else {
			ans -= arr[i][0];
		}
	}
	
	return ans;
}

int main(int argc, char **argv) {
	mt19937 mt_rand(atoi(argv[1]));

	int n = mt_rand() % 100000 + 1;
	cout << n << "\n";

	for(int i = 0; i < n; ++i) {
		long long len = mt_rand()%1000000000+1;
		bars.push_back(len);

		cout << len;
		if (i == n-1) {
			cout << "\n";
		}
		else {
			cout << " ";
		}
	}

	cerr << solution(n) << "\n";
}
