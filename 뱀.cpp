#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <deque>
using namespace std;

int n, k, l, x;

int dy[] = { 0,1,0,-1 }; // 오 아 왼 위
int dx[] = { 1,0,-1,0 };

int board[105][105];
char c;

deque<pair<int, int>> D;
vector<pair<int, char>> save;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    memset(board, 0, sizeof(board));

    cin >> n >> k;

    // 사과 위치
    for (int i = 0; i < k; i++) {
        int y, x;
        cin >> y >> x;
        board[y - 1][x - 1] = 1;
    }

    cin >> l;

    int dir = 0; // 처음 방향: 오른쪽
    D.push_back({ 0,0 });
    board[0][0] = 2;

    for (int i = 0; i < l; i++) {
        cin >> x >> c;
        save.push_back({ x,c });
    }

    int totalTime = 0;
    int turnCnt = 0;

    while (true) {
        auto [curY, curX] = D.front();
        int ny = curY + dy[dir];
        int nx = curX + dx[dir];

        // 벽 충돌
        if (ny < 0 || ny >= n || nx < 0 || nx >= n) {
            cout << totalTime + 1;
            return 0;
        }

        // 자기 몸 충돌
        if (board[ny][nx] == 2) {
            cout << totalTime + 1;
            return 0;
        }

        // 사과가 있는 경우
        if (board[ny][nx] == 1) {
            D.push_front({ ny,nx });
            board[ny][nx] = 2;
        }
        // 사과가 없는 경우
        else {
            D.push_front({ ny,nx });
            board[ny][nx] = 2;

            auto tail = D.back();
            D.pop_back();
            board[tail.first][tail.second] = 0;
        }

        totalTime++;

        // 방향 전환
        // 방향 전환 횟수가 vector에 저장된 것보다 적게 진행되었는지 확인
        // 자칫하면 vector 초과함
        // 몇번 이동했는지 확인 후 방향 전환
        if (turnCnt < save.size() && totalTime == save[turnCnt].first) {
            if (save[turnCnt].second == 'L')
                dir = (dir + 3) % 4;
            else
                dir = (dir + 1) % 4;
            turnCnt++;
        }
    }

    return 0;
}
