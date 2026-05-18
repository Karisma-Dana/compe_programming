#include <bits/stdc++.h>
using namespace std;



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, x;
    int MOD = 1e9 + 7;
    cin >> n;
    cin >> x;

    int coin[n];
    for(int i = 0; i < n; i++){
        cin >> coin[i];
    };
    vector<long long> dp(x + 1);
    dp[0] = 1;

    for (int i = 1; i <= x; i++){
        for (int j = 0; j < n; j++ ){
            if (i - coin[j] >= 0){
                dp[i] = (dp[i] +  dp[i - coin[j]]) %  MOD;
            }
        }
    }
    cout << dp[x] << "\n";


}