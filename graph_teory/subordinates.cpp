#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> count_result;


int findSubordinates( int s ){
    int total = 0;

    for (int bawahan : adj[s]){
        total += 1 + findSubordinates(bawahan);
    }

    count_result[s] = total;
    return total;

}



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    
    adj.resize(n+1);
    count_result.resize(n+1, 0);

    for (int i = 2; i <= n; i++){
        int upper;
        cin >> upper;
        adj[upper].push_back(i);
    }

    findSubordinates(1);

    for(int i = 1; i <= n; i++){
        cout << count_result[i] << " ";
    }

    






}