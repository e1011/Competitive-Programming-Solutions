#include <iostream>
#include <vector>

using namespace std;

vector <vector <int>> rotate90(vector <vector <int>> original) {
	vector <vector <int>> result(original.size(), vector <int> (original.size(), 0));
	
	for (int i = 0; i < original.size(); i ++) {
		for (int j = 0; j < original.size(); j ++) {
			result[i][j] = original[original.size()-j-1][i];
		}
	}
	
	return result;
}

int main() {
	int n;
	cin >> n;
	
	vector <vector <int>> arr(n, vector <int> (n, 0));
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < n; j ++) {
			cin >> arr[i][j];
		}
	}
	
	if (arr[1][0] < arr[0][0] && arr[0][1] > arr[0][0]) {
		arr = rotate90(arr);
	}
	if (arr[1][0] > arr[0][0] && arr[0][1] < arr[0][0]) {
		arr = rotate90(rotate90(rotate90(arr)));
	}
	if (arr[1][0] < arr[0][0] && arr[0][1] < arr[0][0]) {
		arr = rotate90(rotate90(arr));
	}
	
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < n; j ++) {
			cout << arr[i][j];
			if (j == n-1) {
				cout << "\n";
			} 
			else {
				cout << " ";
			}
		}
	}
	
	return 0;
}

