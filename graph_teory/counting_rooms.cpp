// Counting Rooms
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
int n,m;
 
void cekRuang(vector<vector<int>> &map, int r, int c) {
    if (r < 0 || r >= n || c < 0 || c >= m) return; 
    if (map[r][c] == 1) { // ketemu wall
        return;
    } else if (map[r][c] == 0) { // ketemu ruang ksosong yang belum dicek
        map[r][c] = 2; // tandai
        cekRuang(map,r,c+1);
        cekRuang(map,r,c-1);
        cekRuang(map,r-1,c);
        cekRuang(map,r+1,c);
    } else if (map[r][c] == 2) {
        return;
    }
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    cin >> n >> m;
    vector<vector<int>> map(n,vector<int>(m,0));
    for (auto &x: map) {
        string temp; cin >> temp;
        for (int i=0; i<m; i++) {
            if (temp[i] == '#') x[i] = 1;
            else x[i] = 0;
        }
    }
 
    ll count=0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (map[i][j] == 0) {
                cekRuang(map,i,j);
                count++;
            }
        }
    }
 
    cout << count;
 
    return 0;
}