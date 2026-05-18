#include <bits/stdc++.h>
using namespace std;

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, x;
    cin >> n >> x;

    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    // Initialize DP array with a value larger than any possible answer (x + 1)
    vector<int> dp(x + 1, 1e9);
    dp[0] = 0;

    for (int i = 1; i <= x; i++) {
        for (int c : coins) {
            if (i - c >= 0) {
                dp[i] = min(dp[i], dp[i - c] + 1);
            }
        }
    }

    // If dp[x] is still 1e9, it means the sum is impossible
    if (dp[x] == 1e9) {
        cout << -1 << endl;
    } else {
        cout << dp[x] << endl;
    }

    return 0;
}