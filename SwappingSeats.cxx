#include <iostream>
#include <vector>

using namespace std;

// a[b, c] b[a, c] c[a, b]
int swaps(vector <int> mismatches) {
	int results=0, ab=0, ac=0, bc=0;
	
	ab = min(mismatches[0], mismatches[2]);
	ac = min(mismatches[1], mismatches[4]);
	bc = min(mismatches[3], mismatches[5]);
	
	results = ab+ac+bc;
	mismatches[0] -= ab;
	mismatches[2] -= ab;
	mismatches[1] -= ac;
	mismatches[4] -= ac;
	mismatches[3] -= bc;
	mismatches[5] -= bc;
	
	results += 2*max(mismatches[0], mismatches[1]);
	
	return results;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int acount=0, bcount=0, ccount=0, ans=1000000000;
	string s;
	cin >> s;
	int n = s.size();
	vector <int> psum1(2*n, 0);
	vector <int> psum2(2*n, 0);
	vector <int> psum3(2*n, 0);
	
	for (int i = 0; i < n; i ++) {
		if (s[i] == 'A') {
			psum1[i] += 1;
			psum1[i+n] += 1;
			acount += 1;
		}
		else if (s[i] == 'B') {
			psum2[i] += 1;
			psum2[i+n] += 1;
			bcount += 1;
		}
		else {
			psum3[i] += 1;
			psum3[i+n] += 1;
			ccount += 1;
		}
	}
	
	for (int i = 1; i < 2*n; i ++) {
		psum1[i] += psum1[i-1];
		psum2[i] += psum2[i-1];
		psum3[i] += psum3[i-1];
	}
	
	for (int i = 1; i <= n; i ++) {
		ans = min(ans, swaps({psum2[i+acount-1]-psum2[i-1], psum3[i+acount-1]-psum3[i-1], 
			psum1[i+acount+bcount-1]-psum1[i+acount-1], psum3[i+acount+bcount-1]-psum3[i+acount-1], 
			psum1[i+acount+bcount+ccount-1]-psum1[i+acount+bcount-1], psum2[i+acount+bcount+ccount-1]-psum2[i+acount+bcount-1]}));
		ans = min(ans, swaps({psum2[i+acount-1]-psum2[i-1], psum3[i+acount-1]-psum3[i-1], 
			psum1[i+acount+bcount+ccount-1]-psum1[i+acount+ccount-1], psum3[i+acount+bcount+ccount-1]-psum3[i+acount+ccount-1], 
			psum1[i+acount+ccount-1]-psum1[i+acount-1], psum2[i+acount+ccount-1]-psum2[i+acount-1]}));
	}
	
	
	cout << ans << "\n";
	
	return 0;
}

