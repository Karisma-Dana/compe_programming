#include <bits/stdc++.h>
using namespace std;

// There are n applicants and m free apartments. Your task is to distribute the apartments so that as many applicants as possible will get an apartment.
// Each applicant has a desired apartment size, and they will accept any apartment whose size is close enough to the desired size.
// Input
// The first input line has three integers n, m, and k: the number of applicants, the number of apartments, and the maximum allowed difference.
// The next line contains n integers a_1, a_2, \ldots, a_n: the desired apartment size of each applicant. If the desired size of an applicant is x, they will accept any apartment whose size is between x-k and x+k.
// The last line contains m integers b_1, b_2, \ldots, b_m: the size of each apartment.
// Output
// Print one integer: the number of applicants who will get an apartment.
// Constraints

// 1 \le n, m \le 2 \cdot 10^5
// 0 \le k \le 10^9
// 1 \le a_i, b_i \le 10^9

// Example
// Input:
// 4 3 5
// 60 45 80 60
// 30 60 75

// Output:
// 2

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m,k;
    cin >> n;
    cin >> m;
    cin >> k;
    // n = jumlah pelamar 
    // m = apaertement yang tersedia
    // k = selisih

    int appartement_diigninkan[n];
    int appertement_tersedia[m];
    for (int i = 0; i < n; i++){
        cin >> appartement_diigninkan[i];
    }
    for (int i = 0; i < m; i++){
        cin >> appertement_tersedia[i];
    }

    sort(appartement_diigninkan, appartement_diigninkan + n);
    sort(appertement_tersedia, appertement_tersedia + m);
    int i = 0;
    int j = 0;
    int result = 0;

    while (i < n && j < m) {
        if (appertement_tersedia[j] < appartement_diigninkan[i] - k) {
            j++;
        }

        else if (appertement_tersedia[j] > appartement_diigninkan[i] + k) {
            i++; 
        }

        else {
            result++; 
            i++; 
            j++; 
        }
    }
    cout << result << "\n";








}