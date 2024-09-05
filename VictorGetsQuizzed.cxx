#include <iostream>

using namespace std;

int main() {
	int t;
	cin >> t;
	
	for (int i = 0; i < t; i ++) {
		string s;
		cin >> s;
		
		bool math=false, cs=false;
		for (int j = 0; j < s.size(); j ++) {
			if (s[j] == 'M') {
				math = true;
			}
			if (s[j] == 'C') {
				cs = true;
			}
		}
		
		if (math == false && cs == false) {
			cout << "PASS\n";
		}
		else if (math == true && cs == true) {
			cout << "NEGATIVE MARKS\n";
		}
		else {
			cout << "FAIL\n";
		}
	}
	
	
	return 0;
}

