#include <iostream>
#include <vector>

using namespace std;

long long n;
// initialize this to 2*n length
vector <long long> segtree(0);

long long comb(long long a, long long b) {
	return a+b;
}

void modify(long long index, long long val) {
	segtree[index+n] += val;
	for (int i = (index+n)/2; i > 0; i /= 2) {
		segtree[i] = comb(segtree[2*i], segtree[2*i+1]);
	}
}

long long query(long long l, long long r) {
	long long lsum = 0, rsum = 0;
	for (l += n, r += n; l < r; l /= 2, r /= 2) {
		if (l % 2 == 1) {
			lsum = comb(lsum, segtree[l++]); 
		}
		if (r % 2 == 1) {
			rsum = comb(rsum, segtree[--r]);
		}
	}
	return comb(lsum, rsum);
}

int main() {
	long long p, ans;
	cin >> p >> n;
	
	ans = p*(p-1)*(p-2);
	
	n *= 2;
	segtree = vector <long long> (2*n, 0);
	
	for (int i = 0; i < p; i ++) {
		long long x;
		cin >> x;
		modify(x, 1);
		modify(x+(n/2), 1);
	}
	
	for (int i = 0; i < n/2; i ++) {
		long long a = query(i, i+1), b = query(i+1, i+(n/4)+1);
		//cout << i << ", " << a << ", " << b << "\n";
		ans -= 3*a*b*(b-1);
		ans -= 3*a*(a-1)*b;
		ans -= a*(a-1)*(a-2);
		
		if ((n/2) % 2 == 0 && i*4 < n) {
			long long c = query(i+(n/4), i+(n/4)+1);
			ans += 3*a*(a-1)*c;
			ans += 3*a*c*(c-1);
		}
		//cout << 3*a*b*(b-1) << ", " << 3*a*(a-1)*b << ", " << a*(a-1)*(a-2) << "\n";
	}
	
	cout << ans/6 << "\n";
	
	return 0;
}

