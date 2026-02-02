#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

char grid[5][5];
int ans = 0;
bool isConnected(vector<int> selected) {
    int dx[4] = { -1,1,0,0 };
    int dy[4] = { 0,0,-1,1 };
    int cnt = 1;
    bool isVisited[25] = { false, };
    bool sel[25] = { false, };

    for (int i = 0; i < 7; i++) {
        sel[selected[i]] = true;
    }

    queue<int> bfsQ;
    bfsQ.push(selected[0]);
    isVisited[selected[0]] = true;

    while (!bfsQ.empty()) {
        int cur = bfsQ.front();

        int r = cur / 5;
        int c = cur % 5;

        bfsQ.pop();

        for (int i = 0; i < 4; i++) {
            int nr = r + dx[i];
            int nc = c + dy[i];
            if (nr < 0 || nr >= 5 || nc < 0 || nc >= 5)
                continue;
            int nxt = nr * 5 + nc;


            if (!isVisited[nxt] && sel[nxt]) {
                isVisited[nxt] = true;
                bfsQ.push(nxt);
                cnt++;
            }
        }
    }

    return cnt == 7;
}
void dfs(int start, int count, int sCount, vector<int> selected) {
    if (count == 7) {
        if (sCount >= 4 && isConnected(selected)) {
            ans += 1;
        }
        return;
    }
    if (sCount + (7 - count) < 4)
        return;

    for (int i = start; i < 25; i++) {
        int r = i / 5;
        int c = i % 5;

        selected.push_back(i);

        if (grid[r][c] == 'S') {
            dfs(i + 1, count + 1, sCount + 1, selected);
        }
        else {
            dfs(i + 1, count + 1, sCount , selected);
        }

        selected.pop_back();
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 5x5 격자 입력 받기
    for (int i = 0; i < 5; i++) {
        string line;
        cin >> line;
        for (int j = 0; j < 5; j++) {
            grid[i][j] = line[j];
        }
    }

    vector<int> selected;
    dfs(0, 0, 0, selected);
    cout << ans << "\n";

    return 0;
}