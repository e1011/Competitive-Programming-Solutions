#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, ans=0;
	cin >> n;
	
	vector <int> g(2001, 0);
	for (int i = 1; i < 2000; i ++) {
		vector <int> mex(2001, 0);
		for (int k = 1; k < i; k ++) {
			int x = 0;
			x ^= g[i%k];
			x ^= ((i/k) % 2)*g[k];
			mex[x] = 1;
		}
		
		for (int j = 0; j < 2000; j ++) {
			if (mex[j] != 1) {
				g[i] = j;
				break;
			}
		}
		cout << g[i] << "\n";
	}
	
	
	for (int i = 0; i < n; i ++) {
		int p;
		cin >> p;
		ans ^= g[p];
	}
	
	if (ans == 0) {
		cout << "Second\n";
	}
	else {
		cout << "First\n";
	}
	
	return 0;
}

