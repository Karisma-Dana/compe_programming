#include <bits/stdc++.h>
using namespace std;
int N = 100001;
vector<vector<int>> adj(N, vector<int>());
vector<int> team(100001, 0);
bool check = true;



void dfs ( int s ){
    if (team[s] == 0) team[s] = 1;
    int next = (team[s] == 1) ? 2 : 1;

    for (int u : adj[s]){
        if (team[u] == 0){
            team[u] = next;
            dfs(u);
        }else{
            if (team[u] != next){
                check = false;
                return;
            }     
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i < n + 1; i++){
        if (team[i] == 0 ){
            dfs(i);
        }
        if (!check){
            cout << "IMPOSSIBLE" ;
            break;
        }
    }

    if (check){
        for (int i = 1; i <= n; i++){
            cout << team[i] << " ";
        }
    }
        
    
    
    return 0;
        
    



    


}
