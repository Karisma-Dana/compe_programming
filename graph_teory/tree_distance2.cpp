#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200005;
vector<vector<int>> adj;
vector<long long> dp(MAXN, 0);
vector<long long> subTree(MAXN);
int n;



void dfs(int node, int parent, int sum){
    dp[1] += sum;
    subTree[node] = 1;

    for (int anak : adj[node]){
        if (anak != parent){
            dfs(anak, node, sum + 1);
            subTree[node] += subTree[anak];
        }
    }
}


void tracking(int node, int parent){
    for (int anak : adj[node]){
        if (anak != parent){
            dp[anak] = dp[node] + n - 2 * subTree[anak];
            tracking(anak, node);
        }
        
    }
}


int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    adj.resize(n+1);
    dp.resize(n+1);
    subTree.resize(n+1, 0);

    for (int i = 0; i < n - 1; i ++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0, 0);
    tracking(1, 0);
    for (int i = 1; i <= n; i++){
        cout << dp[i] << " ";
        
    }







}