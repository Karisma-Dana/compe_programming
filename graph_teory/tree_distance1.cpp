#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
const int MAXN = 200005;
int distA[MAXN];
int distB[MAXN];
int farthes_node;
int max_dist = -1;

void dfs(int node, int current_dist, int parent, int dist[] ){
    dist[node] = current_dist;

    if (current_dist > max_dist){
        max_dist = current_dist;
        farthes_node = node;
    }

    for (int anak : adj[node]){
        if (anak != parent){
            dfs(anak, current_dist + 1, node, dist);
        }
    }

}



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, nodeA, nodeB;
    cin >> n; 
    adj.resize(n+1);

    for (int i = 0; i < n - 1; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    max_dist = -1;
    int tempDist[MAXN];
    dfs(1, 0, 0,tempDist);
    nodeA = farthes_node;



    max_dist = -1;
    dfs(nodeA, 0, 0, distA);
    nodeB = farthes_node;


    max_dist = -1;
    dfs(nodeB, 0, 0, distB);


    for (int i = 1; i <=n; i++){
        int result = max(distA[i], distB[i]);
        cout << result << " ";
    }








}