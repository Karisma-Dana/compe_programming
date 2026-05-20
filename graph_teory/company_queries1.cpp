#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
vector<vector<int>> query;
vector<vector<int>> boss;



void dfs(int node, int current){
    for (int bawahan : adj[node]){
        boss[bawahan].push_back(node);
        if (current > 0){
            for (int i = 1; i <= current; i++){
                boss[bawahan].push_back(boss[node][i-1]);
            }
        }
        dfs(bawahan, current + 1);
    }
}



int main(){
    


    int n, m;
    cin >> n >> m;
    adj.resize(n + 1);
    boss.resize(n+1);
    query.resize(m);
    for (int i = 2; i <= n; i++ ){
        int upper;
        cin >> upper;
        adj[upper].push_back(i);
    }

    for (int i = 0; i < m; i ++){
        int u, v;
        cin >> u >> v;
        query[i].push_back(u);
        query[i].push_back(v);
    }

    dfs(1, 0);
    for (int i = 0; i < m; i ++){
        int u = query[i][0];
        int v = query[i][1] -1;
        
        if (v >= (int)boss[u].size()){
            cout << -1 << "\n";
        }else{
            cout  << boss[u][v] << "\n";
        }
    }


    






}