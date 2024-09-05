#include <iostream>
#include <vector>
#include <random>

using namespace std;

int main() {
	
	vector <vector <int>> arr1(vector <vector <int>> (3, vector <int> (3, 0)));
	for (int i = 0; i < 3; i ++) {
		for (int j = 0; j < 3; j ++) {
			string s;
			cin >> s;
			if (s == "X") {
				arr1[i][j] = -1;
			}
			else {
				arr1[i][j] = stoi(s);
			}
		}
	}
	/*
	cout << "\n";
	for (int i = 0; i < 3; i ++) {
		for (int j = 0; j < 3; j ++) {
			cout << arr1[i][j] << " ";
		}
		cout << "\n";
	}
	* */

	bool works = 0;
	while (works == false) {
		vector <vector <int>> arr = arr1;
		bool filled = 0;
		while (filled == false) {
			for (int t = 0; t < 2; t ++) {
				for (int i = 0; i < 3; i ++) {
					if (arr[i][0] == -1 && arr[i][1] != -1 && arr[i][2] != -1) {
						arr[i][0] = 2*arr[i][1]-arr[i][2];
					}
					if (arr[i][0] != -1 && arr[i][1] == -1 && arr[i][2] != -1) {
						arr[i][1] = (arr[i][0]+arr[i][2])/2;
					}
					if (arr[i][0] != -1 && arr[i][1] != -1 && arr[i][2] == -1) {
						arr[i][2] = 2*arr[i][1]-arr[i][0];
					}
					if (arr[0][i] == -1 && arr[1][i] != -1 && arr[2][i] != -1) {
						arr[0][i] = 2*arr[1][i]-arr[2][i];
					}
					if (arr[0][i] != -1 && arr[1][i] == -1 && arr[2][i] != -1) {
						arr[1][i] = (arr[0][i]+arr[2][i])/2;
					}
					if (arr[0][i] != -1 && arr[1][i] != -1 && arr[2][i] == -1) {
						arr[2][i] = 2*arr[1][i]-arr[0][i];
					}
				}
			}
			
			filled = 1;
			for (int i = 0; i < 3; i ++) {
				for (int j = 0; j < 3; j ++) {
					if (arr[i][j] == -1) {
						arr[i][j] = (rand()%1000)-500;
						filled = 0;
						break;
					}
				}
			}
		}
		
		works = true;
		for (int i = 0; i < 3; i ++) {
			if (arr[i][1]-arr[i][0] != arr[i][2]-arr[i][1]) {
				works = false;
			}
			if (arr[1][i]-arr[0][i] != arr[2][i]-arr[1][i]) {
				works = false;
			}
		}
		if (works) {
			arr1 = arr;
		}
	}
	
	for (int i = 0; i < 3; i ++) {
		for (int j = 0; j < 3; j ++) {
			cout << arr1[i][j];
			if (j == 2) {
				cout << "\n";
			}
			else {
				cout << " ";
			}
		}
	}
	
	return 0;
}

