#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

int main() {
 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ull n;
    int k;
    cin >> n >> k;

    
    vector<ull> prima(k);
    for (auto &x: prima){
        cin >> x;
    }

    ull result = 0;
    ull mask_total = (1ULL <<k);

    for (ull mask = 1; mask < mask_total; mask ++){

        ull current = 1;
        int count_bit = 0;
        bool overflow = false;

        for (int i = 0; i < k; i++){

            if ((mask >> i) & 1){
                count_bit += 1;

                if (current > n / prima[i]) {
                    overflow = true;
                    break;
                }

                current *= prima[i];
            }
        }
        if (overflow){
            continue;
        }

        ull count_mask = n / current;

        if (count_bit % 2 == 0){
            result -= count_mask;
        }else{
            result += count_mask;
        }


    }

    cout << result << "\n";

}

