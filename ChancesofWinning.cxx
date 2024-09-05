#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector <vector <int>> results(0);
vector <vector <int>> availablegames(0);

void playgame(int gamenumber, vector <int> points) {
	if (gamenumber == availablegames.size()) {
		results.push_back(points);
	}
	else {
		vector <int> points1 = points;
		points1[availablegames[gamenumber][0]] += 1;
		points1[availablegames[gamenumber][1]] += 1;
		playgame(gamenumber+1, points1);

		vector <int> points2 = points;
		points2[availablegames[gamenumber][0]] += 3;
		playgame(gamenumber+1, points2);

		vector <int> points3 = points;
		points3[availablegames[gamenumber][1]] += 3;
		playgame(gamenumber+1, points3);
	}
}

int main() {
	int n, k, ans=0;
	cin >> n >> k;
	
	vector <int> currentpoints(4, 0);
	set <vector <int>> gamesplayed;
	for (int i = 0; i < k; i ++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		if (c == d) {
			currentpoints[a-1] += 1;
			currentpoints[b-1] += 1;
		}
		else if (c > d) {
			currentpoints[a-1] += 3;
		}
		else {
			currentpoints[b-1] += 3;
		}
		gamesplayed.insert({a-1, b-1});
	}
	
	for (int i = 0; i < 4; i ++) {
		for (int j = i+1; j < 4; j ++) {
			if (gamesplayed.count({i, j}) == 0) {
				availablegames.push_back({i, j});
			}
		}
	}
	
	playgame(0, currentpoints);
	for (int i = 0; i < results.size(); i ++) {
		if (n == 1 && results[i][0] > results[i][1] && results[i][0] > results[i][2] && results[i][0] > results[i][3]) {
			ans += 1;
		}
		if (n == 2 && results[i][1] > results[i][0] && results[i][1] > results[i][2] && results[i][1] > results[i][3]) {
			ans += 1;
		}
		if (n == 3 && results[i][2] > results[i][0] && results[i][2] > results[i][1] && results[i][2] > results[i][3]) {
			ans += 1;
		}
		if (n == 4 && results[i][3] > results[i][0] && results[i][3] > results[i][1] && results[i][3] > results[i][2]) {
			ans += 1;
		}
	}
	
	cout << ans << "\n";
	
	
	return 0;
}

