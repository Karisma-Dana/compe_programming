#include <bits/stdc++.h>
using namespace std;


const long long panjang = 1e6 + 1;
vector<long long> divisor(panjang, 0);
void findDivisor(){

    for (int i = 1; i <= panjang; i++){
        for (int j = i; j <= panjang; j+=i){
            divisor[j]++;
        }
    }
}

int main() {
 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    findDivisor();

    int n;
    if (cin >> n){
        while (n--)
        {
            int x;
            cin >> x;
            cout << divisor[x] << "\n";
        }
        
    }


}
