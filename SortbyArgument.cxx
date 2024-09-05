#include <iostream>
#include <vector>
#include <complex>
#include <cmath>
#include <algorithm>

using namespace std;

typedef complex<long double> P;
#define X real()
#define Y imag()

int main() {
	int n;
	cin >> n;
	
	vector <vector <long double>> points(n, vector <long double> (3, 0));
	for (int i = 0; i < n; i ++) {
		cin >> points[i][1] >> points[i][2];
		points[i][0] = (long double)atan(arg((P){points[i][1], points[i][2]}));
	}
	
	sort(points.begin(), points.end());
	for (int i = 0; i < n; i ++) {
		cout << (int)points[i][1] << " " << (int)points[i][2] << "\n";
	}
	
	return 0;
}

