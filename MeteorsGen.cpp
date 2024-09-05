#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

int main(int argc, char **argv) {
	mt19937 mt_rand(atoi(argv[1]));
	
	if (atoi(argv[1]) == 41) {
		cout << "10 3 1\n1 9 10\n7 10 11\n0 4 12\n";
		cerr << "NO\n";
		return 0;
	}
	if (atoi(argv[1]) == 42) {
		cout << "10 3 1\n0 2 5\n1 4 6\n0 10 7\n";
		cerr << "NO\n";
		return 0;
	}
	if (atoi(argv[1]) == 43) {
		cout << "1000 2 1\n300 600 1000\n0 400 1001\n";
		cerr << "YES\n";
		return 0;
	}
	if (atoi(argv[1]) == 44) {
		cout << "1000 2 1\n300 600 1000\n500 1000 1001\n";
		cerr << "YES\n";
		return 0;
	}
	
	
	int n = 1000000000, m = 10000, k = mt_rand() % 1000000 + 1, counter=0, inmeteor=0;
	cout << n << " " << m << " " << k << "\n";
	
	vector <vector <int>> possibleplaces(0);
	possibleplaces.push_back({0, 0});
	possibleplaces.push_back({0, 1});
	
	vector <vector <int>> meteors(m, vector <int> (3, 0));
	for (int i = 0; i < m; i ++) {
		meteors[i][0] = i+1;
		meteors[i][1] = max(0, (int)(mt_rand() % (n+1)) - 20000000);
		meteors[i][2] = min(meteors[i][1]+(int)(mt_rand() % 40000000), n);
	}
	sort(meteors.begin(), meteors.end());
	
	for (int i = 0; i < m; i ++) {
		int a = meteors[i][1], b = meteors[i][2], t = meteors[i][0];
		cout << a << " " << b << " " << t << "\n";
		vector <vector <int>> newpossibleplaces1(0), newpossibleplaces2(0);
		for (int j = 0; j < possibleplaces.size(); j ++) {
			if (possibleplaces[j][1] == 0) {
				newpossibleplaces1.push_back({max(possibleplaces[j][0]-k, 0), 0});
			}
			else if (possibleplaces[j][1] == 1) {
				newpossibleplaces1.push_back({min(possibleplaces[j][0]+k, n), 1});
			}
		}

		newpossibleplaces1.push_back({a-1, 2});
		newpossibleplaces1.push_back({b+1, 0, 1});
		sort(newpossibleplaces1.begin(), newpossibleplaces1.end());
		for (int j = 0; j < newpossibleplaces1.size(); j ++) {
			if (newpossibleplaces1[j][1] == 2) {
				inmeteor = 1;
				if (counter > 0) {
					newpossibleplaces2.push_back({newpossibleplaces1[j][0], 1});
				}
			}
			else if (newpossibleplaces1[j].size() == 3) {
				inmeteor = 0;
				if (counter > 0) {
					newpossibleplaces2.push_back({newpossibleplaces1[j][0], 0});
				}
			}
			else if (newpossibleplaces1[j][1] == 0) {
				if (counter == 0 && inmeteor == 0) {
					newpossibleplaces2.push_back({newpossibleplaces1[j][0], 0});
				}
				counter += 1;
			}
			else {
				counter -= 1;
				if (counter == 0 && inmeteor == 0) {
					newpossibleplaces2.push_back({newpossibleplaces1[j][0], 1});
				}
			}
		}
		possibleplaces = newpossibleplaces2;
		counter = 0;
	}
	
	if (possibleplaces.size()) {
		cerr << "YES\n";
	}
	else {
		cerr << "NO\n";
	}
	
	
	return 0;
}

