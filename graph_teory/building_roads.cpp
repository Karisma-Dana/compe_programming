#include <iostream>
#include <vector>

using namespace std;

vector<int> adj[100005];
bool visited[100005];
vector<int> representatives;

void dfs(int s) {
    visited[s] = true;
    for (int u : adj[s]) {
        if (!visited[u]) dfs(u);
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            representatives.push_back(i);
            dfs(i);
        }
    }
    cout << representatives.size() - 1 << endl;

    // Output koordinat jalan baru
    for (int i = 0; i < (int)representatives.size() - 1; i++) {
        cout << representatives[i] << " " << representatives[i + 1] << endl;
    }

    return 0;
}