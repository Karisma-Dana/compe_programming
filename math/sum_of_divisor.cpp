#include <iostream>

using namespace std;
typedef long long ll;

// Konstanta wajib untuk modulo dan Inverse dari 2
const ll MOD = 1000000007;
const ll INV2 = 500000004;

int main() {
    // Optimasi I/O untuk kompetisi
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    if (cin >> n){

        ll sum = 0;

        ll L = 1;
        while (L <= n)
        {
            ll K = n / 2;
            ll R = n / K;


            ll jumlahDeret = ((L * R) % MOD) * ((R - L + 1) % MOD) % MOD;
            jumlahDeret = (jumlahDeret *INV2) % MOD;
            
            ll Kmod = K % MOD;
            ll sum_blok = (Kmod * jumlahDeret) % MOD;
            sum = (sum + sum_blok) % MOD;


            L = R+1;
        }
        cout << sum << "\n";
    }


    return 0;
}