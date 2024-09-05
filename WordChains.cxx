#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int maxvalue=1, index=0;
	
	vector <string> words(0);
	vector <int> values(0);
	vector <int> linkback(0);
	
	while (true) {
		string s;
		cin >> s;
		if (s == ".") {
			break;
		}
		words.push_back(s);
		values.push_back(1);
		linkback.push_back(-1);
		while (s.size() > 0) {
			s.erase(s.begin()+(int)s.size()-1);
			
			int l = 0, r = (int)words.size()-1;
			while (l < r) {
				int mid = (l+r)/2;
				if (words[mid] == s) {
					values[(int)values.size()-1] += values[mid];
					linkback[(int)linkback.size()-1] = mid;
					if (values[(int)values.size()-1] > maxvalue) {
						index = (int)values.size()-1;
						maxvalue = values[(int)values.size()-1];
					}
					break;
				}
				if (words[mid] < s) {
					l = mid+1;
				}
				else {
					r = mid;
				}
			}
			if (values[(int)values.size()-1] != 1) {
				break;
			}
		}
	}
	
	vector <string> words2(0);
	while (index != -1) {
		words2.push_back(words[index]);
		index = linkback[index];
	}
	for (int i = (int)words2.size()-1; i >= 0; i --) {
		cout << words2[i] << "\n";
	}
	
	
	return 0;
}


