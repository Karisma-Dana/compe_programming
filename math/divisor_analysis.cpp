#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll number = 1;
ll sum = 0;
ll product = 0;


const ll MOD = 1000000007;
const ll INV2 = 500000004;
vector<int> question[100000];

void get_number(){
    
    for(int i = 0; i < question->size(); i++){
        number *= (question[i][1] + 1) % MOD;
    }

}


int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    if (cin >> n){
        question->resize(n);
        for (int i = 0; i < n; i++){
            int x, y;
            cin >> x >> y;
            question[i].push_back(x);
            question[i].push_back(y);
        }

        get_number();


    }



}