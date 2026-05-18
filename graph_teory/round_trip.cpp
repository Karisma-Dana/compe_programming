#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;

bool visited[MAXN];
vector<int> adj[MAXN];
int parent[MAXN];

int start = -1;
int ending = -1;

bool dfs(int s, int p){
    visited[s] = true;
    parent[s] = p;

    for (int v : adj[s]){
        if (v == p) continue;

        if (visited[v]){
            start = v;
            ending = s;
            return true;
        }
        if (!visited[v]){
            if (dfs(v, s)){
                return true;
            }
            
        }
    }
    return false;

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); 

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i ++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i < n + 1; i++){
        if (!visited[i] && dfs(i, 0)) {
            break;
        }
    }

    if (ending == -1) cout << "IMPOSSIBLE" ;
    else{
        vector<int> round_trip;
        round_trip.push_back(start);

        while (ending != start)
        {
            round_trip.push_back(ending);
            ending = parent[ending];
        }
        round_trip.push_back(start);
        
        
        cout << round_trip.size() << "\n";
        for (int v : round_trip){
            cout << v << " ";
        }
        
    }

}
