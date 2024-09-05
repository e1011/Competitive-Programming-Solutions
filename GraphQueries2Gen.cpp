#include <iostream>
#include <vector>
#include <queue>
#include <random>

using namespace std;

vector <vector <int>> dp(0);
vector <vector <int>> graph(0);
vector <vector <int>> costs(0);

int main(int argc, char **argv) {
	mt19937 mt_rand(atoi(argv[1]));
	int qsize=0;
	if (atoi(argv[4]) == 0) {
		qsize = 1000000000;
	}
	else {
		qsize = 1000;
	}
	
	int n = 1000, q = 1000000, k;
	
	cout << n << " " << q << "\n";
	
	graph = vector <vector <int>> (n, vector <int> (0));
	costs = vector <vector <int>> (n, vector <int> (0));
	
	for (int i = 1; i < n; i ++) {
		int u_i = mt_rand() % i + 1, v_i = i+1, l_i = atoi(argv[2])*(mt_rand() % (1000/atoi(argv[2])) + 1);
		cout << u_i << " " << v_i << " " << l_i << "\n";
		graph[u_i-1].push_back(v_i-1);
		graph[v_i-1].push_back(u_i-1);
		costs[u_i-1].push_back(l_i);
		costs[v_i-1].push_back(l_i);
	}
	
	k = 2*costs[0][0];
	
	dp = vector <vector <int>> (n, vector <int> (k, -1));
	priority_queue <vector <int>, vector <vector <int>>, greater <vector<int>>> pq;
	pq.push({0, 0, 0});
	
	while (!pq.empty()) {
        int mod=pq.top()[0], rem=pq.top()[1], node=pq.top()[2];
        pq.pop();

        if (dp[node][rem] == -1) {
            dp[node][rem] = mod;
            for (int i = 0; i < graph[node].size(); i ++) {
				int x = dp[graph[node][i]][(rem+costs[node][i]) % k];
				if (x == -1 || mod+(rem+costs[node][i])/k < x) {
					pq.push({mod+(rem+costs[node][i])/k, (rem+costs[node][i]) % k, graph[node][i]});
				}
            }
        }
    }
	
	for (int i = 0; i < q; i ++) {
		int q_i = mt_rand() % n + 1, c_i = mt_rand() % qsize/atoi(argv[3]) + 1;
		cout << q_i << " " << c_i << "\n";
		if (dp[q_i-1][c_i % k] != -1 && dp[q_i-1][c_i % k] <= c_i/k) {
			cerr << "YES\n";
		}
		else {
			cerr << "NO\n";
		}
	}
	
	return 0;
}

