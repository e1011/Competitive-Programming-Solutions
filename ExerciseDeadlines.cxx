#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, ans=0, impossible=0;
	cin >> n;
	
	vector <int> deadlines(n, 0);
	for (int i = 0; i < n; i ++) {
		cin >> deadlines[i];
	}
	
	for (int t = 0; t < n; t ++) {
		vector <vector <int>> todo(0);
		vector <int> marked(n, 0);
		vector <int> newdeadlines(n, 0);
		
		for (int i = 0; i < n; i ++) {
			if (i >= deadlines[i]) {
				todo.push_back({deadlines[i], i});
				marked[i] = 1;
			}
			if (i == deadlines[i]-1) {
				newdeadlines[i] = deadlines[i];
				marked[i] = 1;
			}
		}
		
		cout << "\n\n";
		for (int i = 0; i < n; i ++) {
			cout << deadlines[i] << "\n";
		}
		cout << "\n\n";
		for (int i = 0; i < (int)todo.size(); i ++) {
			cout << todo[i][0] << ", " << todo[i][1] << "\n";
		}
		cout << "\n";
		
		int iter = n-1;
		for (int i = (int)todo.size()-1; i >= 0; i --) {
			if (iter >= todo[i][1]) {
				iter = todo[i][1]-1;
			}
			while (newdeadlines[iter] != 0) {
				iter -= 1;
			}
			
			if (iter < 0) {
				impossible = 1;
			}
			else {
				ans += todo[i][1]-iter;
				iter -= 1;
			}
		}
		
		iter = 0;
		for (int i = 0; i < n; i ++) {
			if (marked[i] == 0) {
				while (newdeadlines[iter] != 0) {
					iter += 1;
				}
				newdeadlines[iter] = deadlines[i];
			}
		}
		
		deadlines = newdeadlines;
		if (impossible) {
			break;
		}
	}
	
	if (impossible == 0) {
		cout << ans << "\n";
	}
	else {
		cout << "-1\n";
	}
	
	return 0;
}

// 4 3 2 1
// Y Y N N
// 3 4 2 1
// 2 3 4 1
// 1 2 3 4
// do it in batches, find all the ones that dont work, reverse it, then assign indices and make new vector
// can happen n times max, cuz each iteration the one with smallest deadline will find place
// if there are leftover that cannot be put in place, it is impossible








