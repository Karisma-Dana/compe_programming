#include <bits/stdc++.h>
using namespace std;

const int MAX_INT = 1000000;
int frequensi[MAX_INT + 1];
int main() {
 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; 
    cin >> n;

    int max_value = 0;
    for (int i = 0; i < n; i++){
        int x;
        cin >> x;
        frequensi[x]++;

        max_value = max(max_value,x);
    }

    for (int i = max_value; i>= 1; i--){
        int kelipatan = 0;
        for (int j = i; j <= max_value; j+=i){
            kelipatan += frequensi[j];
        }
        if (kelipatan >= 2){
            cout << i;
            return 0;
        }
    }

}