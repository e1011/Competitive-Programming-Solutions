#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, m, r, c;
	cin >> n >> m >> r >> c;
	
	if (r == n && c == m) {
		// all a's
		for (int i = 0; i < n; i ++) {
			for (int j = 0; j < m; j ++) {
				cout << 'a';
			}
			cout << "\n";
		}
	}
	else if (r == n && c != 0) {
		// populate edges, then middle if odd
		if (m % 2 == 0 && c % 2 == 1) {
			cout << "IMPOSSIBLE\n";
		}
		else if (m % 2 == 1 && c == m-1) {
			cout << "IMPOSSIBLE\n";
		}
		else if (c % 2 == 0) {
			for (int i = 0; i < n; i ++) {
				for (int j = 0; j < m; j ++) {
					if (j < c/2 || m-j-1 < c/2) {
						cout << 'a';
					}
					else {
						if (i % 3 == 0) {
							cout << "b";
						}
						else if (i % 3 == 1) {
							cout << "c";
						}
						else {
							cout << "d";
						}
					}
				}
				cout << "\n";
			}
		}
		else if (m % 2 == 1 && c % 2 == 1) {
			for (int i = 0; i < n; i ++) {
				for (int j = 0; j < m; j ++) {
					if (j < c/2 || m-j-1 < c/2 || j == m/2) {
						cout << 'a';
					}
					else {
						if (i % 3 == 0) {
							cout << "b";
						}
						else if (i % 3 == 1) {
							cout << "c";
						}
						else {
							cout << "d";
						}
					}
				}
				cout << "\n";
			}
		}
	}
	else if (c == m && r != 0) {
		// populate edges
		if (n % 2 == 0 && r % 2 == 1) {
			cout << "IMPOSSIBLE\n";
		}
		else if (n % 2 == 1 && r == n-1) {
			cout << "IMPOSSIBLE\n";
		}
		else if (r % 2 == 0) {
			for (int i = 0; i < n; i ++) {
				for (int j = 0; j < m; j ++) {
					if (i < r/2 || n-i-1 < r/2) {
						cout << 'a';
					}
					else {
						if (j % 3 == 0) {
							cout << "b";
						}
						else if (j % 3 == 1) {
							cout << "c";
						}
						else {
							cout << "d";
						}
					}
				}
				cout << "\n";
			}
		}
		else if (n % 2 == 1 && r % 2 == 1) {
			for (int i = 0; i < n; i ++) {
				for (int j = 0; j < m; j ++) {
					if (i < r/2 || n-i-1 < r/2 || i == n/2) {
						cout << 'a';
					}
					else {
						if (j % 3 == 0) {
							cout << "b";
						}
						else if (j % 3 == 1) {
							cout << "c";
						}
						else {
							cout << "d";
						}
					}
				}
				cout << "\n";
			}
		}
	}
	else if (r == n && c == 0) {
		// do layered alphabet, vertically. horizontally is same
		for (int i = 0; i < n; i ++) {
			for (int j = 0; j < m; j ++) {
				if (i % 3 == 0) {
					cout << 'a';
				}
				else if (i % 3 == 1) {
					cout << 'b';
				}
				else {
					cout << 'c';
				}
			}
			cout << "\n";
		}
	}
	else if (c == m && r == 0) {
		// do layered alphabet, horizontally. vertically is same
		for (int i = 0; i < n; i ++) {
			for (int j = 0; j < m; j ++) {
				if (j % 3 == 0) {
					cout << 'a';
				}
				else if (j % 3 == 1) {
					cout << 'b';
				}
				else {
					cout << 'c';
				}
			}
			cout << "\n";
		}
	}
	else if (c == 0 && r == 0) {
		// do layered alphabet both ways
		for (int i = 0; i < n; i ++) {
			for (int j = 0; j < m; j ++) {
				if ((i+j) % 3 == 0) {
					cout << 'a';
				}
				else if ((i+j) % 3 == 1) {
					cout << 'b';
				}
				else {
					cout << 'c';
				}
			}
			cout << "\n";
		}
	}
	else {
		// none of them are 0, none of them are max. first are a, then are b
		for (int i = 0; i < n; i ++) {
			for (int j = 0; j < m; j ++) {
				if (i < r || j < c) {
					cout << 'a';
				}
				else {
					if ((i+j) % 3 == 0) {
						cout << 'b';
					}
					else if ((i+j) % 3 == 1) {
						cout << 'c';
					}
					else {
						cout << 'd';
					}
				}
			}
			cout << "\n";
		}
	}
	
	
	return 0;
}

