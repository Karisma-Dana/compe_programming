#include <bits/stdc++.h>
using namespace std;
#include <time.h>
// Your task is to count the number of ways to construct sum n by throwing a dice one or more times. Each throw produces an outcome between 1 and  6.
// For example, if n=3, there are 4 ways:

// 1+1+1
// 1+2
// 2+1
// 3

// Input
// The only input line has an integer n.
// Output
// Print the number of ways modulo 10^9+7.
// Constraints

// 1 \le n \le 10^6

// Example
// Input:
// 3

// Output:
// 4

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long n;
    cin >> n;

    int MOD = 1e9 + 7;
    long long  dp[n + 1] = {};
    dp[0] = 1;


    // dp {0} = 1;
    // dp [1] = dp[0];
    // dp [2] = dp[0] + dp[1]
    // dp [3] = dp[0] + dp[1] + dp[2]

    for (int i = 1; i <= n; i++ ){

        for (int j = 0; j <= 6 && j <= i; j++){
            dp[i] = (dp[i] + dp[i-j]) % MOD;
        }
    }
    

    cout << dp[n] << "\n";

}









