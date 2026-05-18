// Grid Paths I
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n; cin >> n;
    vector<vector<ll>> dp(n+1,vector<ll>(n+1,0));
    ll mod = 1e9+7;
    dp[1][1] = 1;


    for (int i=1; i<=n; i++) {
        string s; cin >> s;
        for (int j=0; j<s.length(); j++) {
            if ((i == 1 && s[0] == '*') || (i==n && s[s.length()-1]=='*')) {
                cout << 0;
                return 0;
            }
            if (i==1 && j+1==1) continue;
            if (s[j] == '.') {
                dp[i][j+1] = (dp[i-1][j+1] + dp[i][j]) % mod;
            } else if (s[j] == '*') {
                dp[i][j+1] = 0;
            }
        }
    }

    cout << dp[n][n];

    return 0;
}