#include <iostream>
#include <vector>

using namespace std;

long long exp(long long x, long long y, long long p) {
	long long res = 1; x %= p;
	while (y) {
		if (y & 1) {
			res *= x; res %= p; 
		}
		x *= x; x %= p;
		y >>= 1;
	}
	return res;
}

int main() {
	vector <int> arr(0);
	
	// checks how many points are encompassed by the "infinite" line starting at (x, 0)
	for (int i = 0; i < 1000; i += 2) {
		int x=i, y=0, firstinstance=0;
		for (int j = 0; j < 10000; j ++) {
			x += 1;
			y += 1;
			bool works = 1;
			for (int k = 0; exp(3, k, 1000000) <= x; k ++) {
				if ((x/exp(3, k, 1000000000))%2 != (y/exp(3, k, 1000000000))%2) {
					works = 0;
				}
			}
			if (works) {
				arr.push_back(y);
				break;
			}
		}
		arr.push_back(sum);
	}
	
	int x = 0;
	for (int i = 1; i < arr.size(); i ++) {
		if (arr[i] > arr[i-1]) {
			x += 1;
		}
		else {
			x -= 1;
		}
		cout << x << "\n";
	}
	
	return 0;
}


// count, starting from origin, how often they appear
// (0, 0), every val
// x=1, divide
// x=2, divide
// x=3, multiply
// x=4, divide
// x=5, divide
// x=6, multiply
// x=7, divide
// x=8, multiply
// x=9, multiply
// x=10, divide
// x=11, divide
// x=12, multiply
// x=13, divide
// 0010010110010
