#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector <int> nodetonum(0)
vector <vector <int>> edges(0);

int main() {
	int n, a, b;
	cin >> n >> a >> b;
	
	nodetonum = vector <int> (2*n, 0);
	edges = vector <vector <int>> (2*n, vector <int> (0));
	map <int, vector <int>> numtonode;
	
	for (int i = 0; i < n; i ++) {
		cin >> nodetonum[i];
		map[nodetonum[i]].push_back(i);
	}
	for (int i = 0; i < n; i ++) {
		cin >> nodetonum[n+i];
		for (int j = 0; j < numtonode[b-a+nodetonum[n+i]].size(); j ++) {
			edges[n+i].push_back(numtonode[b-a+nodetonum[n+i]][j]);
			edges[b-a+numtonode[nodetonum[n+i]][j]].push_back(n+i);
		}
		for (int j = 0; j < numtonode[b-a-nodetonum[n+i]].size(); j ++) {
			edges[n+i].push_back(numtonode[b-a-nodetonum[n+i]][j]);
			edges[b-a-numtonode[nodetonum[n+i]][j]].push_back(n+i);
		}
	}
	
	
		
	return 0;
}

