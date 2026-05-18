#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> isCouple;
int count_relation = 0;



void dfs( int node, int parent){

    for (int anak : adj[node]){
        if (anak != parent){
            dfs(anak, node);
            if (!isCouple[anak] && !isCouple[node]){
                isCouple[anak] = true;
                isCouple[node] = true;
                count_relation +=1;
            }

        }
    }
}
int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;

    adj.resize(n+1);
    isCouple.resize(n+1, false);

    for (int i = 0; i < n - 1; i++){
        int u,v; 
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);

    cout << count_relation << "\n";
    return 0;










    
    







}