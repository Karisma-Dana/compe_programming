#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

const long long MODULUS = 1000000007;
const long long MOD_EXPO = 1000000006;

ull power(ull base, ull exp, ull MOD){

    ull result = 1;
    base = base % MOD;
    
    while (exp > 0)
    {
        if (exp % 2 == 1){
            result = (result * base) % MOD;

        }
        base = (base * base) % MOD;
        exp /= 2;
    }
    return result;
    
}


int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n; 


    if (cin >> n){
        ull number = 1;
        ull sum = 1;
        ull product = 1;

        ull number_expo = 1;
        for (int i = 0; i < n; i ++){
            ull x, k;
            cin >> x >> k;


            // number 
            number = (number * (k + 1)) % MODULUS;


            // sum 
            ull pembilang = (power(x, k+1, MODULUS) - 1  + MODULUS) % MODULUS;
            ull penyebut = power(x - 1, MODULUS -2, MODULUS);

            sum = (sum * ((pembilang * penyebut) % MODULUS)) %  MODULUS;


            // product 
            ull part1 = power(product, k + 1, MODULUS);

            long long pow_k;
            if (k % 2 == 0) {
                pow_k = ((k / 2) % MOD_EXPO * (k + 1) % MOD_EXPO) % MOD_EXPO;
            } else {
                pow_k = (k % MOD_EXPO * ((k + 1) / 2) % MOD_EXPO) % MOD_EXPO;
            }

            long long term_p = power(x, pow_k, MODULUS);
   
            long long part2 = power(term_p, number_expo, MODULUS);
            
    
            product = (part1 * part2) % MODULUS;

            number_expo = (number_expo * (k + 1)) % MOD_EXPO;




        }


        cout << number << " " << sum << " " << product;
    }
    return 0;





}