#include <bits/stdc++.h>
using namespace std;

int main() {
    // Optimasi I/O
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;

    // Perbaikan 1: Gunakan vector 1D dan hindari nama 'stack'
    int arr[n];
    for(auto &x : arr){
        cin >> x;
    }

    int dpLeft[n];
    int dpRight[n];
    int max_time = 0;

    // Looping Kiri ke Kanan
    for (int i = 0; i < n; i++){
        if (i == 0){
            dpLeft[i] = min(1,arr[i]);
        } else {
            dpLeft[i] = min(dpLeft[i - 1] + 1, arr[i]);
        }
    }

    // Perbaikan 2: Looping Kanan ke Kiri, mulai dari n - 1
    for (int i = n - 1; i >= 0; i--){
        if (i == n - 1){
            dpRight[i] = min(1, arr[i]);
        } else {
            dpRight[i] = min(dpRight[i + 1] + 1, arr[i]);
        }
    }

    // Mencari waktu maksimal
    for (int i = 0; i < n; i++){
        max_time = max(max_time,  min(dpLeft[i], dpRight[i]));
    }

    // Menampilkan hasil
    cout << max_time << "\n";

    return 0;
}