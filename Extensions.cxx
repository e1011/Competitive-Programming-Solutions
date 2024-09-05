#include <iostream>

using namespace std;

int main() {
	int n;
	string s;
	cin >> n >> s;
	
	if (n % 2 == 1) {
		cout << s << "\n";
	}
	else {
		if (s == "left") {
			cout << "right\n";
		}
		else {
			cout << "left\n";
		}
	}
	
	
	return 0;
}

