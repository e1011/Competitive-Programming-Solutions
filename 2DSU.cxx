#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <vector <int> > ans, nodes, visited;
    
// a 2d dsu
struct DSU {

    vector <vector <vector <int> > > e;
    vector <vector <vector <vector <int> > > > e1;
    DSU(int n, int m) { e = vector <vector <vector <int> > >(n, vector <vector <int> > (m, vector <int> (2, -1))); 
                        e1 = vector <vector <vector <vector <int> > > > (n, vector <vector <vector <int> > > (m, vector <vector <int> > (0))); }

    vector <int> get(vector <int> x) { return e[x[0]][x[1]][0] < 0 ? x : e[x[0]][x[1]] = get(e[x[0]][x[1]]); }
    int size(vector <int> x) { return -e[get(x)[0]][get(x)[1]][0]; }

    bool unite(vector <int> x, vector <int> y, int h) {
        x = get(x), y = get(y);
        if (x == y) return false;
        if (e[x[0]][x[1]][0] > e[y[0]][y[1]][0]) swap(x, y);
        
        if (e1[x[0]][x[1]][0][0] < e1[y[0]][y[1]][0][0]) {
            for (int i = 0; i < e1[x[0]][x[1]].size(); i ++) {
                ans[e1[x[0]][x[1]][i][1]][e1[x[0]][x[1]][i][2]] = e1[x[0]][x[1]][i][0]-h;
            }
            e1[x[0]][x[1]] = e1[y[0]][y[1]];
        }
        else if (e1[x[0]][x[1]][0][0] > e1[y[0]][y[1]][0][0]) {
            for (int i = 0; i < e1[y[0]][y[1]].size(); i ++) {
                ans[e1[y[0]][y[1]][i][1]][e1[y[0]][y[1]][i][2]] = e1[y[0]][y[1]][i][0]-h;
            }
        }
        else {
            for (int i = 0; i < e1[y[0]][y[1]].size(); i ++) {
                e1[x[0]][x[1]].push_back(e1[y[0]][y[1]][i]);
            }
        }
        
        e[x[0]][x[1]][0] += e[y[0]][y[1]][0]; e[y[0]][y[1]] = x; return true;
    }
    void setvalue(int h, int i, int j) {
        e1[i][j].push_back({h, i, j});
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    
    ans = vector <vector <int>> (n, vector <int> (m, 0));
    visited = vector <vector <int>> (n, vector <int> (m, 0));
    nodes = vector <vector <int>> (0);
    
    DSU dsu(n, m);
    
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            int h;
            cin >> h;
            nodes.push_back({h, i, j});
            dsu.setvalue(h, i, j);
            ans[i][j] = h;
        }
    }
    
    sort(nodes.begin(), nodes.end());
    reverse(nodes.begin(), nodes.end());
    
    for (int i = 0; i < n*m; i ++) {
        visited[nodes[i][1]][nodes[i][2]] = 1;
        if (nodes[i][1] > 0 && visited[nodes[i][1]-1][nodes[i][2]] == 1) {
            dsu.unite({nodes[i][1], nodes[i][2]}, {nodes[i][1]-1, nodes[i][2]}, nodes[i][0]);
        }
        if (nodes[i][1] < n-1 && visited[nodes[i][1]+1][nodes[i][2]] == 1) {
            dsu.unite({nodes[i][1], nodes[i][2]}, {nodes[i][1]+1, nodes[i][2]}, nodes[i][0]);
        }
        if (nodes[i][2] > 0 && visited[nodes[i][1]][nodes[i][2]-1] == 1) {
            dsu.unite({nodes[i][1], nodes[i][2]}, {nodes[i][1], nodes[i][2]-1}, nodes[i][0]);
        }
        if (nodes[i][2] < m-1 && visited[nodes[i][1]][nodes[i][2]+1] == 1) {
            dsu.unite({nodes[i][1], nodes[i][2]}, {nodes[i][1], nodes[i][2]+1}, nodes[i][0]);
        }
    }
    
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
    
    return 0;
}


