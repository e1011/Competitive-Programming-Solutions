#include <iostream>
#include <vector>

using namespace std;

int main() {
	int ans=1;
	string s;
	vector <string> arr(9, "");
	cin >> s;
	cin >> arr[0];
	cin >> arr[1];
	cin >> arr[2];
	cin >> s;
	cin >> arr[3];
	cin >> arr[4];
	cin >> arr[5];
	cin >> s;
	cin >> arr[6];
	cin >> arr[7];
	cin >> arr[8];
	cin >> s;
	
	vector <vector <int>> grid(9, vector <int> (9, 0));
	for (int i = 0; i < 9; i ++) {
		grid[i][0] = arr[i][1]-48;
		grid[i][1] = arr[i][2]-48;
		grid[i][2] = arr[i][3]-48;
		grid[i][3] = arr[i][5]-48;
		grid[i][4] = arr[i][6]-48;
		grid[i][5] = arr[i][7]-48;
		grid[i][6] = arr[i][9]-48;
		grid[i][7] = arr[i][10]-48;
		grid[i][8] = arr[i][11]-48;
	}
	for (int i = 0; i < 9; i ++) {
		for (int j = 0; j < 9; j ++) {
			if (grid[i][j] == -2) {
				grid[i][j] = 0;
			}
		}
	}
	/*
	for (int i = 0; i < 9; i ++) {
		for (int j = 0; j < 9; j ++) {
			cout << grid[i][j] << " ";
		}
		cout << "\n";
	}
	* */
	
	vector <int> oneto9;
	
	for (int i = 0; i < 9; i ++) {
		oneto9 = vector <int> (10, 0);
		for (int j = 0; j < 9; j ++) {
			if (oneto9[grid[i][j]] == 1) {
				ans = 0;
			}
			else if (grid[i][j] != 0) {
				oneto9[grid[i][j]] = 1;
			}
		}
		
		oneto9 = vector <int> (10, 0);
		for (int j = 0; j < 9; j ++) {
			if (oneto9[grid[j][i]] == 1) {
				ans = 0;
			}
			else if (grid[j][i] != 0) {
				oneto9[grid[j][i]] = 1;
			}
		}
	}
	
	for (int i = 0; i < 9; i ++) {
		oneto9 = vector <int> (10, 0);
		oneto9[grid[0+3*(i%3)][0+3*(i/3)]] += 1;
		oneto9[grid[1+3*(i%3)][0+3*(i/3)]] += 1;
		oneto9[grid[2+3*(i%3)][0+3*(i/3)]] += 1;
		oneto9[grid[0+3*(i%3)][1+3*(i/3)]] += 1;
		oneto9[grid[1+3*(i%3)][1+3*(i/3)]] += 1;
		oneto9[grid[2+3*(i%3)][1+3*(i/3)]] += 1;
		oneto9[grid[0+3*(i%3)][2+3*(i/3)]] += 1;
		oneto9[grid[1+3*(i%3)][2+3*(i/3)]] += 1;
		oneto9[grid[2+3*(i%3)][2+3*(i/3)]] += 1;
		for (int j = 1; j <= 9; j ++) {
			if (oneto9[j] > 1) {
				ans = 0;
			}
		}
	}
	
	if (ans) {
		cout << "OK\n";
	}
	else {
		cout << "GRESKA\n";
	}
	
	return 0;
}

