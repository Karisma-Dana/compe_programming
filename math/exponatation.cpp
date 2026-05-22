#include <bits/stdc++.h>
using namespace std;


const long long MOD = 1000000007;

long long power(long long base, long long exp) {
    long long res = 1; 
    base = base % MOD; 

    while (exp > 0) {
        if (exp % 2 == 1) {
            res = (res * base) % MOD;
        }
        
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

int main() {
 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    if (cin >> n) {
        while (n--) {
            long long a, b;
            cin >> a >> b;
            
        
            if (a == 0 && b == 0) {
                cout << 1 << "\n";
            } else {
                cout << power(a, b) << "\n";
            }
        }
    }
    return 0;
}