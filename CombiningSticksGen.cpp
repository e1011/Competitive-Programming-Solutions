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
#include <stdio.h>
#include <assert.h>

using namespace std;

vector<long long> sticks; 

long long solution(int n) {
    long long ans {0}; 

    vector <long long> arr {sticks};
	sort(arr.begin(), arr.end());
	
	reverse(arr.begin(), arr.end());
	for (int i = 1; i < n; i ++) {
		ans += arr[i];
	}

    return ans; 
}

int main(int argc, char **argv) {
	mt19937 mt_rand(atoi(argv[1]));
	
	int n = (mt_rand() % 1000000) + 1;
	cout << n << "\n";

	for(int i = 0; i < n; i++) {
		int len = mt_rand() % 1000000 + 1;
		cout << len;
		sticks.push_back(len);
		if (i == n-1) {
			cout << "\n";
		}
		else {
			cout << " ";
		}
	}

	
	cerr<< solution(n);
}
