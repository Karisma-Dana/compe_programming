/ Array Description
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    ll mod = 1e9+7;
    ll n,m; cin >> n >> m;
    // x arraynya
    vector<ll> x(n);
    for (auto &x: x) {
        cin >> x;
    }
    vector<vector<ll>> dp(2,vector<ll>(m+2,0));
 
    if (x[0] == 0) {
        for (int i=1; i<=m; i++) {
            dp[0][i] = 1;
        }
    } else {
        dp[0][x[0]] = 1;
    }
 
    for (int i=1; i<n; i++) {
        for (int j=1; j<=m; j++) {
            if (x[i] == 0) {
                 dp[1][j] = (dp[0][j-1] + dp[0][j] + dp[0][j+1])%mod;
            } else {
                if (j != x[i]) {
                    dp[1][j] = 0;
                } else {
                    dp[1][j] = (dp[0][j-1] + dp[0][j] + dp[0][j+1])%mod;
                }
            }
        }
        for (int j=1; j<=m; j++) {
            dp[0][j] = dp[1][j];
        }
    }
 
    ll total=0;
    for (int i=1; i<=m; i++) {
        total += dp[0][i];
    }
 
    cout << total%mod;
 
 
    return 0;
}