#include <iostream>
#include <complex>

using namespace std;

long double cross(complex <long double> a, complex <long double> b) {
	return (conj(a)*b).imag();
}

long double dot(complex <long double> a, complex <long double> b) {
	return (conj(a)*b).real();
}

complex <long double> intersection(complex <long double> a, complex <long double> b, complex <long double> p, complex <long double> q) {
	long double c1 = cross(p - a, b - a), c2 = cross(q - a, b - a);
	return (c1 * q - c2 * p) / (c1 - c2); // undefined if parallel
}

int main() {
	long double a, b;
	complex <long double> p1, p2, p3, p4;
	
	cin >> a >> b;
	p1 = {a, b};
	cin >> a >> b;
	p2 = {a, b};
	cin >> a >> b;
	p3 = {a, b};
	cin >> a >> b;
	p4 = {a, b};
	
	if (cross(a, b) == cross(c, d)) {
	
	}
	
	cout << intersection(p1, p2, p3, p4) << "\n";
	
	
	return 0;
}

