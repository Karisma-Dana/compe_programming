#include <bits/stdc++.h>
using namespace std;


int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string n, m;
    cin >> n;

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
            }else{
                pola.push_back({m[i-1], 0});
            }
        }
    }

    int count = 0;

    int j = 0;
    for (int i = 0; i < n.length();){
        if (n[i] == pola[j+1].first){
            if (m.length() == 1){
                count++;
                j = 0;
                i++;
            } else if (j == (pola.size() - 2)){
                count++;
                j = pola[pola.size() - 1].second; 
                i++; 
            } else {
                j++;
                i++;
            }
        } else {
            if (j > 0){
                j = pola[j].second;
            } else {
                i++;
            }
        }
    }

    

    cout << count;










}