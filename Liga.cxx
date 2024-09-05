#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector <int> simplify(vector <int> arr) {
	if (min(arr[1], min(arr[2], arr[3])) != -1) {
		arr[0] = arr[1]+arr[2]+arr[3];
	}
	if (arr[0] != -1) {
		if (arr[1] != -1 && arr[2] != -1) {
			arr[3] = arr[0]-arr[1]-arr[2];
		}
		if (arr[1] != -1 && arr[3] != -1) {
			arr[2] = arr[0]-arr[1]-arr[3];
		}
		if (arr[2] != -1 && arr[3] != -1) {
			arr[1] = arr[0]-arr[2]-arr[3];
		}
	}
	
	return arr;
}

int main() {
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i ++) {
		vector <int> arr(5, -1);
		string a, b, c, d, e;
		cin >> a >> b >> c >> d >> e;
		
		if (a != "?") {
			arr[0] = stoi(a);
		}
		
		if (b != "?") {
			arr[1] = stoi(b);
		}
		
		if (c != "?") {
			arr[2] = stoi(c);
		}
		
		if (d != "?") {
			arr[3] = stoi(d);
		}
		
		if (e != "?") {
			arr[4] = stoi(e);
		}
		
		arr = simplify(arr);
		
		
		for (int j = 0; j <= 100; j ++) {
			for (int k = 0; j+k <= 100; k ++) {
				for (int l = 0; j+k+l <= 100; l ++) {
					if (arr[1] != -1 && arr[1] != j) {
						if (j == 0 && k == 1 && l == 0) {
							//cout << "1\n";
						}
						continue;
					}
					if (arr[2] != -1 && arr[2] != k) {
						if (j == 0 && k == 1 && l == 0) {
							//cout << "4\n";
						}
						continue;
					}
					if (arr[3] != -1 && arr[3] != l) {
						if (j == 0 && k == 1 && l == 0) {
							//cout << "3\n";
						}
						continue;
					}
					if (arr[0] != -1 && arr[0] != j+k+l) {			
						if (j == 0 && k == 1 && l == 0) {
							//cout << "2\n";
						}
						continue;
					}
					if (arr[4] != -1 && (3*j+k != arr[4])) {						
						if (j == 0 && k == 1 && l == 0) {
							//cout << "5\n";
						}
						continue;
					}
					arr[1] = j;
					arr[2] = k;
					arr[3] = l;
				}
			}
		}
		
		arr = simplify(arr);
		
		if (arr[0] != -1 && arr[1] != -1 && arr[2] != -1 && arr[3] != -1) {
			arr[4] = 3*arr[1] + arr[2];
		}
		if (arr[0] == -1) {
			//throw;
		}
		if (arr[1] == -1) {
			//throw;
		}
		if (arr[2] == -1) {
			//throw;
		}
		if (arr[3] == -1) {
			//throw;
		}
		if (arr[4] == -1) {
			//throw;
		}
		cout << arr[0] << " " << arr[1] << " " << arr[2] << " " << arr[3] << " " << arr[4] << "\n"; 
	}
	
	
	return 0;
}
