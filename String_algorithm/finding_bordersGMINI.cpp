#include <bits/stdc++.h>
using namespace std;

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string m;
    if (!(cin >> m)) return 0;
    
    vector<pair<char, int>> pola;
    pola.push_back({' ', 0});
    
    // --- PERBAIKAN 1: Menggunakan WHILE untuk tabel pola yang akurat ---
    for (int i = 1; i <= m.length(); i ++){
        if (i == 1){   
            pola.push_back({m[i-1], 0});
        }else{
            int prev_lps = pola[i - 1].second;
            
            // Mundur berantai mencari border yang cocok
            while (prev_lps > 0 && m[i - 1] != m[prev_lps]) {
                prev_lps = pola[prev_lps].second;
            }
            
            if (m[i - 1] == m[prev_lps]) {
                pola.push_back({m[i-1], prev_lps + 1});
            } else {
                pola.push_back({m[i-1], 0});
            }
        }
    }
    
    vector<int> result;
    int hasil = pola[m.length()].second;
    
    // --- PERBAIKAN 2: Proteksi agar angka 0 tidak ikut tercetak ---
    if (hasil > 0) {
        result.push_back(hasil);
        while(hasil > 0){
            hasil = pola[hasil].second;
            if(hasil == 0){
                break;
            }
            result.push_back(hasil);
        }
    }
    
    // Cetak terbalik dari yang terkecil (Gaya asli Boss)
    for (int i = (int)result.size() - 1; i >= 0; i--){
        cout << result[i] << " ";
    }

    return 0;
}