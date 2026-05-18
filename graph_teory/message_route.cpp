#include <bits/stdc++.h>
using namespace std;



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    

    int n, m;
    cin >> n >> m;

    vector<int> adj[n + 1];

    for (int i = 0; i < m; i ++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }


    vector<bool> path(n + 1, false);
    vector<int> parent(n + 1, 0);

    queue<int> q;

    q.push(1);
    path[1] = 1;
    int found;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();


        if (u == n){
            found = n;
            break;
            path[u] = true;
        }

        for (int v : adj[u]){
            if (path[v] == false){
                path[v] = true;
                parent[v] = u;
                q.push(v);
            }
        }        
    }

    if (path[n] == false){
        cout << "IMPOSSIBLE\n";
    }else{

        int count;
        int n = found;
        vector<int> resultPath;

        while (n != 0)
        {
            cout << n << " ";
            n = parent[n];
        }

        cout << resultPath.size() << "\n";
        for (int i = resultPath.size() - 1; i >= 0; i--){
            cout << resultPath[i] << " ";
        }

      
        
    }
    return 0;
    




}