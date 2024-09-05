#include <iostream>
#include <vector>

using namespace std;

vector <long long> exp(long long x, long long y, long long p) {
	long long res = 1, k=0;
	if (x >= p) {x %= p; k = 1;}
	while (y) {
		if (y & 1) {
			res *= x;
			if (res >= p) {res %= p; k = 1;}
		}
		x *= x; 
		if (x >= p) {x %= p; k = 1;}
		y >>= 1;
	}
	return {res, k};
}

long long phi(long long n) {
    long long result = n;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0) {
                n /= i;
			}
            result -= result / i;
        }
    }
    if (n > 1) {
        result -= result / n;
    }
    return result;
}

vector <long long> twr(0);
long long solve(long long index, long long mod) {
	vector <long long> x(2, 0);
	if (mod == 1 || index == (long long)twr.size()-1) {
		x[0] = twr[index];
	}
	else {
		x = exp(twr[index], solve(index+1, phi(mod)), mod);
	}
	if (x[0] > mod || x[1]) {
		x[0] %= mod; x[0] += mod;
	}
	return x[0];
}


int main() {
	long long n, m;
	cin >> n >> m;
	
	twr = vector <long long> (n, 0);
	for (int i = 0; i < n; i ++) {
		cin >> twr[i];
	}
	
	cout << solve(0, m) % m << "\n";
	
	return 0;
}

