#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,no-stack-protector")

// QQ came here

using namespace std;

/*
6 6
######
##.#.#
#..#.#
#.##.#
#.#..#
######
4
2 3
5 4
2 5
5 2
*/

struct Dirty {
    short r;
    short c;
    int date;
};

char canvas[5005][5005];
Dirty buildings[200000];
queue<Dirty> bfs_q;
short DR[] = {1, -1, 0, 0};
short DC[] = {0, 0, 1, -1};
string ans = "";
void canvasVisualize(int h, int w) {
    cout << endl;
    for(int i = 1; i <= h; i++) {
        for(int j = 1; j <= h; j++) {
            cout << canvas[i][j];
        }
        cout << endl;
    }
    cout << endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int flag_today = 0;
    int h, w;
    int n; // ¤Ñ¼Æ
    cin >> h >> w;
    for(int i = 1 ; i <= h; i++) {
        for(int j = 1; j <= w; j++) {
            char c;
            cin >> c;
            canvas[i][j] = c;
        }
    }
    cin >> n;
    for(int i = 0; i < n; i++) {
        short r, c; // row, column
        cin >> r >> c;
        buildings[i] = {r, c, i};
    }
    int today = 0;
    int total = 0;

    canvas[buildings[today].r][buildings[today].c] = 'X';
    bfs_q.emplace(buildings[today]);
    total++;
    cout << total << "\n";
    int out_countdown = n - 1;
    while(!bfs_q.empty()) {
        Dirty dirty = bfs_q.front();
        bfs_q.pop();
        if(dirty.date > today) {
            today++;
            // to build new building
            Dirty new_building = buildings[today];
            if(canvas[new_building.r][new_building.c] == '.'){
                canvas[new_building.r][new_building.c] = 'X';
                bfs_q.emplace(buildings[today]);
                total++;
            }
            //canvasVisualize(h, w);
            //cout << total << "\n";
            ans += to_string(total) + "\n";
            out_countdown--;
            if(out_countdown <= 0) break;
        }
        if(dirty.r == 25565 || dirty.c == 25565) {
            if (flag_today < (today + 1)) {
                Dirty date_flag = {25565, 25565, today + 1};
                bfs_q.emplace(date_flag);
                flag_today = today + 1;
            }
            continue;
        }

        int row = dirty.r;
        int col = dirty.c;
        bool flag=1;


        for(int i = 0; i < 4; i++) {
            int new_row = row + DR[i], new_col = col + DC[i];
            if(!(canvas[new_row][new_col] == '.' && new_row > 0 && new_row <= h && new_col > 0 && new_col <= w)) continue;

            Dirty new_dirty = {new_row, new_col, today + 1};
            canvas[new_row][new_col] = 'X';
            bfs_q.emplace(new_dirty);
            total++;
            flag=0;
        }

        if (flag) {
            if (flag_today < (today + 1)) {
                Dirty date_flag = {25565, 25565, today + 1};
                bfs_q.emplace(date_flag);
                flag_today = today + 1;
            }

        }
    }
    cout << ans;
}
