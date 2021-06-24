#include <bits/stdc++.h>
using namespace std;

char maps[105][105] = { 0 };
int cluster[105][105] = { 0 };

int R, C, N;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};



void print_map() {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cout << maps[i][j];
        }
        cout << '\n';
    } 
}

void print_cluster() {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cout << cluster[i][j];
        }
        cout << '\n';
    } 
}

int bfs(int x_init, int y_init, int cluster_num) {
    int max_x = x_init;
    cluster[x_init][y_init] = cluster_num;

    queue<pair<int, int>> q;
    q.push({x_init, y_init});
    
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
            if (maps[nx][ny] == 'x' && cluster[nx][ny] == 0) {
                if (nx > max_x) max_x = nx;
                cluster[nx][ny] = cluster_num;
                q.push({nx, ny});
            }
        }
    }
    // cout << "x: " << x_init << "y: " << y_init << "cluster_num: " << cluster_num << '\n';
    // print_cluster();
    return R - max_x;
}

void fall(int cluster_num) {
    if (cluster_num < 0) return;
    // print_cluster();
    int min_x = R;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (cluster[i][j] == cluster_num) {
                maps[i][j] = '.';
                int k, fall_x;
                for (k = i + 1; k < R; k++) {
                    if (cluster[k][j] != cluster_num && cluster[k][j] > 0) {
                        fall_x = k - i - 1;
                        break;
                    }
                }
                if (k == R) {
                    fall_x = R - 1 - i;
                }
                if (min_x > fall_x) min_x = fall_x;
            }
        }
    }
    // cout << "fall: " << max_x << '\n';
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (cluster[i][j] == cluster_num) {
                maps[min_x + i][j] = 'x';
            }
        }
    }
}

void movemap(int x, int y) {
    // cout << "x: " << x << "y: " << y << '\n';
    int fall_cluster_num = -1;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
        if (maps[nx][ny] == 'x' && cluster[nx][ny] == 0) {
            int res = bfs(nx, ny, i + 1);
            if (res != 1) fall_cluster_num = i + 1;
        }
    }
    // cout << "fall_cluster_num: " << fall_cluster_num << '\n';
    fall(fall_cluster_num);
}

void play(int x, bool is_left) {
    // cout << "x: " << x << "is_left: " << is_left << '\n';
    if (is_left) {
        int i = 0;
        while (i < C) {
            if (maps[x][i] == 'x') {
                maps[x][i] = '.';
                movemap(x, i);
                break;
            }
            i++;
        }        
    } else {
        int i = C - 1;
        while (i >= 0) {
            if (maps[x][i] == 'x') {
                maps[x][i] = '.';
                movemap(x, i);
                break;
            }
            i--;
        }
    }
}

int main() {
    cin >> R >> C;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cin >> maps[i][j];
        }
    }
    cin >> N;
    int height;

    for (int i = 0; i < N; i++) {
        memset(cluster, 0, sizeof(cluster));
        cin >> height;
        play(R - height, !(i & 1));
    }
    print_map();
    return 0;
}