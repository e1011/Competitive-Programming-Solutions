#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	float a, b, c, d;
	cin >> a >> b >> c >> d;
	
	
	cout << fixed;
	cout << (a+b)/2 << "\n";
	cout << (a+c)/2 << "\n";
	cout << (a+d)/2.0 << "\n";
	cout << (b+c)/2.0 << "\n";
	cout << (b+d)/2 << "\n";
	cout << (c+d)/2 << "\n";
	cout << (a+b+c)/3 << "\n";
	cout << (a+b+d)/3 << "\n";
	cout << (a+c+d)/3 << "\n";
	cout << (b+c+d)/3 << "\n";
	cout << (a+b+c+d)/4 << "\n";
	
	return 0;
}

