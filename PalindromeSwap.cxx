#include <iostream>
#include <vector>

using namespace std;

int main() {
	string s;
	cin >> s;
	
	long long pointerl=0, pointerr=(int)s.size()-1, counterl=0, counterr=0, ans=0, acount=0, bcount=0;
	
	for (int i = 0; i < s.size(); i ++) {
		if (s[i] == 'a') {
			acount += 1;
		}
		else {
			bcount += 1;
		}
	}
	
	if (acount % 2 == 1 && bcount % 2 == 1) {
		cout << "-1\n";
	}
	else {
		while (true) {
			while (s[pointerl] != 'b') {
				pointerl += 1;
				counterl += 1;
			}
			if (pointerl > pointerr) {
				break;
			}
			
			while (s[pointerr] != 'b') {
				pointerr -= 1;
				counterr += 1;
			}
			if (pointerr == pointerl) {
				ans += abs(counterl-counterr)/2;
				break;
			}
			else {
				ans += abs(counterl-counterr);
			}
			
			pointerl += 1;
			pointerr -= 1;
		}
		
		cout << ans << "\n";
	}
	
	return 0;
}

