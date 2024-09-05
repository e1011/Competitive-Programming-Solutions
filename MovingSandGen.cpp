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


int main(int argc, char **argv) {
	mt19937 mt_rand(atoi(argv[1]));
	int n = mt_rand() % 1000000 + 1, q = mt_rand() % 1000000 + 1;

	cout << n << " " << q << "\n";

	vector<int> ps(n, 0), arr(n, 0); 
	for (int i = 0; i < n; i++) {
		int s_i = mt_rand() % 1000 + 1;
		arr[i] = s_i;
		ps[i] = s_i;
		cout << s_i;
		
		if (i == n-1) {
			cout << "\n";
		}
		else {
			cout << " ";
		}
	}
	
	for (int i = 1; i < n; i ++) {
		ps[i] += ps[i-1];
	}
	

	for (int i = 0; i < q; i++) {
		int a = mt_rand() % 3 + 1;
		int b, c; 
		if (atoi(argv[2]) == 1) {
			a = 3;
		}
		if (a == 1) {
			b = mt_rand() % (n-2) + 2;
			c = mt_rand() % (ps[b - 1] - ps[b - 2]+1);
			ps[b - 2] += c;
		} else if (a == 2) {
			b = mt_rand() % (n-2) + 1;
			c = mt_rand() % (ps[b - 1] - ps[b - 2]+1);
			ps[b-1] -= c;
		} else {
			b = mt_rand() % n + 1;
			c = mt_rand() % n + 1;

			int temp = b; 
			b = min(b, c);
			c = max(temp, c);

			cerr << (ps[c-1] - ps[b - 2]) << "\n";
		}

		cout << a << " " << b << " " << c << "\n";
	}

    return 0;
}

