#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int n, m, k;
int A[15][15];
int board[15][15];

int dy[8] = { 0,1,0,-1,1,1,-1,-1 };
int dx[8] = { 1,0,-1,0,1,-1,1,-1 };

vector<tuple<int, int, int>> tree; // x, y, age

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;

    // 초기 양분 5
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            board[i][j] = 5;

    // 겨울에 추가되는 양분
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> A[i][j];

    // 초기 나무
    for (int i = 0; i < m; i++) {
        int x, y, age;
        cin >> x >> y >> age;
        tree.push_back({ x - 1, y - 1, age });
    }

    while (k--) {

        // 나이순 정렬
        sort(tree.begin(), tree.end(),
            [](const tuple<int, int, int>& a,
                const tuple<int, int, int>& b) {
                    return get<2>(a) < get<2>(b);
            });

        vector<tuple<int, int, int>> alive;
        vector<tuple<int, int, int>> dead;

        // 봄
        for (int t = 0; t < tree.size(); t++) {
            auto [x, y, age] = tree[t];

            if (board[x][y] >= age) {
                board[x][y] -= age;
                alive.push_back({ x, y, age + 1 });
            }
            else {
                dead.push_back({ x, y, age });
            }
        }

        // 여름
        for (int t = 0; t < dead.size(); t++) {
            auto [x, y, age] = dead[t];
            board[x][y] += age / 2;
        }

        tree = alive;

        // 가을
        for (int t = 0; t < tree.size(); t++) {
            auto [x, y, age] = tree[t];

            if (age % 5 != 0) continue;

            for (int d = 0; d < 8; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];

                if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                tree.push_back({ nx, ny, 1 });
            }
        }

        // 겨울
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                board[i][j] += A[i][j];
    }

    cout << tree.size();
    return 0;
}
