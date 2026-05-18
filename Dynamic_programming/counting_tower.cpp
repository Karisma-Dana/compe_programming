#include <bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    const int MOD = 1e9 + 7;
    long long max_elemnt;
    cin >> n;

    vector<long long> height(n);
    for (auto &x :height){
        cin >> x;
    }

    max_elemnt = *std::max_element(height.begin(), height.end());
    vector<vector<long long>> dp(max_elemnt+ 1, vector<long long>(2,0));

    dp[1][0] = 1;
    dp[1][1] = 1;
    for (int i = 2; i <= max_elemnt; i++){
        dp[i][0] = ((2 * dp[i - 1][0]) + dp[i-1][1]) % MOD;
        dp[i][1] = (1 * dp[i-1][0] + (4 * dp[i-1][1])) % MOD;
    }

    for (auto &x : height){
        cout << (dp[x][0] + dp[x][1]) % MOD << "\n";
    }
    
}