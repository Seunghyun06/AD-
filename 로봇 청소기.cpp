#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

int board[55][55];

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };


int n, m;
int curY, curX;
int dir = 0;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	cin >> curY >> curX >> dir;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}

	int cnt = 0;

	while (true) {
		if (board[curY][curX] == 0) {
			board[curY][curX] = 2;
			cnt++;
		}
		bool isempty = false;
		for (int dir = 0; dir < 4; dir++) {
			int ny = curY + dy[dir];
			int nx = curX + dx[dir];
			if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
			if (board[ny][nx] == 0) isempty = true;
		}
		if (!isempty) {
			int temp = (dir + 2) % 4;
			curY += dy[temp];
			curX += dx[temp];
			if (curY < 0 || curY >= n || curX < 0 || curX >= m) break;
			if (board[curY][curX] == 1) break;
		}
		else {
			dir = (dir + 3) % 4;
			if (board[curY + dy[dir]][curX + dx[dir]] == 0) {
				curY += dy[dir];
				curX += dx[dir];
			}
		}
	}

	cout << cnt;

	return 0;
}
