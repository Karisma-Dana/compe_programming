#include <bits/stdc++.h>
using namespace std;

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);


    string m;
    cin >> m;
    vector<pair<char, int>> pola;
    pola.push_back({' ', 0});
    for (int i = 1; i <= m.length(); i ++){
        if (i == 1){   
            pola.push_back({m[i-1], 0});
        }else{
            if (m[i - 1] == m[pola[i - 1].second]){
                pola.push_back({m[i-1], pola.at(i-1).second + 1});
            }else if (m[i - 1] == m[pola[i-1].second - 1]){
                pola.push_back({m[i-1], pola.at(i-1).second});
            }
            else if (m[i -1] == m[0]){
                pola.push_back({m[i-1], 1});
            }
            else{
                pola.push_back({m[i-1], 0});
            }
        }
    }
    vector<int> result;
    int hasil = pola[m.length()].second;
    if (hasil != 0){
        
    }
    result.push_back(hasil);
    while(hasil > 0){
        hasil = pola[hasil].second;
        if(hasil == 0){
            break;
        }
        result.push_back(hasil);

    }
    for (int i = result.size() - 1; i >= 0; i--){
        cout << result[i] << " ";
    }




}
