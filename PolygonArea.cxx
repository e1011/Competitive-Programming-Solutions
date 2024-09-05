#include <iostream>
#include <vector>
#include <complex>
#include <iomanip>

using namespace std;

int main() {
	while (true) {
		int n, smallest=1000000000, index;
		long double area=0, type=-1;
		cin >> n;
		if (n == 0) {
			break;
		}
		
		vector <complex <long double>> points(n, {0, 0});
		for (int i = 0; i < n; i ++) {
			long double x, y;
			cin >> x >> y;
			points[i] = {x, y};
			if (y < smallest) {
				smallest = y;
				index = i;
			}
		}
		
		if ((conj(points[(index-1+n)%n]-points[index])*(points[(index+1)%n]-points[index])).imag() > 0) {
			cout << "CW ";
			type = 1;
		}
		else {
			cout << "CCW ";
		}
		
		points.push_back(points[0]);
		for (int i = 0; i < n; i ++) {
			area += type*(points[i+1].real()-points[i].real())*(points[i].imag()+points[i+1].imag())/2;
		}
		cout << fixed << setprecision(1) << area << "\n";
	}
	
	
	return 0;
}

