#include <iostream>
#include <vector>

using namespace std;

// prints nth fibonacci number (starting from 1)

vector <vector <long long>> matrix{{1, 1}, {1, 0}};

vector <vector <long long>> multiply(vector <vector <long long>> a, vector <vector <long long>> b) {
	// a*n, n*b -> a*b
	vector <vector <long long>> ans(a.size(), vector <long long> (b[0].size(), 0));
	for (int i = 0; i < a.size(); i ++) {
		for (int j = 0; j < b[0].size(); j ++) {
			for (int k = 0; k < a[0].size(); k ++) {
				ans[i][j] += a[i][k]*b[k][j];
				ans[i][j] %= 1000000007;
			}
		}
	}
	return ans;
}

vector <vector <long long>> binexp(long long exp) {
	vector <vector <long long>> ans{{1, 0}};
	for (; exp > 0; exp /= 2, matrix = multiply(matrix, matrix)) {
		if (exp & 1) {
			ans = multiply(ans, matrix);
		}
	}
	return ans;
}

int main() {
	long long n;
	cin >> n;
	
	if (n == 0) {
		cout << "0\n";
	}
	else {
		cout << binexp(n-1)[0][0] << "\n";
	}
	
	return 0;
}

