#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
int max_dist = -1; 
int farthest_node = 0;



void dfs(int node, int parent, int current_ditance){
    if (current_ditance > max_dist){
        max_dist = current_ditance;
        farthest_node = node;
    }
    for (int anak : adj[node]){
        if (anak != parent){
            dfs(anak, node, current_ditance + 1);
        }
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;

    adj.resize(n+1);

    for (int i = 0; i < n-1; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if (n == 1){
        cout << "0";
        return 0;
    }
    
    dfs(1, 0,0);
    int next = farthest_node;


    max_dist = -1;
    dfs(next, 0, 0);

    cout << max_dist;










}
