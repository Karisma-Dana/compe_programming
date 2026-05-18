#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, m;
int start_r, start_c, end_r, end_c;

// Array untuk mempermudah pengecekan 4 arah (Atas, Bawah, Kiri, Kanan)
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};
char dir_char[] = {'U', 'D', 'L', 'R'};

int main() {
    // Optimasi Input/Output
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    
    // Kita cukup pakai vector of string untuk menyimpan peta, lebih hemat memori
    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
        for (int j = 0; j < m; j++) {
            // Deteksi titik Start (A) dan End (B)
            if (grid[i][j] == 'A') {
                start_r = i;
                start_c = j;
            } else if (grid[i][j] == 'B') {
                end_r = i;
                end_c = j;
            }
        }
    }

    // Matriks untuk Parent Tracking dan Penanda (Visited)
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m, {-1, -1}));
    vector<vector<char>> step(n, vector<char>(m, ' '));

    // Antrean untuk BFS
    queue<pair<int, int>> q;

    // 1. Mulai dari titik A
    q.push({start_r, start_c});
    visited[start_r][start_c] = true;

    bool found = false;

    // 2. Loop BFS
    while (!q.empty()) {
        pair<int, int> curr = q.front();
        int r = curr.first;
        int c = curr.second;
        q.pop();

        // Jika sampai di B, hentikan pencarian (Break)
        if (r == end_r && c == end_c) {
            found = true;
            break;
        }

        // Cek ke 4 arah
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            // Cek Boundary, Tembok, dan Visited
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] != '#' && !visited[nr][nc]) {
                visited[nr][nc] = true;        // Tandai sudah dikunjungi
                parent[nr][nc] = {r, c};       // Simpan siapa yang membawa ke sini
                step[nr][nc] = dir_char[i];    // Simpan arah langkahnya (U/D/L/R)
                q.push({nr, nc});              // Masukkan ke antrean
            }
        }
    }

    // 3. Output dan Backtracking
    if (found) {
        cout << "YES\n";
        string path = "";
        pair<int, int> curr = {end_r, end_c};

        // Jalan mundur dari B ke A
        while (curr.first != start_r || curr.second != start_c) {
            int r = curr.first;
            int c = curr.second;
            
            path += step[r][c];       // Kumpulkan jejak arahnya
            curr = parent[r][c];      // Pindah ke posisi parent-nya
        }

        // Karena dicatat mundur, kita harus reverse string-nya
        reverse(path.begin(), path.end());

        cout << path.length() << "\n";
        cout << path << "\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}