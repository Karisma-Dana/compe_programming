#include <bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, x, y;
    cin >> n >> x >> y;
    vector<int> arr(n);
    int count = 0;
    bool test = false;
    for (auto &z : arr){
        cin >> z;
        if (z >= x){
            count += 1;
            if (count >= y){
                test = true;
            }
        }
    }

    if (test){
        cout << "YES";
    }else{
        cout << "NO";
    }



}