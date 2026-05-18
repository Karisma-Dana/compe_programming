#include <bits/stdc++.h>
using namespace std;

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, temp;
    cin >> n;
    vector<int> dp(n + 1, 1e9);
    dp[0] = 0;


    for (int i = 1; i <= n; i++){
        temp = i;

        while (temp > 0)
        {
            int digit = temp % 10;
            temp /= 10;

            if (digit != 0){
                dp[i] = min(dp[i], dp[i - digit] + 1);
            }
        }
    }
    cout << dp[n] << "\n";


}