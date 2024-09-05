#include <iostream>
#include <vector>
#include <complex>

using namespace std;

int main() {
	while (true) {
		int n, m;
		cin >> n;
		if (n == 0) {
			break;
		}
		
		vector <vector <int>> points (n, vector <int> (2, 0));
		for (int i = 0; i < n; i ++) {
			cin >> points[i][0] >> points[i][1];
		}
		points.push_back({points[0][0], points[0][1]});
		
		cin >> m;
		for (int i = 0; i < m; i ++) {
			int px, py, counter = 0, on = 0;
			cin >> px >> py;
			complex <long long> P{px, py};

			
			for (int j = 0; j < n; j ++) {
				complex <long long> P2 {points[j][0], points[j][1]};
				complex <long long> P3 {points[j+1][0], points[j+1][1]};
				
				if (P2.real() > P3.real()) {
					swap(P2, P3);
				}
				if (P2.real() == P3.real() && P2.imag() > P3.imag()) {
					swap(P2, P3);
				}
				
				if (P2.real() == P.real() && P3.real() == P.real()) {
					if (P2.imag() <= P.imag() && P3.imag() >= P.imag()) {
						on = 1;
					}
				}
				else if (P2.real() <= P.real() && P3.real() > P.real()) {
					if ((conj(P3-P2)*(P-P2)).imag() == 0) {
						on = 1;
					}
					else if ((conj(P3-P2)*(P-P2)).imag() < 0) {
						counter += 1;
					}
				}
				
			}
			
			if (on) {
				cout << "on\n";
			}
			else if (counter % 2 == 0) {
				cout << "out\n";
			}
			else {
				cout << "in\n";
			}
			
		}
	}
	
	
	return 0;
}

